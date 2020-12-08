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
        StringTokenizer token;

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int[][] map = new int[N + 1][N + 1];
        int from = 0, to = 0, cost = 0;

        for (int i = 0; i < M; i++) {
            token = new StringTokenizer(br.readLine());
            from = Integer.parseInt(token.nextToken());
            to = Integer.parseInt(token.nextToken());
            cost = Integer.parseInt(token.nextToken());

            if (map[from][to] == 0 || map[from][to] > cost) {
                map[from][to] = cost;
            }
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                if (k == i) continue;
                for (int j = 1; j <= N; j++) {
                    if (i == j || map[i][k] == 0 || map[k][j] == 0) {
                        continue;
                    }

                    int costSum = map[i][k] + map[k][j];
                    if (map[i][j] == 0) {
                        map[i][j] = costSum;
                    } else if (costSum < map[i][j]) {
                        map[i][j] = costSum;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                bw.write(map[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
