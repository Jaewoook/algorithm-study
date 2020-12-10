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
        int X = Integer.parseInt(token.nextToken());
        int[][] dist = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = i == j ? 0 : Integer.MAX_VALUE;
            }
        }

        int start, end, cost;
        while (M-- > 0) {
            token = new StringTokenizer(br.readLine());
            start = Integer.parseInt(token.nextToken());
            end = Integer.parseInt(token.nextToken());
            cost = Integer.parseInt(token.nextToken());

            dist[start][end] = cost;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                if (k == i) continue;
                for (int j = 1; j <= N; j++) {
                    if (i == j || dist[i][k] == Integer.MAX_VALUE || dist[k][j] == Integer.MAX_VALUE) {
                        continue;
                    }

                    int len = dist[i][k] + dist[k][j];
                    if (len < dist[i][j]) {
                        dist[i][j] = len;
                    }
                }
            }
        }

        int highDist = 0, len = 0;
        for (int i = 1; i <= N; i++) {
            len = dist[i][X] + dist[X][i];
            highDist = highDist < len ? len : highDist;
        }

        bw.write(highDist + "\n");
        bw.flush();
        bw.close();
    }
}
