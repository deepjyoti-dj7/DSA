#include <iostream>
#include <cstring> // For strlen, strcpy, etc.

class String {
private:
    char* data;     // Pointer to hold the string data
    size_t length;  // Length of the string

public:
    // Constructors
    String() : data(nullptr), length(0) {} // Default constructor

    String(const char* str) { // Constructor from C-string
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            length = 0;
            data = nullptr;
        }
    }

    String(const String& other) : length(other.length) { // Copy constructor
        if (other.data) {
            data = new char[length + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    String(String&& other) noexcept : data(other.data), length(other.length) { // Move constructor
        other.data = nullptr;
        other.length = 0;
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Member functions
    size_t size() const { // Get the length of the string
        return length;
    }

    const char* c_str() const { // Get C-string representation
        return data;
    }

    void append(const String& other) { // Append another string
        if (other.length == 0) return;

        char* newData = new char[length + other.length + 1];
        if (data) {
            strcpy(newData, data);
        }
        strcat(newData, other.data);

        delete[] data;
        data = newData;
        length += other.length;
    }

    // Operator overloads
    String& operator=(const String& other) { // Copy assignment
        if (this == &other) return *this;

        delete[] data;

        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
        return *this;
    }

    String& operator=(String&& other) noexcept { // Move assignment
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;
        return *this;
    }

    String operator+(const String& other) const { // Concatenate strings
        String result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];

        if (data) strcpy(result.data, data);
        if (other.data) strcat(result.data, other.data);

        return result;
    }

    char& operator[](size_t index) { // Access character by index
        return data[index];
    }

    const char& operator[](size_t index) const { // Access character by index (const)
        return data[index];
    }

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        if (str.data) os << str.data;
        return os;
    }
};

int main() {
    String s1("Hello");
    String s2(" World");

    String s3 = s1 + s2; // Concatenate
    std::cout << "Concatenated: " << s3 << std::endl;

    s1.append(s2); // Append
    std::cout << "Appended: " << s1 << std::endl;

    String s4 = s3; // Copy constructor
    std::cout << "Copied: " << s4 << std::endl;

    String s5 = std::move(s4); // Move constructor
    std::cout << "Moved: " << s5 << std::endl;

    s1 = s5; // Copy assignment
    std::cout << "Copy Assigned: " << s1 << std::endl;

    s2 = std::move(s5); // Move assignment
    std::cout << "Move Assigned: " << s2 << std::endl;

    std::cout << "Character at index 1: " << s2[1] << std::endl;

    return 0;
}
