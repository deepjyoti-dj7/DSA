public class main {
    public static boolean canJump(int[] nums) {
        int maxReach = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (i > maxReach) return false; // If we can't reach this index, return false
            maxReach = Math.max(maxReach, i + nums[i]); // Update farthest reach
            if (maxReach >= nums.length - 1) return true; // Early exit if we can reach the last index
        }

        return false;
    }

    public static void main(String[] args) {
        int[] nums1 = {2, 3, 1, 1, 4}; // Expected Output: true
        System.out.println(canJump(nums1));

        int[] nums2 = {3, 2, 1, 0, 4}; // Expected Output: false
        System.out.println(canJump(nums2));
    }
}
