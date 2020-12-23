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
        int M = Integer.parseInt(token.nextToken());
        int K = Integer.parseInt(token.nextToken());

        int H = (int) Math.ceil(Math.log(N) / Math.log(2));
        long[] num = new long[N + 1];
        long[] tree = new long[1 << H + 1];
        long[] lazy = new long[1 << H + 1];
        for (int i = 1; i <= N; i++) {
            num[i] = Long.parseLong(br.readLine());
        }

        initTree(tree, num, 1, N, 1);

        int a, b, c;
        long d;
        for (int i = 0; i < M + K; i++) {
            token = new StringTokenizer(br.readLine());
            a = Integer.parseInt(token.nextToken());
            b = Integer.parseInt(token.nextToken());
            c = Integer.parseInt(token.nextToken());
            if (a == 1) {
                d = Long.parseLong(token.nextToken());
                updateTree(tree, lazy, 1, N, b, c, 1, d);
            } else {
                bw.write(queryTree(tree, lazy, 1, N, b, c, 1) + "\n");
            }
        }

        bw.flush();
        bw.close();
    }

    static void initTree(long[] tree, long[] num, int start, int end, int node) {
        if (start == end) {
            tree[node] = num[start];
            return;
        }

        int mid = (start + end) / 2;
        initTree(tree, num, start, mid, node * 2);
        initTree(tree, num, mid + 1, end, node * 2 + 1);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    static long queryTree(long[] tree, long[] lazy, int start, int end, int from, int to, int node) {
        lazyUpdate(tree, lazy, start, end, node);
        if (to < start || end < from) {
            return 0;
        }

        if (from <= start && end <= to) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        long r1 = queryTree(tree, lazy, start, mid, from, to, node * 2);
        long r2 = queryTree(tree, lazy, mid + 1, end, from, to, node * 2 + 1);
        return r1 + r2;
    }

    static void updateTree(long[] tree, long[] lazy, int start, int end, int from, int to, int node, long diff) {
        lazyUpdate(tree, lazy, start, end, node);
        if (to < start || end < from) {
            return;
        }

        if (from <= start && end <= to) {
            lazy[node] += diff;
            lazyUpdate(tree, lazy, start, end, node);
            return;
        }

        int mid = (start + end) / 2;
        updateTree(tree, lazy, start, mid, from, to, node * 2, diff);
        updateTree(tree, lazy, mid + 1, end, from, to, node * 2 + 1, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    static void lazyUpdate(long[] tree, long[] lazy, int start, int end, int node) {
        if (lazy[node] == 0) {
            return;
        }

        tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
