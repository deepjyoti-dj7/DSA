#include <iostream>
#include <string>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front() {
        if (empty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node<T>* temp = head;
        if (head->next == nullptr) { // Only one node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (empty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node<T>* temp = tail;
        if (tail->prev == nullptr) { // Only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void remove(T value) {
        if (empty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        if (head->data == value) {
            pop_front();
            return;
        }

        if (tail->data == value) {
            pop_back();
            return;
        }

        Node<T>* current = head;
        while (current && current->data != value) {
            current = current->next;
        }

        if (current) {
            current->prev->next = current->next;
            if (current->next) {
                current->next->prev = current->prev;
            }
            delete current;
        } else {
            std::cout << "Value not found in the list!" << std::endl;
        }
    }

    bool search(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print_forward() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void print_backward() {
        Node<T>* current = tail;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "NULL" << std::endl;
    }

    size_t size() {
        size_t count = 0;
        Node<T>* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.push_back(40);
    list.push_back(50);

    std::cout << "Initial List (Forward): ";
    list.print_forward();
    std::cout << "Initial List (Backward): ";
    list.print_backward();

    std::cout << "List size: " << list.size() << std::endl;

    list.pop_back();
    std::cout << "After pop_back (Forward): ";
    list.print_forward();
    std::cout << "After pop_back (Backward): ";
    list.print_backward();

    list.pop_front();
    std::cout << "After pop_front (Forward): ";
    list.print_forward();
    std::cout << "After pop_front (Backward): ";
    list.print_backward();

    std::cout << "Removing 40..." << std::endl;
    list.remove(40);
    list.print_forward();
    list.print_backward();

    std::cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;
    list.print_forward();

    std::cout << "List size: " << list.size() << std::endl;

    list.pop_front();
    std::cout << "After pop_front (Forward): ";
    list.print_forward();
    std::cout << "After pop_front (Backward): ";
    list.print_backward();

    std::cout << "Removing 20..." << std::endl;
    list.remove(20);
    list.print_forward();
    list.print_backward();

    std::cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;

    DoublyLinkedList<std::string> strList;
    strList.push_front("Hello");
    strList.push_back("World");
    strList.push_front("Hi");

    std::cout << "String List (Forward): ";
    strList.print_forward();
    std::cout << "String List (Backward): ";
    strList.print_backward();

    return 0;
}
