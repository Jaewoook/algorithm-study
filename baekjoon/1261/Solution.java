import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {

    static class Position implements Comparable<Position> {
        int r, c, cost;
        public Position(int r, int c, int cost) {
            this.r = r;
            this.c = c;
            this.cost = cost;
        }

        @Override
        public int compareTo(Position p) {
            return this.cost < p.cost ? -1 : 1;
        }
    }

    static final int[][] d = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(token.nextToken());
        int N = Integer.parseInt(token.nextToken());
        int[][] map = new int[N + 1][M + 1], dist = new int[N + 1][M + 1];

        String mapLine;
        for (int i = 1; i <= N; i++) {
            mapLine = br.readLine();
            for (int j = 1; j <= M; j++) {
                map[i][j] = mapLine.charAt(j - 1) - '0';
                dist[i][j] = 1000000;
            }
        }

        int next_r, next_c;
        Position current;
        PriorityQueue<Position> q = new PriorityQueue<>();
        dist[1][1] = 0;
        q.add(new Position(1, 1, 0));

        while (!q.isEmpty()) {
            current = q.poll();
            if (current.r == N && current.c == M) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                next_r = current.r + d[i][0];
                next_c = current.c + d[i][1];

                if (next_r < 1 || next_c < 1 || next_r > N || next_c > M) {
                    continue;
                }
                if (dist[current.r][current.c] + map[next_r][next_c] < dist[next_r][next_c]) {
                    dist[next_r][next_c] = dist[current.r][current.c] + map[next_r][next_c];
                    q.add(new Position(next_r, next_c, dist[next_r][next_c]));
                }
            }
        }

        bw.write(dist[N][M] + "\n");
        bw.flush();
        bw.close();
    }
}
