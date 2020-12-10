import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {
    static class Position implements Comparable<Position> {
        int i, cost;
        public Position(int i, int cost) {
            this.i = i;
            this.cost = cost;
        }

        @Override
        public int compareTo(Main.Position o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(token.nextToken());
        int M = Integer.parseInt(token.nextToken());
        int X = Integer.parseInt(token.nextToken());
        int[][] startMap = new int[N + 1][N + 1];
        int[][] endMap = new int[N + 1][N + 1];
        int[] starts = new int[N + 1];
        int[] ends = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            starts[i] = Integer.MAX_VALUE;
            ends[i] = Integer.MAX_VALUE;
            for (int j = 1; j <= N; j++) {
                startMap[i][j] = i == j ? 0 : Integer.MAX_VALUE;
                endMap[i][j] = i == j ? 0 : Integer.MAX_VALUE;
            }
        }

        int start, end, cost;
        while (M-- > 0) {
            token = new StringTokenizer(br.readLine());
            start = Integer.parseInt(token.nextToken());
            end = Integer.parseInt(token.nextToken());
            cost = Integer.parseInt(token.nextToken());

            startMap[start][end] = cost;
            endMap[end][start] = cost;
        }

        dijkstra(startMap, starts, X);
        dijkstra(endMap, ends, X);

        int dist = 0;
        for (int i = 1; i <= N; i++) {
            dist = Math.max(dist, starts[i] + ends[i]);
        }

        bw.write(dist + "\n");
        bw.flush();
        bw.close();
    }

    static void dijkstra(int[][] map, int[] dist, int start) {
        int N = map.length - 1;
        PriorityQueue<Position> q = new PriorityQueue<>();
        q.add(new Position(start, 0));
        dist[start] = 0;
        Position current;

        while (!q.isEmpty()) {
            current = q.poll();

            for (int i = 1; i <= N; i++) {
                if (map[current.i][i] == Integer.MAX_VALUE) continue;
                if (dist[i] > dist[current.i] + map[current.i][i]) {
                    dist[i] = dist[current.i] + map[current.i][i];
                    q.add(new Position(i, dist[i]));
                }
            }
        }
    }
}
