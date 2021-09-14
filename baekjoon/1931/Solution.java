import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()), end = 0, count = 0;
        StringTokenizer tokenizer;
        int[][] times = new int[n][2];
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(br.readLine());
            times[i][0] = Integer.parseInt(tokenizer.nextToken());
            times[i][1] = Integer.parseInt(tokenizer.nextToken());
        }

        Arrays.sort(times, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b) {
                if (a[1] < b[1]) {
                    return -1;
                } else if (a[1] == b[1]) {
                    return a[0] < b[0] ? -1 : 1;
                } else {
                    return 1;
                }
            }
        });
        for (int i = 0; i < n; i++) {
            if (end <= times[i][0]) {
                end = times[i][1];
                count++;
            }
        }

        System.out.println(count);
    }

}
