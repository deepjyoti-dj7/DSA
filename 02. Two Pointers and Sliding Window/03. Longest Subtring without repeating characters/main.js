function bruteForce(s) {
    let maxLength = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = i; j < s.length; j++) {
            if (allUnique(s, i, j)) {
                maxLength = Math.max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

function allUnique(s, start, end) {
    let set = new Set();
    for (let i = start; i <= end; i++) {
        if (set.has(s[i])) return false;
        set.add(s[i]);
    }
    return true;
}

function improvedBruteForce(s) {
    let maxLength = 0;
    for (let i = 0; i < s.length; i++) {
        let seen = new Set();
        for (let j = i; j < s.length; j++) {
            if (seen.has(s[j])) break;
            seen.add(s[j]);
            maxLength = Math.max(maxLength, j - i + 1);
        }
    }
    return maxLength;
}

function slidingWindow(s) {
    let lastSeen = new Map(), left = 0, maxLength = 0;
    for (let right = 0; right < s.length; right++) {
        if (lastSeen.has(s[right])) {
            left = Math.max(left, lastSeen.get(s[right]) + 1);
        }
        lastSeen.set(s[right], right);
        maxLength = Math.max(maxLength, right - left + 1);
    }
    return maxLength;
}

function slidingWindowSet(s) {
    let seen = new Set(), left = 0, maxLength = 0;
    for (let right = 0; right < s.length; right++) {
        while (seen.has(s[right])) {
            seen.delete(s[left]);
            left++;
        }
        seen.add(s[right]);
        maxLength = Math.max(maxLength, right - left + 1);
    }
    return maxLength;
}

function main() {
    const s = prompt("Enter a string:");
    console.log("Brute Force:", bruteForce(s));
    console.log("Improved Brute Force:", improvedBruteForce(s));
    console.log("Sliding Window (Hash Map):", slidingWindow(s));
    console.log("Sliding Window (Hash Set):", slidingWindowSet(s));
}

main();
