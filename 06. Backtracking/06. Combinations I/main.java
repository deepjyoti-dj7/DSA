import java.util.*;

public class main {
    public static void backtrack(int start, int n, int k, List<Integer> current, List<List<Integer>> result) {
        if (current.size() == k) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = start; i <= n; i++) {
            current.add(i);
            backtrack(i + 1, n, k, current, result);
            current.remove(current.size() - 1); // Backtrack
        }
    }

    public static List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(1, n, k, new ArrayList<>(), result);
        return result;
    }

    public static void main(String[] args) {
        int n = 4, k = 2;
        List<List<Integer>> result = combine(n, k);

        System.out.println("Combinations:");
        for (List<Integer> comb : result) {
            System.out.println(comb);
        }
    }
}
