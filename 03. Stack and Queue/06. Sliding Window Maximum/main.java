import java.util.*;

public class main {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();
        int[] result = new int[nums.length - k + 1];
        int index = 0;

        for (int i = 0; i < nums.length; i++) {
            if (!dq.isEmpty() && dq.peekFirst() == i - k) 
                dq.pollFirst();

            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) 
                dq.pollLast();

            dq.offerLast(i);

            if (i >= k - 1) 
                result[index++] = nums[dq.peekFirst()];
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
        int[] result = maxSlidingWindow(nums, k);

        for (int num : result) 
            System.out.print(num + " ");
        System.out.println();
    }
}
