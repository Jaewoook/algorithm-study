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

        long[] num = new long[N + 1];
        int H = (int) Math.ceil(Math.log(N) / Math.log(2));
        long[] tree = new long[1 << (H + 1)];

        for (int i = 1; i <= N; i++) {
            num[i] = Long.parseLong(br.readLine());
        }

        initTree(tree, num, 1, N, 1);

        int a, b;
        long c;
        for (int i = 0; i < M + K; i++) {
            token = new StringTokenizer(br.readLine());
            a = Integer.parseInt(token.nextToken());
            b = Integer.parseInt(token.nextToken());
            c = Long.parseLong(token.nextToken());
            if (a == 1) {
                updateTree(tree, 1, N, 1, b, c - num[b]);
                num[b] = c;
            } else {
                bw.write(sumTree(tree, 1, N, b, c, 1) + "\n");
            }
        }

        bw.flush();
        bw.close();
    }

    static long initTree(long[] tree, long[] num, int start, int end, int node) {
        if (start == end) {
            return tree[node] = num[start];
        }
        int mid = (start + end) / 2;
        return tree[node] = initTree(tree, num, start, mid, node * 2) + initTree(tree, num, mid + 1, end, node * 2 + 1);
    }

    static void updateTree(long[] tree, int start, int end, int node, int index, long diff) {
        if (index < start || end < index) {
            return;
        }

        tree[node] += diff;
        if (start == end) {
            return;
        }

        int mid = (start + end) / 2;
        updateTree(tree, start, mid, node * 2, index, diff);
        updateTree(tree, mid + 1, end, node * 2 + 1, index, diff);
    }

    static long sumTree(long[] tree, int start, int end, int from, long to, int node) {
        if (end < from || to < start) {
            return 0;
        }

        if (from <= start && end <= to) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        return sumTree(tree, start, mid, from, to, node * 2) + sumTree(tree, mid + 1, end, from, to, node * 2 + 1);
    }

}
