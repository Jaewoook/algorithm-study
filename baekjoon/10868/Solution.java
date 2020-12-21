import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    static final int MAX = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer token = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(token.nextToken());
        int M = Integer.parseInt(token.nextToken());

        int H = (int) Math.ceil(Math.log(N) / Math.log(2));
        int[] num = new int[N + 1];
        int[] tree = new int[1 << H + 1];

        for (int i = 1; i <= N; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }

        initTree(tree, num, 1, N, 1);

        int a, b;
        for (int i = 0; i < M; i++) {
            token = new StringTokenizer(br.readLine());
            a = Integer.parseInt(token.nextToken());
            b = Integer.parseInt(token.nextToken());
            bw.write(min(tree, 1, N, a, b, 1) + "\n");
        }

        bw.flush();
        bw.close();
    }

    static int initTree(int[] tree, int[] num, int start, int end, int node) {
        if (start == end) {
            return tree[node] = num[start];
        }

        int mid = (start + end) / 2;
        return tree[node] = Math.min(initTree(tree, num, start, mid, node * 2), initTree(tree, num, mid + 1, end, node * 2 + 1));
    }

    static int min(int[] tree, int start, int end, int from, int to, int node) {
        if (to < start || end < from) {
            return MAX;
        }

        if (from <= start && end <= to) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        return Math.min(min(tree, start, mid, from, to, node * 2), min(tree, mid + 1, end, from, to, node * 2 + 1));
    }
}
