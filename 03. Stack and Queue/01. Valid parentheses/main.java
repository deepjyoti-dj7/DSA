import java.util.Stack;

public class main {
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c); // Push opening brackets
            } else {
                if (stack.isEmpty()) return false; // No matching opening bracket

                char top = stack.peek();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    stack.pop(); // Valid pair, remove from stack
                } else {
                    return false; // Mismatch
                }
            }
        }
        return stack.isEmpty(); // Stack should be empty if all brackets match
    }

    public static void main(String[] args) {
        String[] testCases = {"()", "()[]{}", "(]", "([)]", "{[]}"};

        for (String test : testCases) {
            System.out.println("String: " + test + " -> " + (isValid(test) ? "Valid" : "Invalid"));
        }
    }
}
