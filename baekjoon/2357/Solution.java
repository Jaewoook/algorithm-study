import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    static final int MIN = 0;
    static final int MAX = 1000000001;

    static class MinMax {
        public int min, max;
        public MinMax(int min, int max) {
            this.min = min;
            this.max = max;
        }
        @Override
        public String toString() {
            return min + " " + max;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(token.nextToken());
        int M = Integer.parseInt(token.nextToken());
        int[] num = new int[N + 1];
        int H = (int) Math.ceil(Math.log(N) / Math.log(2));
        MinMax[] tree = new MinMax[1 << (H + 1)];

        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }

        initTree(tree, num, 0, N - 1, 1);

        int a, b;
        for (int i = 0; i < M; i++) {
            token = new StringTokenizer(br.readLine());
            a = Integer.parseInt(token.nextToken());
            b = Integer.parseInt(token.nextToken());
            bw.write(query(tree, 1, N, a, b, 1) + "\n");
        }

        bw.flush();
        bw.close();
    }

    static MinMax initTree(MinMax[] tree, int[] num, int start, int end, int node) {
        if (start == end) {
            return tree[node] = new MinMax(num[start], num[start]);
        }

        int mid = (start + end) / 2;
        MinMax r1 = initTree(tree, num, start, mid, node * 2);
        MinMax r2 = initTree(tree, num, mid + 1, end, node * 2 + 1);
        return tree[node] = new MinMax(Math.min(r1.min, r2.min), Math.max(r1.max, r2.max));
    }

    static MinMax query(MinMax[] tree, int start, int end, int from, int to, int node) {
        if (to < start || end < from) {
            return new MinMax(MAX, MIN);
        }
        if (from <= start && end <= to) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        MinMax r1 = query(tree, start, mid, from, to, node * 2);
        MinMax r2 = query(tree, mid + 1, end, from, to, node * 2 + 1);
        return new MinMax(Math.min(r1.min, r2.min), Math.max(r1.max, r2.max));
    }
}
