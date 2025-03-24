import java.util.*;

public class main {
    
    // 1. Brute Force (O(n^3))
    public static int bruteForce(String s) {
        int n = s.length(), maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (allUnique(s, i, j)) {
                    maxLength = Math.max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }

    private static boolean allUnique(String s, int start, int end) {
        Set<Character> set = new HashSet<>();
        for (int i = start; i <= end; i++) {
            if (set.contains(s.charAt(i))) return false;
            set.add(s.charAt(i));
        }
        return true;
    }

    // 2. Improved Brute Force (O(n^2))
    public static int improvedBruteForce(String s) {
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            Set<Character> seen = new HashSet<>();
            for (int j = i; j < s.length(); j++) {
                if (seen.contains(s.charAt(j))) break;
                seen.add(s.charAt(j));
                maxLength = Math.max(maxLength, j - i + 1);
            }
        }
        return maxLength;
    }

    // 3. Sliding Window (O(n)) using HashMap
    public static int slidingWindow(String s) {
        Map<Character, Integer> lastSeen = new HashMap<>();
        int left = 0, maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (lastSeen.containsKey(s.charAt(right))) {
                left = Math.max(left, lastSeen.get(s.charAt(right)) + 1);
            }
            lastSeen.put(s.charAt(right), right);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }

    // 4. Sliding Window using HashSet
    public static int slidingWindowSet(String s) {
        Set<Character> seen = new HashSet<>();
        int left = 0, maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            while (seen.contains(s.charAt(right))) {
                seen.remove(s.charAt(left));
                left++;
            }
            seen.add(s.charAt(right));
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanner.next();
        
        System.out.println("Brute Force: " + bruteForce(s));
        System.out.println("Improved Brute Force: " + improvedBruteForce(s));
        System.out.println("Sliding Window (Hash Map): " + slidingWindow(s));
        System.out.println("Sliding Window (Hash Set): " + slidingWindowSet(s));

        scanner.close();
    }
}
