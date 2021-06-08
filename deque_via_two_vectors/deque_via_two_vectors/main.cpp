//
//  main.cpp
//  deque_via_two_vectors
//
//  Created by Andre on 13/01/21.
//

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>

template <typename T>
class Deque {
private:
    std::vector<T> front_;
    std::vector<T> back_;
public:
    Deque(){};
    const bool Empty() const {
        if (front_.size() == 0 && back_.size() == 0) {
            return true;
        }
        return false;
    }
    const size_t Size() const {
        return front_.size() + back_.size();
    }
    void PushBack(T elem) {    // Под новую реализацию сделано!
        back_.push_back(elem);
    }
    void PushFront(T elem) {   // Под новую реализацию сделано!
        front_.push_back(elem);
    }
    T& Back() {               // Под новую реализацию сделано!
        if (!back_.size()) {  // Элементов в зад добавлено не было
            return front_.front();
        }
        return back_.back();
    }
    const T& Back() const {    // Под новую реализацию сделано!
        if (!back_.size()) {  // Элементов в зад добавлено не было
            return front_.front();
        }
        return back_.back();
    }
    T& Front() {               // Под новую реализацию сделано!
        if (!front_.size()) {  // Элементов в перед добавлено не было
            return back_.front();
        }
        return front_.back();
    }
    const T& Front() const {    // Под новую реализацию сделано!
        if (!front_.size()) {  // Элементов в перед добавлено не было
            return back_.front();
        }
        return front_.back();
    }
    T& operator[] (size_t index) {
        if (front_.empty()) {
            return back_[index];
        }
        if (back_.empty()) {
            return *(std::next(front_.rbegin(), index));
        }
        if (index >= front_.size()) {
            return back_[index - front_.size()];
        }
        return *(std::next(front_.rbegin(), index));
    }
    const T& operator[](size_t index) const {
        if (front_.empty()) {
            return back_[index];
        }
        if (back_.empty()) {
            return *(std::next(front_.rbegin(), index));
        }
        if (index >= front_.size()) {
            return back_[index - front_.size()];
        }
        return *(std::next(front_.rbegin(), index));
    }
    T& At(size_t index) {
        if (index >= (front_.size() + back_.size())) {
            throw std::out_of_range("out of range");
        }
        if (front_.empty()) {
            return back_[index];
        }
        if (back_.empty()) {
            return *(std::next(front_.rbegin(), index));
        }
        if (index >= front_.size()) {
            return back_[index - front_.size()];
        }
        return *(std::next(front_.rbegin(), index));
    }
    const T& At(size_t index) const {
        if (index >= (front_.size() + back_.size())) {
            throw std::out_of_range("out of range");
        }
        if (front_.empty()) {
            return back_[index];
        }
        if (back_.empty()) {
            return *(std::next(front_.rbegin(), index));
        }
        if (index >= front_.size()) {
            return back_[index - front_.size()];
        }
        return *(std::next(front_.rbegin(), index));
    }
};

int main() {
    Deque<int> d;
    for (int i = 6; i <= 11; ++i) {
        d.PushBack(i);
    }
    for (int i = 0; i <= 5; ++i) {
        d.PushFront(i);
    }
    std::cout << d.Size() << std::endl;
    std::cout << d[0] << std::endl;
    try {
        std::cout << d.At(0) << std::endl;
    } catch (const std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "Back: " << d.Back() << std::endl;
    std::cout << "Front: " << d.Front() << std::endl;
    
    
    return 0;
}
