import java.util.*;

public class main {
    public static void generateSubsets(int index, int[] nums, List<Integer> current, List<List<Integer>> result) {
        // Base case: If we've processed all elements, add current subset to result
        if (index == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        // Exclude the current element and move to the next
        generateSubsets(index + 1, nums, current, result);

        current.add(nums[index]); // Include the current element
        generateSubsets(index + 1, nums, current, result);
        current.remove(current.size() - 1); // Backtrack: Remove the last added element
    }

    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        generateSubsets(0, nums, new ArrayList<>(), result);
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        System.out.println("Subsets using Backtracking:");
        System.out.println(subsets(nums));
    }
}
