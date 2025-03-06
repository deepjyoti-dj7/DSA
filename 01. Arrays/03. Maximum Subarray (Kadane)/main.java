class Main {
    public static int maxSubArray(int[] nums) {
        int maxSum = nums[0], currSum = 0;
        for (int num : nums) {
            currSum = Math.max(num, currSum + num);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Maximum Subarray Sum: " + maxSubArray(nums));
    }
}
