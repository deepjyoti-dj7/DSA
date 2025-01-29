#include <iostream>
#include <string>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
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
        Node<T>* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T value) {
        Node<T>* newNode = new Node(value);
        if (empty()) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void pop_front() {
        if (empty()) {
            std::cout << "List is empty !" << std::endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (empty()) {
            std::cout << "List is empty !" << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next->next) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    void remove(T value) {
        if (empty()) {
            std::cout << "List is empty !" << std::endl;
            return;
        }

        if (head->data == value) {
            pop_front();
            return;
        }

        Node<T>* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
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

    void print() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
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
    LinkedList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.push_back(40);
    list.push_back(50);

    std::cout << "Initial List: ";
    list.print();

    std::cout << "List size: " << list.size() << std::endl;

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();

    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();

    std::cout << "Removing 40..." << std::endl;
    list.remove(40);
    list.print();

    std::cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;
    list.print();

    std::cout << "List size: " << list.size() << std::endl;

    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();

    std::cout << "Removing 40..." << std::endl;
    list.remove(40);
    list.print();

    std::cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;

    LinkedList<std::string> strList;
    strList.push_front("Hello");
    strList.push_back("World");
    strList.push_front("Hi");

    std::cout << "String List: ";
    strList.print();

    return 0;
}