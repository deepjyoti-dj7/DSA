public class main {
    public static int longestOnes(int[] nums, int k) {
        int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) zeroCount++;

            while (zeroCount > k) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
        int k = 2;

        System.out.println("Maximum consecutive ones (with at most " + k + " flips): " 
                           + longestOnes(nums, k));
    }
}
