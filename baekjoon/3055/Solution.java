import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;


class Main {
    static class Position {
        public int r, c;
        public Position(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static int[][] d = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String line = br.readLine();

        int R = Integer.parseInt(line.split(" ")[0]);
        int C = Integer.parseInt(line.split(" ")[1]);
        int[][] map = new int[R][C];
        int[][] v = new int[R][C];
        Position start = null, end = null;

        for (int i = 0; i < R; i++) {
            line = br.readLine();
            for (int j = 0; j < C; j++) {
                switch(line.charAt(j)) {
                    case '.':
                        map[i][j] = 0;
                        break;
                    case '*':
                        map[i][j] = 1;
                        break;
                    case 'D':
                        map[i][j] = 2;
                        end = new Position(i, j);
                        break;
                    case 'S':
                        map[i][j] = 0;
                        start = new Position(i, j);
                        break;
                    case 'X':
                        map[i][j] = 3;
                        break;
                }
            }
        }

        Queue<Position> phase = new LinkedList<>();
        Queue<Position> q = null;
        Position current;
        int next_r, next_c, count = 1;

        phase.add(start);
        v[start.r][start.c] = count;

        loop:
        while (!phase.isEmpty()) {
            q = new LinkedList<>(phase);
            phase.clear();
            count++;
            map = water(map);

            while (!q.isEmpty()) {
                current = q.poll();
                if (map[current.r][current.c] == 2) {
                    break loop;
                }

                for (int i = 0; i < 4; i++) {
                    next_r = current.r + d[i][0];
                    next_c = current.c + d[i][1];

                    if (!validBlock(R, C, next_r, next_c)) continue;
                    if (v[next_r][next_c] > 0) continue;

                    if (map[next_r][next_c] == 0 || map[next_r][next_c] == 2) {
                        phase.add(new Position(next_r, next_c));
                        v[next_r][next_c] = count;
                    }
                }
            }
        }

        count = v[end.r][end.c] - 1;
        bw.write(count == -1 ? "KAKTUS" : count + "\n");
        bw.flush();
        bw.close();
    }

    static boolean validBlock(int R, int C, int next_r, int next_c) {
        return next_r >= 0 && next_c >= 0 && next_r < R && next_c < C;
    }

    static int[][] water(int[][] map) {
        int R = map.length;
        int C = map[0].length;
        int[][] newMap = new int[R][C];
        for (int i = 0; i < R; i++) {
            newMap[i] = map[i].clone();
        }
        int next_r, next_c;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] != 1) continue;

                for (int k = 0; k < 4; k++) {
                    next_r = i + d[k][0];
                    next_c = j + d[k][1];
                    if (!validBlock(R, C, next_r, next_c)) continue;
                    if (map[next_r][next_c] != 0) continue;

                    newMap[next_r][next_c] = 1;
                }
            }
        }

        return newMap;
    }
}
