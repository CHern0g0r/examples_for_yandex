#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>

#include "my_vector.h"

class Product {
public:
    Product();
    Product(const char* name, int quantity, double price);
    Product(const Product& pr);
    ~Product();
    char* get_name() const;
    int get_quantity() const;
    double get_price() const;

    Product& operator= (Product p);
    bool operator==(const Product& p) const;
    friend std::ostream& operator<< (std::ostream& os, Product& pr);

private:
    char *name_;
    int quantity_;
    double price_;
};

Product::Product() {
    name_ = new char[255];
    quantity_ = 0;
    price_ = 0;
}

Product::~Product() {
    delete [] name_;
}

char* Product::get_name() const {
    return name_;
}

int Product::get_quantity() const {
    return quantity_;
}

double Product::get_price() const {
    return price_;
}

Product::Product(const char *name, int quantity, double price) {
    name_ = new char[255];
    strcpy(name_, name);
    quantity_ = quantity;
    price_ = price;
}

Product::Product(const Product &pr) {
    name_ = new char[255];
    strcpy(name_, pr.get_name());
    quantity_ = pr.get_quantity();
    price_ = pr.get_price();
}

Product& Product::operator=(Product pr) {
    // std::swap(&pr, this);
    std::swap(name_, pr.name_);
    std::swap(quantity_, pr.quantity_);
    std::swap(price_, pr.price_);
    return *this;
}

bool Product::operator==(const Product &p) const {
    return (!strcmp(name_, p.get_name())) && (quantity_ == p.quantity_) && (price_ == p.price_);
}

std::ostream& operator<< (std::ostream& os, Product& pr) {
    os << pr.name_ << " " << pr.quantity_ << " " << pr.price_ << "\n";
    return os;
}

std::ostream& operator<< (std::ostream& os, const Product& pr) {
    os << pr.get_name() << " " << pr.get_quantity() << " " << pr.get_price() << "\n";
    return os;
}

void print(const my_vector<Product>& v) {
    std::cout << v << std::endl;
}

template <class P>
void test_my_vector(P& a, P& b) {

    my_vector<P> x;
    x.push_back(a);

    assert(!x.empty());

    my_vector<P> y(x);
    x.reserve(10);
    y.push_back(b);

    assert(x.size() == 1);
    assert(y.size() == 2);

    y.pop_back();
    assert(y.size() == 1);

    y.push_back(a);
    y.push_back(b);
    assert(y.size() == 3);

    my_vector<P> asdf(y);

    assert(asdf.size() == 3);

    assert(x[0] == a);
    assert(y[0] == a);
    assert(y[1] == a);
    y[1] = b;
    assert(y[1] == b);
    assert(y[2] == b);
    assert(asdf[2] == b);
    asdf.resize(10);
    assert(asdf.size() == 10);
    asdf.resize(1);
    assert(asdf.size() == 1);

}

int main() {
    int a = 5, b = 10;
    test_my_vector<int>(a, b);
    Product c("asdf", 4, 12.0);
    Product d("qwe", -1, 7.5);
    test_my_vector<Product>(c, d);

    return 0;
}
