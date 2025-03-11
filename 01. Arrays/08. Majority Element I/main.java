import java.util.Arrays;
import java.util.HashMap;

class main {
    // Brute Force
    public static int majorityElementBruteForce(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) count++;
            }
            if (count > n / 2) return nums[i];
        }
        return -1;
    }

    // Sorting
    public static int majorityElementSorting(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }

    // HashMap
    public static int majorityElementHashMap(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) freq.put(num, freq.getOrDefault(num, 0) + 1);
        for (int key : freq.keySet()) {
            if (freq.get(key) > nums.length / 2) return key;
        }
        return -1;
    }

    // Boyer-Moore Voting Algorithm (Optimal)
    public static int majorityElementBoyerMoore(int[] nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }

    // Main Function
    public static void main(String[] args) {
        int[] nums = {3, 2, 3};
        System.out.println("Brute Force: " + majorityElementBruteForce(nums));
        System.out.println("Sorting: " + majorityElementSorting(nums));
        System.out.println("HashMap: " + majorityElementHashMap(nums));
        System.out.println("Boyer-Moore: " + majorityElementBoyerMoore(nums));
    }
}
