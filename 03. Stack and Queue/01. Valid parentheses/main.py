def isValid(s):
    stack = []

    for c in s:
        if c in "({[":
            stack.append(c)  # Push opening brackets
        else:
            if not stack:  # No matching opening bracket
                return False
            
            top = stack[-1]
            if (c == ')' and top == '(') or (c == '}' and top == '{') or (c == ']' and top == '['):
                stack.pop()  # Valid pair, remove from stack
            else:
                return False  # Mismatch

    return not stack  # Stack should be empty if all brackets match

def main():
    testCases = ["()", "()[]{}", "(]", "([)]", "{[]}"]
    for test in testCases:
        print(f"String: {test} -> {'Valid' if isValid(test) else 'Invalid'}")

main()