import java.util.*;

public class main {
    // Brute Force - O(N*K)
    public static List<Integer> bruteForce(int[] nums, int k) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i <= nums.length - k; i++) {
            int maxVal = nums[i];
            for (int j = i; j < i + k; j++) {
                maxVal = Math.max(maxVal, nums[j]);
            }
            result.add(maxVal);
        }
        return result;
    }

    // Max Heap (Priority Queue) - O(N log K)
    public static List<Integer> heapSlidingWindow(int[] nums, int k) {
        List<Integer> result = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        for (int i = 0; i < nums.length; i++) {
            pq.offer(new int[]{nums[i], i});

            if (i >= k - 1) {
                while (pq.peek()[1] <= i - k) {
                    pq.poll();
                }
                result.add(pq.peek()[0]);
            }
        }
        return result;
    }

    // Optimized Deque Approach - O(N)
    public static List<Integer> dequeSlidingWindow(int[] nums, int k) {
        List<Integer> result = new ArrayList<>();
        Deque<Integer> dq = new LinkedList<>();

        for (int i = 0; i < nums.length; i++) {
            if (!dq.isEmpty() && dq.peekFirst() == i - k)
                dq.pollFirst();

            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i])
                dq.pollLast();

            dq.offerLast(i);

            if (i >= k - 1)
                result.add(nums[dq.peekFirst()]);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;

        System.out.println("Brute Force Output: " + bruteForce(nums, k));
        System.out.println("Heap Output: " + heapSlidingWindow(nums, k));
        System.out.println("Deque Output: " + dequeSlidingWindow(nums, k));
    }
}
