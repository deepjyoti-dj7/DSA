import java.util.*;

public class main {

    // Brute Force O(N^3)
    public static List<List<Integer>> threeSumBruteForce(int[] nums) {
        Set<List<Integer>> uniqueTriplets = new HashSet<>();
        int n = nums.length;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> triplet = Arrays.asList(nums[i], nums[j], nums[k]);
                        Collections.sort(triplet);
                        uniqueTriplets.add(triplet);
                    }
                }
            }
        }

        return new ArrayList<>(uniqueTriplets);
    }

    // Optimized Two Pointers O(N^2)
    public static List<List<Integer>> threeSumOptimized(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }

    public static void printTriplets(List<List<Integer>> triplets) {
        for (List<Integer> triplet : triplets) {
            System.out.println(triplet);
        }
    }

    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};

        System.out.println("Brute Force Approach results:");
        List<List<Integer>> brute = threeSumBruteForce(nums);
        printTriplets(brute);

        System.out.println("\nOptimized Two Pointers Approach results:");
        List<List<Integer>> optimized = threeSumOptimized(nums);
        printTriplets(optimized);
    }
}
