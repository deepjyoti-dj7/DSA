function backtrack(start, n, k, current, result) {
    if (current.length === k) {
        result.push([...current]);
        return;
    }

    for (let i = start; i <= n; i++) {
        current.push(i);
        backtrack(i + 1, n, k, current, result);
        current.pop(); // Backtrack
    }
}

function combine(n, k) {
    let result = [];
    backtrack(1, n, k, [], result);
    return result;
}

// Main function
function main() {
    let n = 4, k = 2;
    let result = combine(n, k);

    console.log("Combinations:");
    console.log(result);
}

// Run the main function
main();
