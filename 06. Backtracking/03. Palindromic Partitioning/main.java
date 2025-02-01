import java.util.*;

public class main {
    
    // Function to check if a substring is a palindrome
    private static boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start) != s.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }

    // Backtracking function to generate partitions
    private static void backtrack(int start, String s, List<String> current, List<List<String>> result) {
        if (start == s.length()) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                current.add(s.substring(start, end + 1)); // Take substring
                backtrack(end + 1, s, current, result);
                current.remove(current.size() - 1); // Backtrack
            }
        }
    }

    // Function to generate all palindromic partitions
    public static List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        backtrack(0, s, new ArrayList<>(), result);
        return result;
    }

    // Utility function to print partitions
    private static void printPartitions(List<List<String>> partitions) {
        for (List<String> partition : partitions) {
            System.out.println("  " + partition);
        }
    }

    public static void main(String[] args) {
        String s = "aab";
        System.out.println("Palindromic Partitions of \"" + s + "\":");
        printPartitions(partition(s));
    }
}
