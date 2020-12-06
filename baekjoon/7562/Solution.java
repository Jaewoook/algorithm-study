import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

    static final int[][] d = {
        {-2, 1}, {-1, 2},
        {1, 2}, {2, 1},
        {2, -1}, {1, -2},
        {-1, -2}, {-2, -1},
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer token;

        int T = Integer.parseInt(br.readLine());
        int size;
        int[] start, dest;
        while (T-- > 0) {
            size = Integer.parseInt(br.readLine());
            start = new int[2];
            dest = new int[2];
            token = new StringTokenizer(br.readLine());
            start[0] = Integer.parseInt(token.nextToken());
            start[1] = Integer.parseInt(token.nextToken());

            token = new StringTokenizer(br.readLine());
            dest[0] = Integer.parseInt(token.nextToken());
            dest[1] = Integer.parseInt(token.nextToken());

            bw.write(bfs(start, dest, size) + "\n");
        }
        bw.flush();
        bw.close();
    }

    static int bfs(int[] start, int[] dest, int size) {
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[size][size];
        int count = 0;
        int[] current, next = new int[2];

        q.add(new int[] { start[0], start[1], 0 });
        visited[start[0]][start[1]] = true;

        if (start[0] == dest[0] && start[1] == dest[1]) {
            return 0;
        }

        loop:
        while (!q.isEmpty()) {
            current = q.element();
            q.poll();

            for (int i = 0; i < 8; i++) {
                next[0] = current[0] + d[i][0];
                next[1] = current[1] + d[i][1];

                if (next[0] < 0 || next[0] > size - 1 || next[1] < 0 || next[1] > size - 1 || visited[next[0]][next[1]]) {
                    continue;
                }

                q.add(new int[] { next[0], next[1], current[2] + 1 });
                count = current[2] + 1;
                visited[next[0]][next[1]] = true;
                if (next[0] == dest[0] && next[1] == dest[1]) {
                    break loop;
                }
            }
        }

        return count;
    }
}
