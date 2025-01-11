import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class LIS {

    // Recursive approach
    public static int LIS_Recursive(int[] arr, int ind, int prev) {
        if (ind == arr.length) 
            return 0;

        int notTake = LIS_Recursive(arr, ind + 1, prev);
        int take = 0;
        if (prev == -1 || arr[prev] < arr[ind]) 
            take = 1 + LIS_Recursive(arr, ind + 1, ind);

        return Math.max(take, notTake);
    }

    // Memoization approach
    public static int LIS_Memoization(int[] arr, int ind, int prev, int[][] dp) {
        if (ind == arr.length) 
            return 0;

        if (dp[ind][prev + 1] != -1) 
            return dp[ind][prev + 1];

        int notTake = LIS_Memoization(arr, ind + 1, prev, dp);
        int take = 0;
        if (prev == -1 || arr[prev] < arr[ind]) 
            take = 1 + LIS_Memoization(arr, ind + 1, ind, dp);

        return dp[ind][prev + 1] = Math.max(take, notTake);
    }

    // Tabulation approach
    public static int LIS_Tabulation(int[] arr, int n) {
        int[][] dp = new int[n + 1][n + 1];
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notTake = dp[ind + 1][prev + 1];
                int take = 0;
                if (prev == -1 || arr[prev] < arr[ind]) 
                    take = 1 + dp[ind + 1][ind + 1];

                dp[ind][prev + 1] = Math.max(take, notTake);
            }
        }
        return dp[0][0];
    }

    // Tabulation with Space Optimization
    public static int LIS_Tabulation_SpaceOptimized1(int[] arr, int n) {
        int[] cur = new int[n + 1];
        int[] next = new int[n + 1];

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notTake = next[prev + 1];
                int take = 0;
                if (prev == -1 || arr[prev] < arr[ind]) 
                    take = 1 + next[ind + 1];

                cur[prev + 1] = Math.max(take, notTake);
            }
            next = cur.clone();
        }
        return next[0];
    }

    public static int LIS_Tabulation_SpaceOptimized2(int[] arr, int n) {
        int maxi = 1;

        int[] dp = new int[n];
        for (int i : dp) dp[i] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i]) {
                    dp[i] = Math.max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = Math.max(maxi, dp[i]);
        }
        return maxi;
    }

    public static int LIS_Print(int[] arr, int n) {
        int maxi = 1;
        int lastIndex = 0;
        
        int[] dp = new int[n];
        for (int i : dp) dp[i] = 1;

        int[] hash = new int[n];

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        List<Integer> temp = new ArrayList<>();
        temp.add(arr[lastIndex]);

        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.add(arr[lastIndex]);
        }
        Collections.reverse(temp);

        System.out.print("LIS elements: ");
        for (int it : temp) {
            System.out.print(it + " ");
        }

        System.out.print("\nLength of LIS is: ");

        return maxi;
    }

    public static int LIS_binary_search(int[] arr, int n) {
        List<Integer> res = new ArrayList<>();
        res.add(arr[0]); 
        for (int i = 1; i < n; i++) {
            if (arr[i] > res.get(res.size() - 1)) 
                res.add(arr[i]);
            else {
                int ind = lowerBound(res, arr[i]);
                res.set(ind, arr[i]);
            }
        }
        return res.size();
    }

    public static int lowerBound(List<Integer> list, int key) {
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 5, 6, 0, 1};
        int n = arr.length;

        // Recursive solution
        System.out.println("Length of LIS (Recursive): " + LIS_Recursive(arr, 0, -1));

        // Memoization solution
        int[][] dp = new int[n][n + 1];
        for (int[] row : dp) 
            Arrays.fill(row, -1);
        System.out.println("Length of LIS (Memoization): " + LIS_Memoization(arr, 0, -1, dp));

        // Tabulation solution
        System.out.println("Length of LIS (Tabulation): " + LIS_Tabulation(arr, n));

        // Tabulation with Space Optimization 1 solution
        System.out.println("Length of LIS (Space Optimized 1): " + LIS_Tabulation_SpaceOptimized1(arr, n));

        // Tabulation with Space Optimization 1 solution
        System.out.println("Length of LIS (Space Optimized 2): " + LIS_Tabulation_SpaceOptimized2(arr, n));

        System.out.println(LIS_Print(arr, n));

        System.out.println("Length of LIS using binary search: " + LIS_binary_search(arr, n));
    }
}
