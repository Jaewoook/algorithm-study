import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {
    static class Position implements Comparable<Position> {
        public int r, c, cost;
        public Position(int r, int c, int cost) {
            this.r = r;
            this.c = c;
            this.cost = cost;
        }

        @Override
        public int compareTo(Main.Position o) {
            return this.cost - o.cost;
        }
    }

    static int[][] d = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token;

        int count = 1;
        int size = 0;
        int[][] map;
        while (true) {
            size = Integer.parseInt(br.readLine());
            if (size == 0) break;

            map = new int[size + 1][size + 1];
            for (int i = 1; i <= size; i++) {
                token = new StringTokenizer(br.readLine());
                for (int j = 1; j <= size; j++) {
                    map[i][j] = Integer.parseInt(token.nextToken());
                }
            }

            bw.write("Problem " + count++ + ": " + dijkstra(map) + "\n");
        }

        bw.flush();
        bw.close();
    }

    static int dijkstra(int[][] map) {
        int N = map.length - 1;
        PriorityQueue<Position> q = new PriorityQueue<>();
        int[][] dist = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        Position current;
        int next_r, next_c;

        q.add(new Position(1, 1, map[1][1]));
        dist[1][1] = map[1][1];

        while (!q.isEmpty()) {
            current = q.poll();
            if (current.r == N && current.c == N) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                next_r = current.r + d[i][0];
                next_c = current.c + d[i][1];

                if (next_r < 1 || next_c < 1 || next_r > N || next_c > N) {
                    continue;
                }

                int len = dist[current.r][current.c] + map[next_r][next_c];
                if (dist[next_r][next_c] > len) {
                    dist[next_r][next_c] = len;
                    q.add(new Position(next_r, next_c, len));
                }
            }
        }

        return dist[N][N];
    }
}
