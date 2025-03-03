public class main {
    public static int jump(int[] nums) {
        int jumps = 0, farthest = 0, currentEnd = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            farthest = Math.max(farthest, i + nums[i]); // Update farthest reachable index

            if (i == currentEnd) { // If we reach the end of the current jump
                jumps++;
                currentEnd = farthest; // Move to the farthest reachable index
            }
        }

        return jumps;
    }

    public static void main(String[] args) {
        int[] nums1 = {2, 3, 1, 1, 4}; // Expected Output: 2
        System.out.println("Minimum jumps: " + jump(nums1));

        int[] nums2 = {1, 1, 1, 1}; // Expected Output: 3
        System.out.println("Minimum jumps: " + jump(nums2));
    }
}
