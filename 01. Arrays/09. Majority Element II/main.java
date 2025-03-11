import java.util.*;

class main {
    // Brute Force Approach - O(n²) Time, O(1) Space
    public static List<Integer> majorityElementBruteForce(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) count++;
            }
            if (count > n / 3 && !result.contains(nums[i])) result.add(nums[i]);
        }
        return result;
    }

    // Sorting Approach - O(n log n) Time, O(1) Space
    public static List<Integer> majorityElementSorting(int[] nums) {
        Arrays.sort(nums);
        List<Integer> result = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n;) {
            int count = 0, num = nums[i];
            while (i < n && nums[i] == num) { count++; i++; }
            if (count > n / 3) result.add(num);
        }
        return result;
    }

    // HashMap Approach - O(n) Time, O(n) Space
    public static List<Integer> majorityElementHashMap(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) freq.put(num, freq.getOrDefault(num, 0) + 1);
        List<Integer> result = new ArrayList<>();
        for (int key : freq.keySet()) {
            if (freq.get(key) > nums.length / 3) result.add(key);
        }
        return result;
    }

    // Boyer-Moore Voting Algorithm - O(n) Time, O(1) Space
    public static List<Integer> majorityElementBoyerMoore(int[] nums) {
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) { candidate1 = num; count1 = 1; }
            else if (count2 == 0) { candidate2 = num; count2 = 1; }
            else { count1--; count2--; }
        }
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        List<Integer> result = new ArrayList<>();
        int n = nums.length;
        if (count1 > n / 3) result.add(candidate1);
        if (count2 > n / 3) result.add(candidate2);
        return result;
    }

    // Main Function
    public static void main(String[] args) {
        int[] nums = {3, 2, 3, 1, 1, 1, 2, 2};
        System.out.println("Brute Force: " + majorityElementBruteForce(nums));
        System.out.println("Sorting: " + majorityElementSorting(nums));
        System.out.println("HashMap: " + majorityElementHashMap(nums));
        System.out.println("Boyer-Moore: " + majorityElementBoyerMoore(nums));
    }
}
