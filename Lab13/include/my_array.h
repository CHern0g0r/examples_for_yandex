#ifndef LAB_13_MY_ARRAY_H
#define LAB_13_MY_ARRAY_H

#include <cstddef>
#include <iostream>

template<typename T, std::size_t N>
class my_array {
public:
    T& at(std::size_t index);
    T const & at(std::size_t index) const;
    T& operator[](std::size_t index);
    T const & operator[](std::size_t index) const;

    bool empty() const {
        return N;
    };

    size_t size() const {
        return N;
    };

    void fill(T val) {
        for (size_t i = 0; i<N; i++) {
            data[i] = val;
        }
    };
private:
    T data[N];
};

template<typename T, std::size_t N>
T& my_array<T, N>::at(std::size_t index) {
    // if (index >= N || index < 0) {
        
    // }
    // assert(index >= N || index < 0);
    return data[index];
}

template<typename T, std::size_t N>
T const & my_array<T, N>::at(std::size_t index) const {
    // if (index >= N || index < 0) {
    //     return -1;
    // }
    // assert(index >= N || index < 0);
    return data[index];
}

template<typename T, std::size_t N>
T& my_array<T, N>::operator[] (std::size_t index) {
    return data[index];
}

template<typename T, std::size_t N>
T const & my_array<T, N>::operator[] (std::size_t index) const {
    return data[index];
}

//----------------------------------------------------------------


template<std::size_t N>
class my_array<bool, N> {
public:

    class const_reference {
        friend class my_array;
    public:
        // const_reference(char *p, std::size_t offset);
        const_reference(const char *p, std::size_t offset);
        operator bool() const;
        bool shit();

    private:
        const char *point;
        std::size_t offset;
    };

    class reference : public const_reference{
        friend class my_array;
    public:
        reference(char *p, std::size_t offset);
        reference& operator=(bool x);
        reference& operator=(reference& x);
        // void flip();
    private:
        char* point;
    };

    reference at(std::size_t index);
    const_reference at(std::size_t index) const;
    reference operator[](std::size_t index);
    const_reference operator[](std::size_t index) const;

    bool empty() const {
        return N;
    };

    size_t size() const {
        return N;
    };

    void fill(bool val) {
        for (size_t i = 0; i<N; i++) {
            this -> at(i) = val;
        }
    };

private:
    char data[N/8 + 1] = {0};
};

//-------------------------------------------

template<std::size_t N>
my_array<bool, N>::reference::reference(char* p, std::size_t off) : const_reference(nullptr, off){
    point = p;
    this -> offset = off;
};

template<std::size_t N>
typename my_array<bool, N>::reference& my_array<bool, N>::reference::operator=(bool x) {
    if (x) *(this -> point) = *(this -> point) | (1 << this -> offset);
    else *(this -> point) = *(this -> point) & (~(1 << this -> offset));

    return *this;
}

template<std::size_t N>
typename my_array<bool, N>::reference& my_array<bool, N>::reference::operator=(my_array<bool, N>::reference& ref) {
    this -> point = ref.point;
    this -> offset = ref.offset;
}

//-------------------------------------------

// template<std::size_t N>
// my_array<bool, N>::const_reference::const_reference (char* p, std::size_t off) {
//     offset = off;
//     point = p;
// }

template<std::size_t N>
my_array<bool, N>::const_reference::const_reference (const char* p, std::size_t off) {
    offset = off;
    point = p;
}

template<std::size_t N>
my_array<bool, N>::const_reference::operator bool () const {
    // #pragma GCC diagnostic ignored "-Wuninitialized"
    bool res = *(this -> point) & (1 << this -> offset);
    // #pragma GCC diagnostic pop
    return res;
}

//-------------------------------------------

template<std::size_t N>
typename my_array<bool, N>::const_reference my_array<bool, N>::at (std::size_t index) const{
    return my_array<bool, N>::const_reference(&data[index/8], 7-index%8);
}

template<std::size_t N>
typename my_array<bool, N>::reference my_array<bool, N>::at (std::size_t index) {
    return my_array<bool, N>::reference(&data[index/8], 7-index%8);
}

template<std::size_t N>
typename my_array<bool, N>::const_reference my_array<bool, N>::operator[] (std::size_t index) const {
    return my_array<bool, N>::const_reference(&data[index/8], 7-index%8);
}

template<std::size_t N>
typename my_array<bool, N>::reference my_array<bool, N>::operator[] (std::size_t index) {
    return my_array<bool, N>::reference(&data[index/8], 7-index%8);
}

#endif