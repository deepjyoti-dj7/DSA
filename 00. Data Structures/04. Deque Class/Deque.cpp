#include <iostream>

template <typename T>
class Deque {
private:
    T* data;
    size_t capacity;
    size_t size;
    size_t front;
    size_t rear;

    void resize() {
        size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];

        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = newData;
        front = 0;
        rear = size;
        capacity = newCapacity;
    }

public:
    Deque(size_t initialCapacity = 1) : capacity(initialCapacity), size(0), front(0), rear(capacity - 1) {
        data = new T[capacity];
    }

    ~Deque() {
        delete[] data;
    }

    bool is_empty() {
        return size == 0;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        ++size;
    }

    void push_front(const T& value) {
        if (size == capacity) {
            resize();
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        ++size;
    }

    T pop_back() {
        if (is_empty()) {
            std::cout << "Deque is empty!" << std::endl;
            return T();
        }
        T value = data[rear];
        rear = (rear - 1 + capacity) % capacity;
        --size;
        return value;
    }

    T pop_front() {
        if (is_empty()) {
            std::cout << "Deque is empty!" << std::endl;
            return T();
        }
        T value = data[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    T get_back() {
        if (is_empty()) {
            std::cout << "Deque is empty!" << std::endl;
            return T();
        }
        return data[rear];
    }

    T get_front() {
        if (is_empty()) {
            std::cout << "Deque is empty!" << std::endl;
            return T();
        }
        return data[front];
    }

    size_t get_size() {
        return size;
    }
};

int main() {
    Deque<int> deque;

    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);
    deque.push_front(2);

    std::cout << "Front element: " << deque.get_front() << std::endl; 
    std::cout << "Rear element: " << deque.get_back() << std::endl;  

    std::cout << "Popped from front: " << deque.pop_front() << std::endl;
    std::cout << "Current size: " << deque.get_size() << std::endl; 

    deque.push_back(30);
    deque.push_back(40);
    deque.push_back(50); 

    std::cout << "Current size: " << deque.get_size() << std::endl; 

    int size = deque.get_size();
    while (size--) { 
        deque.pop_front();
    }
    deque.pop_front(); // This should print an error as the deque is empty

    return 0;
}