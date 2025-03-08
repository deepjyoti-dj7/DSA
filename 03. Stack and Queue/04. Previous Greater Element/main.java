import java.util.Stack;

public class main {
    public static int[] previousGreaterElement(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        int[] result = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && stack.peek() <= nums[i]) {
                stack.pop();
            }
            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(nums[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 2, 10, 8};
        int[] result = previousGreaterElement(nums);

        System.out.println("Previous Greater Elements:");
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
