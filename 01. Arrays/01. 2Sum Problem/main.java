import java.util.*;

class main {
    // Brute Force - O(N^2)
    public static int[] twoSumBruteForce(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{nums[i], nums[j]};
                }
            }
        }
        return new int[]{-1, -1};
    }

    // Sorting + Two Pointers - O(N log N)
    public static int[] twoSumSorting(int[] nums, int target) {
        int[][] indexedNums = new int[nums.length][2];
        for (int i = 0; i < nums.length; i++) {
            indexedNums[i] = new int[]{nums[i], i};
        }
        Arrays.sort(indexedNums, Comparator.comparingInt(a -> a[0]));

        int left = 0, right = nums.length - 1;
        while (left < right) {
            int sum = indexedNums[left][0] + indexedNums[right][0];
            if (sum == target) {
                return new int[]{indexedNums[left][0], indexedNums[right][0]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return new int[]{-1, -1};
    }

    // Hashing (Optimal) - O(N)
    public static int[] twoSumHashing(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            int complement = target - num;
            if (map.containsKey(complement)) {
                return new int[]{complement, num};
            }
            map.put(num, 1);
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;

        System.out.println("Brute Force: " + Arrays.toString(twoSumBruteForce(nums, target)));
        System.out.println("Sorting + Two Pointers: " + Arrays.toString(twoSumSorting(nums, target)));
        System.out.println("Hashing: " + Arrays.toString(twoSumHashing(nums, target)));
    }
}
