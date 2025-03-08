import java.util.*;

public class main {
    
    // 🔹 Brute Force (O(N²))
    public static int subarraySumBrute(int[] nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }

    // 🔹 Optimized (O(N)) - Prefix Sum + HashMap
    public static int subarraySumOptimized(int[] nums, int k) {
        Map<Integer, Integer> prefixSumCount = new HashMap<>();
        prefixSumCount.put(0, 1);

        int count = 0, prefixSum = 0;
        for (int num : nums) {
            prefixSum += num;
            if (prefixSumCount.containsKey(prefixSum - k)) {
                count += prefixSumCount.get(prefixSum - k);
            }
            prefixSumCount.put(prefixSum, prefixSumCount.getOrDefault(prefixSum, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 2, -1, 2};
        int k = 5;

        System.out.println("Brute Force: " + subarraySumBrute(nums, k));
        System.out.println("Optimized: " + subarraySumOptimized(nums, k));
    }
}
