// column-submit.h

#ifndef COLUMN_SUBMIT_H_
#define COLUMN_SUBMIT_H_

#include <string>
#include <iostream>

/// TODO: Add the definitions of inline global functions below

template <>
inline std::string Column<int>::as_string_at(int index) const {
    return std::to_string(data_[index]);

}

template <>
inline std::string Column<bool>::as_string_at(int index) const {
    return (data_[index] == true)? "true" : "false";

}

template <>
inline std::string Column<std::string>::as_string_at(int index) const {
    return data_[index];
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Column<T>& column) {
    return column << os;
}

/// TODO: Add the missing function definitions of the Column template below

template <typename T>
void Column<T>::reserve_capacity(int new_capacity) {
    if (new_capacity > capacity_){
        T* newarray = new T[new_capacity];
        for (int i = 0; i < size_; ++i){
            newarray[i] = data_[i];
        }
        delete [] data_;
        data_ = newarray;
        capacity_ = new_capacity;
    }
    return;
}

template <typename T>
void Column<T>::expand_size(int new_size) {
    if (new_size <= size_){
        return;
    }
    if (new_size > capacity_){
        this->reserve_capacity(new_size);
    }
    for (int i = 0; i < (new_size - size_); ++i){
        data_[size_ + i] = default_value_;
    }
    size_ = new_size;
    return;
}

template <typename T>
void Column<T>::append(const Column<T>& other) {
    int remaining_capacity = capacity_ - size_;

    if (other.size_ > remaining_capacity){
        int new_capacity = size_ + other.size_;

        this->reserve_capacity(new_capacity);
    }
    for (int i = 0; i < other.size_; ++i){
        data_[size_ + i] = other.data_[i];
    }
    size_ += other.size_;
    return;
}

template <typename T>
const Column<T>& Column<T>::operator=(const Column<T>& other) {
    if (this != &other){
        if (data_ != nullptr){
            delete [] this->data_;
        }
        this->default_value_ = other.default_value_;
        this->name_ = other.name_;
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
    
        data_ = new T[capacity_];
        for (int i = 0; i < size_; ++i){
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template <typename T>
Column<T> Column<T>::operator+(const Column<T>& other) const {
    std::string new_name = "NULL";
    Column<T> temp(this->default_value_, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp.data_[i] = this->data_[i] + other.data_[i];
    }
    return temp;
}

template <typename T>
const Column<T>& Column<T>::operator+=(const Column<T>& other) {
    for (int i = 0; i < size_; ++i){
        this->data_[i] = this->data_[i] + other.data_[i];
    }
    return *this;
}

template <typename T>
Column<bool> Column<T>::operator==(const Column<T>& other) const {
    std::string new_name = "NULL";
    Column<bool> temp(false, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp[i] = this->data_[i] == other.data_[i];
    }
    return temp;
}

template <typename T>
Column<bool> Column<T>::operator<(const Column<T>& other) const {
    std::string new_name = "NULL";
    Column<bool> temp(false, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp[i] = this->data_[i] < other.data_[i];
    }
    return temp;
}

template <typename T>
Column<bool> Column<T>::operator==(const T& other) const {
    std::string new_name = "NULL";
    Column<bool> temp(false, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp[i] = this->data_[i] == other;
    }
    return temp;
}

template <typename T>
Column<bool> Column<T>::operator<(const T& other) const {
    std::string new_name = "NULL";
    Column<bool> temp(false, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp[i] = this->data_[i] < other;
    }
    return temp;
}

template <typename T>
Column<bool> Column<T>::operator!() const {   
    std::string new_name = "NULL";
    Column<bool> temp(false, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp[i] = !this->data_[i];
    }
    return temp;
}

template <typename T>
Column<bool> Column<T>::operator&&(const Column<T>& other) const {
    std::string new_name = "NULL";
    Column<bool> temp(false, this->size_, this->size_, new_name);
    for (int i = 0; i < size_; ++i){
        temp.data_[i] = this->data_[i] && other.data_[i];
    }
    return temp;
}


template <typename T>
T Column<T>::operator[](int index) const {
    int corrected_index = index;
    if (index < 0) {
        corrected_index = index + size_;
    }
    return data_[corrected_index];
}

template <typename T>
T& Column<T>::operator[](int index) {
    int corrected_index = index;
    if (index < 0) {
        corrected_index = index + size_;
    }
    return data_[corrected_index];
}

template <typename T>
Column<T>::Column(const Column<T>& other, const Column<bool>& selector) {
    other.get_capacity();
    selector.get_capacity();
}

template <typename T>
Column<T> Column<T>::operator[](const Column<bool>& selector) const {
    std::string new_name = "NULL";
    Column<T> temp(default_value_, 0, 0, new_name);
    for (int i = 0, y = 0; i < selector.get_size(); ++i){
        if (selector[i]){
            temp.expand_size(++y);
            temp[-1] = this->data_[i];
        }
    }
    return temp;
}

#endif  // COLUMN_SUBMIT_H_
