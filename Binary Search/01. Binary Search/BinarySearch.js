// Iterative Binary Search
function binarySearchIterative(arr, target) {
    let left = 0, right = arr.length - 1;

    while (left <= right) {
        let mid = Math.floor(left + (right - left) / 2); // Prevents overflow

        if (arr[mid] === target) 
            return mid; // Target found
        else if (arr[mid] < target) 
            left = mid + 1; // Search right half
        else 
            right = mid - 1; // Search left half
    }
    return -1; // Target not found
}

// Recursive Binary Search
function binarySearchRecursive(arr, left, right, target) {
    if (left > right) return -1; // Base case: target not found

    let mid = Math.floor(left + (right - left) / 2); // Prevents overflow

    if (arr[mid] === target) 
        return mid; // Target found
    else if (arr[mid] < target) 
        return binarySearchRecursive(arr, mid + 1, right, target); // Search right half
    else 
        return binarySearchRecursive(arr, left, mid - 1, target); // Search left half
}

function main() {
    let arr = [2, 3, 4, 10, 40];
    let target = 10;
    
    let iterativeResult = binarySearchIterative(arr, target);
    console.log(iterativeResult !== -1 ? `Iterative: Element found at index ${iterativeResult}` : "Iterative: Element not found");
    
    let recursiveResult = binarySearchRecursive(arr, 0, arr.length - 1, target);
    console.log(recursiveResult !== -1 ? `Recursive: Element found at index ${recursiveResult}` : "Recursive: Element not found");
}

main();
