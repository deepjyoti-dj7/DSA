import java.util.*;

public class BinarySearch {
    // Iterative Binary Search
    public static int binarySearchIterative(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
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
    public static int binarySearchRecursive(int[] arr, int left, int right, int target) {
        if (left > right) return -1; // Base case: target not found

        int mid = left + (right - left) / 2; // Prevents overflow

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            return binarySearchRecursive(arr, mid + 1, right, target); // Search right half
        else
            return binarySearchRecursive(arr, left, mid - 1, target); // Search left half
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int target = 10;

        // Iterative Binary Search
        int iterativeResult = binarySearchIterative(arr, target);
        System.out.println(iterativeResult != -1 ? "Iterative: Element found at index " + iterativeResult : "Iterative: Element not found");

        // Recursive Binary Search
        int recursiveResult = binarySearchRecursive(arr, 0, arr.length - 1, target);
        System.out.println(recursiveResult != -1 ? "Recursive: Element found at index " + recursiveResult : "Recursive: Element not found");
    }
}
