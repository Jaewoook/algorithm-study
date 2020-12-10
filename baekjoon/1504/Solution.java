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
        int E = Integer.parseInt(token.nextToken());
        int[][] map = new int[N + 1][N + 1];
        int dist = 0, from, to, cost;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] = i == j ? 0 : Integer.MAX_VALUE;
            }
        }

        while (E-- > 0) {
            token = new StringTokenizer(br.readLine());
            from = Integer.parseInt(token.nextToken());
            to = Integer.parseInt(token.nextToken());
            cost = Integer.parseInt(token.nextToken());

            map[from][to] = cost;
            map[to][from] = cost;
        }

        token = new StringTokenizer(br.readLine());
        int X1 = Integer.parseInt(token.nextToken());
        int X2 = Integer.parseInt(token.nextToken());

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                if (k == i) continue;
                for (int j = 1; j <= N; j++) {
                    if (i == j || map[i][k] == Integer.MAX_VALUE || map[k][j] == Integer.MAX_VALUE) {
                        continue;
                    }
                    map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }

        int d1 = map[1][X1] + map[X1][X2] + map[X2][N];
        if (map[1][X1] == Integer.MAX_VALUE || map[X1][X2] == Integer.MAX_VALUE || map[X2][N] == Integer.MAX_VALUE) {
            d1 = -1;
        }

        int d2 = map[1][X2] + map[X2][X1] + map[X1][N];
        if (map[1][X2] == Integer.MAX_VALUE || map[X2][X1] == Integer.MAX_VALUE || map[X1][N] == Integer.MAX_VALUE) {
            d2 = -1;
        }
        if (d1 > 0 && d2 > 0) {
            dist = Math.min(d1, d2);
        } else if (d1 > 0 && d2 == -1) {
            dist = d1;
        } else if (d1 == -1 && d2 > 0) {
            dist = d2;
        } else {
            dist = -1;
        }

        bw.write(dist + "\n");
        bw.flush();;
        bw.close();
    }
}
