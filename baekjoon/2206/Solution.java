import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

class Main {

    static final int d[][] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] NM = br.readLine().split(" ");
        String line;
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);
        boolean[][] map = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j) - 48 == 1 ? true : false;
            }
        }

        bw.write(bfs(N, M, map) + "\n");
        bw.flush();
        bw.close();
    }

    static int bfs(int N, int M, boolean[][] map) {
        if (N == 1 && M == 1) {
            return 1;
        }

        Queue<int[]> q = new LinkedList<>();
        int[][][] v = new int[N][M][2];
        int[] current, next = new int[2];

        q.add(new int[] { 0, 0, 0 });
        v[0][0][0] = 1;

        while (!q.isEmpty()) {
            current = q.poll();

            if (current[0] == N - 1 && current[1] == M - 1) {
                return v[current[0]][current[1]][current[2]];
            }

            for (int i = 0; i < 4; i++) {
                next[0] = current[0] + d[i][0];
                next[1] = current[1] + d[i][1];

                if (next[0] < 0 || next[0] >= N || next[1] < 0 || next[1] >= M) {
                    continue;
                }

                if (map[next[0]][next[1]] && current[2] == 0) {
                    v[next[0]][next[1]][1] = v[current[0]][current[1]][current[2]] + 1;
                    q.add(new int[] { next[0], next[1], 1 });
                } else if (!map[next[0]][next[1]] && v[next[0]][next[1]][current[2]] == 0) {
                    v[next[0]][next[1]][current[2]] = v[current[0]][current[1]][current[2]] + 1;
                    q.add(new int[] { next[0], next[1], current[2] });
                }
            }
        }

        return -1;
    }
}
