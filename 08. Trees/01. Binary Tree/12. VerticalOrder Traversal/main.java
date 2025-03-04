import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {
    public static List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, List<int[]>> map = new TreeMap<>();
        Queue<Object[]> queue = new LinkedList<>();
        queue.offer(new Object[]{root, 0, 0});

        while (!queue.isEmpty()) {
            Object[] arr = queue.poll();
            TreeNode node = (TreeNode) arr[0];
            int col = (int) arr[1], row = (int) arr[2];

            map.putIfAbsent(col, new ArrayList<>());
            map.get(col).add(new int[]{row, node.val});

            if (node.left != null) queue.offer(new Object[]{node.left, col - 1, row + 1});
            if (node.right != null) queue.offer(new Object[]{node.right, col + 1, row + 1});
        }

        List<List<Integer>> result = new ArrayList<>();
        for (List<int[]> colVals : map.values()) {
            colVals.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
            List<Integer> sortedVals = new ArrayList<>();
            for (int[] arr : colVals) sortedVals.add(arr[1]);
            result.add(sortedVals);
        }
        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println("Vertical Order Traversal: " + verticalTraversal(root));
    }
}
