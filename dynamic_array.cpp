#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;        // Pointer to hold the array
    int capacity;     // Current capacity of the array
    int size;         // Current number of elements in the array

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;    // Free old memory
        data = new_data;  // Point to the new array
        capacity = new_capacity;
    }

public:
    DynamicArray() : data(nullptr), capacity(0), size(0) {
        resize(1);  // Initial capacity of 1
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize(2 * capacity);  // Double the capacity when the array is full
        }
        data[size++] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = value;
    }

    int get_size() const {
        return size;
    }

    int get_capacity() const {
        return capacity;
    }
};

int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    for (int i = 0; i < arr.get_size(); i++) {
        std::cout << arr.get(i) << " ";
    }

    return 0;
}
