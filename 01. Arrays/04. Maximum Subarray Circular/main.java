public class main {
    public static int kadane(int[] nums) {
        int maxSum = nums[0], currentSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }
        return maxSum;
    }

    public static int maxCircularSubarraySum(int[] nums) {
        int maxKadane = kadane(nums);
        int totalSum = 0, minSum = nums[0], currentMin = nums[0];

        for (int i = 0; i < nums.length; i++) {
            totalSum += nums[i];
            if (i > 0) {
                currentMin = Math.min(nums[i], currentMin + nums[i]);
                minSum = Math.min(minSum, currentMin);
            }
        }

        if (totalSum == minSum) return maxKadane;
        return Math.max(maxKadane, totalSum - minSum);
    }

    public static void main(String[] args) {
        int[] nums = {5, -3, 5};
        System.out.println("Maximum Circular Subarray Sum: " + maxCircularSubarraySum(nums));
    }
}
