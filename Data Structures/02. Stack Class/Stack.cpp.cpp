#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    size_t capacity;
    size_t size;
    T* data;

    void resize() {
        size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(size_t initialCapacity = 1) : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void push(const T& value) {
        if (isFull()) {
            resize();
        }
        data[size++] = value;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
        }
        return data[--size];
    }

     T peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
        }
        return data[size - 1];
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    std::cout << "Current stack size: " << stack.getSize() << std::endl;

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;

    std::cout << "Current stack size: " << stack.getSize() << std::endl;

    while (!stack.isEmpty()) {
        std::cout << "Popped element: " << stack.pop() << std::endl;
    }

    std::cout << "Trying to pop from an empty stack..." << std::endl;
    stack.pop();

    return 0;
}