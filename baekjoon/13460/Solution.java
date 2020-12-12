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

    static class RedBlue {
        public Position red, blue;
        int count;
        public RedBlue(Position red, Position blue, int count) {
            this.red = red;
            this.blue = blue;
            this.count = count;
        }
    }

    static final int[][] d = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = br.readLine();
        int R = line.charAt(0) - '0';
        int C = line.charAt(0) - '0';

        int[][] map = new int[R][C];
        Position red = null, blue = null;

        for (int i = 0; i < R; i++) {
            line = br.readLine();
            for (int j = 0; j < C; j++) {
                switch (line.charAt(j)) {
                    case '#':
                    map[i][j] = 1;
                    break;
                    case '.':
                    map[i][j] = 0;
                    break;
                    case 'R':
                    map[i][j] = 0;
                    red = new Position(i, j);
                    break;
                    case 'B':
                    map[i][j] = 0;
                    blue = new Position(i, j);
                    break;
                    case '0':
                    map[i][j] = 2;
                    break;
                }
            }
        }

        Queue<RedBlue> q = new LinkedList<>();
        RedBlue current;
        int[][] v = new int[R][C];
        int red_r, red_c, blue_r, blue_c;
        boolean move_red, move_blue;
        int result = 0;

        q.add(new RedBlue(red, blue, 0));
        v[0][0] = 1;

        while (!q.isEmpty()) {
            current = q.poll();
            red = current.red;
            blue = current.blue;

            if (map[red.r][red.c] == 2) {
                if (map[blue.r][blue.c] == 2) {
                    continue;
                }
                result = v[red.r][red.c];
                break;
            } else if (v[red.r][red.c] == 10) {
                result = -1;
                break;
            }

            for (int i = 0; i < 4; i++) {
                red_r = red.r + d[i][0];
                red_c = red.c + d[i][1];
                blue_r = blue.r + d[i][0];
                blue_c = blue.c + d[i][1];
                move_red = move_blue = true;

                if (red_r < 0 || red_c < 0 || red_r > R - 1 || red_c > C - 1 || map[red_r][red_c] == 1) {
                    move_red = false;
                }
                if (blue_r < 0 || blue_c < 0 || blue_r > R - 1 || blue_c > C - 1) {
                    move_blue = false;
                }
                if (!move_red && !move_blue) {
                    continue;
                }

                if (move_red) {
                    red = new Position(red_r, red_c);
                }
                if (move_blue) {
                    blue = new Position(blue_r, blue_c);
                }
                if (red.r == blue.r && red.c == blue.c) {
                    continue;
                }
                q.add(new RedBlue(red, blue, current.count + 1));
                System.out.println("redblue added " + red.r + "," + red.c + " " + blue.r + "," + blue.c);
            }
        }

        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }
}
