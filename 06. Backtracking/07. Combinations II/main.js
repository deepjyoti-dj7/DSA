function backtrack(candidates, target, start, current, result) {
    if (target === 0) {
        result.push([...current]);
        return;
    }

    for (let i = start; i < candidates.length; i++) {
        if (i > start && candidates[i] === candidates[i - 1]) continue; // Skip duplicates
        if (candidates[i] > target) break; // No need to proceed

        current.push(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, current, result);
        current.pop(); // Backtrack
    }
}

function combinationSum2(candidates, target) {
    candidates.sort((a, b) => a - b); // Sort to handle duplicates
    const result = [];
    backtrack(candidates, target, 0, [], result);
    return result;
}

function main() {
    const candidates = [10, 1, 2, 7, 6, 1, 5];
    const target = 8;
    console.log("Combinations:", combinationSum2(candidates, target));
}

// Run the main function
main();
