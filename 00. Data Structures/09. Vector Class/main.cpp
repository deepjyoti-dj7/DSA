#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int current;

public:
    // Constructor
    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    // Add element at the end
    void push_back(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    // Remove last element
    void pop_back() {
        if (current > 0) {
            current--;
        }
    }

    // Overload [] operator
    T operator[](int index) const {
        if (index < current) {
            return arr[index];
        }
        return T();
    }

    // Return current size
    int size() const {
        return current;
    }

    // Return total capacity
    int getCapacity() const {
        return capacity;
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }
};

int main() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Elements in vector: ";
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    
    cout << endl;

    v.pop_back();

    cout << "After pop_back(): ";
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    
    cout << endl;

    cout << "Current Size: " << v.size() << endl;
    cout << "Capacity: " << v.getCapacity() << endl;

    // Test with another type
    Vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    cout << "String Vector: ";
    for (int i = 0; i < vs.size(); i++) 
        cout << vs[i] << " ";
    cout << endl;

    return 0;
}
