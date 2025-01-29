#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Target not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) return -1; // Base case: target not found

    int mid = left + (right - left) / 2; // Prevents overflow

    if (arr[mid] == target)
        return mid; // Target found
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target); // Search right half
    else
        return binarySearchRecursive(arr, left, mid - 1, target); // Search left half
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Iterative Binary Search
    int iterativeResult = binarySearchIterative(arr, n, target);
    if (iterativeResult != -1)
        cout << "Iterative: Element found at index " << iterativeResult << endl;
    else
        cout << "Iterative: Element not found" << endl;

    // Recursive Binary Search
    int recursiveResult = binarySearchRecursive(arr, 0, n - 1, target);
    if (recursiveResult != -1)
        cout << "Recursive: Element found at index " << recursiveResult << endl;
    else
        cout << "Recursive: Element not found" << endl;

    return 0;
}
