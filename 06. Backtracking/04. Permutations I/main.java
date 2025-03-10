import java.util.*;

public class Permutations {
    public static void backtrack(List<List<Integer>> result, List<Integer> current, boolean[] used, int[] nums) {
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            
            used[i] = true;
            current.add(nums[i]);
            backtrack(result, current, used, nums);
            current.remove(current.size() - 1);
            used[i] = false;
        }
    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), new boolean[nums.length], nums);
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        System.out.println("Permutations: " + permute(nums));
    }
}
