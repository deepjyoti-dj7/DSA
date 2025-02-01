// Function to check if a substring is a palindrome
function isPalindrome(s, start, end) {
    while (start < end) {
        if (s[start] !== s[end]) return false;
        start++;
        end--;
    }
    return true;
}

// Backtracking function to generate partitions
function backtrack(start, s, current, result) {
    if (start === s.length) {
        result.push([...current]);
        return;
    }

    for (let end = start; end < s.length; end++) {
        if (isPalindrome(s, start, end)) {
            current.push(s.substring(start, end + 1)); // Take substring
            backtrack(end + 1, s, current, result);
            current.pop(); // Backtrack
        }
    }
}

// Function to generate all palindromic partitions
function partition(s) {
    let result = [];
    backtrack(0, s, [], result);
    return result;
}

// Utility function to print partitions
function printPartitions(partitions) {
    partitions.forEach(partition => console.log("  ", partition));
}

// Main function
function main() {
    let s = "aab";
    console.log(`Palindromic Partitions of "${s}":`);
    printPartitions(partition(s));
}

main();
