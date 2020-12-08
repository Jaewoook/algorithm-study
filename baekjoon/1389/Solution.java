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
        int[][] relations = new int[N + 1][N + 1];
        int min = 0, count = 0, n = 0;

        for (int i = 1; i <= M; i++) {
            token = new StringTokenizer(br.readLine());
            int p1 = Integer.parseInt(token.nextToken());
            int p2 = Integer.parseInt(token.nextToken());
            relations[p1][p2] = 1;
            relations[p2][p1] = 1;
        }

        for (int p = 1; p <= N; p++) {
            for (int i = 1; i <= N; i++) {
                if (p == i) continue;
                for (int j = 1; j <= N; j++) {
                    if (i == j || relations[i][p] == 0 || relations[p][j] == 0) {
                        continue;
                    }

                    int len = relations[i][p] + relations[p][j];
                    if (relations[i][j] == 0) {
                        relations[i][j] = len;
                    } else if (len < relations[i][j]) {
                        relations[i][j] = len;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            count = 0;
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                count += relations[i][j];
            }
            if (count > 0 && (min == 0 || count < min)) {
                min = count;
                n = i;
            }
        }

        bw.write(n + "\n");
        bw.flush();
        bw.close();
    }
}
