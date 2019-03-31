#ifndef LAB_12_MY_VECTOR_H
#define LAB_12_MY_VECTOR_H
#include <iostream>
#include <cstddef>
#include <algorithm>


template <class T>
class my_vector{
public:
    // my_vector();
    my_vector(size_t n = 0);
    my_vector(my_vector& other);
    my_vector& operator=(my_vector other);
    ~my_vector();

    size_t size() const;
    size_t capacity();
    bool empty();

    void resize(size_t n);
    void reserve(size_t n);

    T const operator[](size_t index) const;
    T& operator[](size_t index);

    void push_back(const T& t);
    void pop_back();
    void clear();

private:
    size_t capacity_;
    size_t size_;
    T* array_;

    T* copy_data(size_t capacity, size_t size, T* data = nullptr);
};

template <class T>
my_vector<T>::my_vector (size_t n) {
    size_t k = 1;
    while(k<n) k *= 2;
    array_ = copy_data(k, n);
    for (size_t i = 0; i<size_; i++) {
        new (array_ + i) T();
    }
}

template <class T>
my_vector<T>::my_vector (my_vector& old) {
    array_ = copy_data(old.capacity_, old.size_, old.array_);
}

template <class T>
my_vector<T>::~my_vector (){
    for (size_t i = size_; i > 0; i--) {
        array_[i-1].~T();
    }
    delete[] reinterpret_cast<char*> (array_);
}

template <class T>
my_vector<T>& my_vector<T>::operator= (my_vector<T> old) {
    std::swap(&old, this);
    return *this;
}

template <class T>
void my_vector<T>::reserve (size_t n) {
    if (n > capacity_) {
        T* new_array_ = copy_data(n, size_, array_);

        for (size_t i = size_; i > 0; i--) {
            array_[i-1].~T();
        }
        delete[] reinterpret_cast<char*> (array_);
        array_ = new_array_;
    }
}

template  <class T>
void my_vector<T>::resize (size_t n) {
    if (n > capacity_) {
        size_t k = capacity_;
        while (k < n) k*=2;
        reserve(k);
    }
    if (n >= size_) {
        for (size_t i = size_; i<n; i++) {
            new (&array_[i]) T();
            size_ = n;
        }
    } else {
        for (size_t i = size_; i > n; i--) {
            array_[i-1].~T();
            size_ = n;
        }
    }
}

template <class T>
void my_vector<T>::push_back(const T& t) {
    // std::cout << t;
    if (size_ >= capacity_ - 1) {
        reserve(capacity_ * 2);
    }
    new (&array_[size_]) T(t);
    size_++;
}

template <class T>
void my_vector<T>::pop_back() {
    array_[--size_].~T();
}

template <class T>
void my_vector<T>::clear() {
    T* new_array_ = copy_data(capacity_, 0);
    for (size_t i = size_; i > 0; i--) {
        array_[i-1].~T();
    }
    delete[] reinterpret_cast<char*> (array_);
    array_ = new_array_;
}

template <class T>
T const my_vector<T>::operator[] (size_t index) const {
    return array_[index];
}

template <class T>
T& my_vector<T>::operator[] (size_t index) {
    return array_[index];
}

template <class T>
size_t my_vector<T>::size() const {
    return size_;
}

template <class T>
size_t my_vector<T>::capacity() {
    return capacity_;
}

template  <class T>
bool my_vector<T>::empty() {
    return size_ == 0;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const my_vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    return os;
}

//--------------------------------------------------------------------

template <class T>
T* my_vector<T>::copy_data(size_t capacity, size_t size, T* old) {
    
    capacity_ = capacity;
    size_ = size;
    T* new_array_ = reinterpret_cast <T*> (new char[sizeof(T) * capacity_]);

    if (old != nullptr) {
        for (size_t i = 0; i<size_; i++) {
            new (new_array_ + i) T(old[i]);
        }
    }

    return new_array_;
}

#endif
