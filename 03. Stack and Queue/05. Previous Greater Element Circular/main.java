import java.util.*;

public class main {
    public static int[] previousGreaterElements(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);
        Stack<Integer> stack = new Stack<>();

        // Traverse twice in reverse order to simulate circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= nums[i % n]) {
                stack.pop();
            }
            if (i < n) {
                if (!stack.isEmpty()) {
                    result[i] = stack.peek();
                }
                stack.push(nums[i]);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 2, 10, 8};
        int[] result = previousGreaterElements(nums);

        System.out.println("Previous Greater Elements (Circular):");
        System.out.println(Arrays.toString(result));
    }
}
