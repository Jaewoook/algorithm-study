import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(token.nextToken());
        int H;
        int[] num;
        int[] tree;
        while (N != 0) {
            num = new int[N + 1];
            H = (int) Math.pow(2, Math.ceil(Math.log(N) / Math.log(2)) + 1);
            tree = new int[H];
            for (int i = 1; i <= N; i++) {
                num[i] = Integer.parseInt(token.nextToken());
            }
            initTree(tree, num, 1, N, 1);
            bw.write(getMaxSize(tree, num, 1, N) + "\n");

            token = new StringTokenizer(br.readLine());
            N = Integer.parseInt(token.nextToken());
        }

        bw.flush();
        bw.close();
    }

    static void initTree(int[] tree, int[] num, int start, int end, int node) {
        if (start == end) {
            tree[node] = start;
            return;
        }

        int mid = (start + end) / 2;
        initTree(tree, num, start, mid, node << 1);
        initTree(tree, num, mid + 1, end, (node << 1) + 1);
        tree[node] = num[tree[node * 2]] <= num[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1];
    }

    static int queryTree(int[] tree, int[] num, int start, int end, int lRange, int rRange, int node) {
        if (rRange < start || end < lRange) {
            return -1;
        }

        if (lRange <= start && end <= rRange) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int r1 = queryTree(tree, num, start, mid, lRange, rRange, node << 1);
        int r2 = queryTree(tree, num, mid + 1, end, lRange, rRange, (node << 1) + 1);

        if (r1 > -1 && r2 > -1) {
            return num[r1] <= num[r2] ? r1 : r2;
        }
        return r1 > -1 ? r1 : r2;
    }

    static long getMaxSize(int[] tree, int[] num, int lRange, int rRange) {
        int lowIndex = queryTree(tree, num, 1, num.length - 1, lRange, rRange, 1);
        long maxSize = ((long) num[lowIndex]) * ((long) (rRange - lRange + 1));

        if (lRange < lowIndex) {
            maxSize = Math.max(maxSize, getMaxSize(tree, num, lRange, lowIndex - 1));
        }
        if (lowIndex < rRange) {
            maxSize = Math.max(maxSize, getMaxSize(tree, num, lowIndex + 1, rRange));
        }

        return maxSize;
    }
}
