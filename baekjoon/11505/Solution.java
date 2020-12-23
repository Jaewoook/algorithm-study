import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(token.nextToken());
        int M = Integer.parseInt(token.nextToken()) + Integer.parseInt(token.nextToken());
        int H = 1;
        while (H < N * 2) {
            H <<= 1;
        }
        int[] num = new int[N + 1];
        long[] tree = new long[H];
        for (int i = 1; i <= N; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }

        initTree(tree, num, 1, N, 1);

        int a, b, c;
        for (int i = 0; i < M; i++) {
            token = new StringTokenizer(br.readLine());
            a = Integer.parseInt(token.nextToken());
            b = Integer.parseInt(token.nextToken());
            c = Integer.parseInt(token.nextToken());
            if (a == 1) {
                updateTree(tree, num, 1, N, b, 1, c);
                num[b] = c;
            } else {
                bw.write(queryTree(tree, 1, N, b, c, 1) + "\n");
            }
        }

        bw.flush();
        bw.close();
    }

    static void initTree(long[] tree, int[] num, int start, int end, int node) {
        if (start == end) {
            tree[node] = num[start];
            return;
        }

        int mid = (start + end) / 2;
        initTree(tree, num, start, mid, node * 2);
        initTree(tree, num, mid + 1, end, node * 2 + 1);
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
    }

    static long queryTree(long[] tree, int start, int end, int from, int to, int node) {
        if (end < from || to < start) {
            return 1;
        }

        if (from <= start && end <= to) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        long r1 = queryTree(tree, start, mid, from, to, node * 2);
        long r2 = queryTree(tree, mid + 1, end, from, to, node * 2 + 1);
        return (r1 * r2) % MOD;
    }

    static long updateTree(long[] tree, int[] num, int start, int end, int idx, int node, int val) {
        if (end < idx || idx < start) {
            return tree[node];
        }

        if (start == end) {
            return tree[node] = val;
        }

        int mid = (start + end) / 2;
        long r1 = updateTree(tree, num, start, mid, idx, node * 2, val);
        long r2 = updateTree(tree, num, mid + 1, end, idx, node * 2 + 1, val);
        return tree[node] = (r1 * r2) % MOD;
    }
}
