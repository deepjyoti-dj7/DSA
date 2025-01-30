function isValid(s) {
    let stack = [];

    for (let c of s) {
        if (c === '(' || c === '{' || c === '[') {
            stack.push(c); // Push opening brackets
        } else {
            if (stack.length === 0) return false; // No matching opening bracket

            let top = stack[stack.length - 1];
            if ((c === ')' && top === '(') || 
                (c === '}' && top === '{') || 
                (c === ']' && top === '[')) {
                stack.pop(); // Valid pair, remove from stack
            } else {
                return false; // Mismatch
            }
        }
    }
    return stack.length === 0; // Stack should be empty if all brackets match
}


function main() {
    const testCases = ["()", "()[]{}", "(]", "([)]", "{[]}"];
    testCases.forEach(test => {
        console.log(`String: ${test} -> ${isValid(test) ? "Valid" : "Invalid"}`);
    });
}

main();