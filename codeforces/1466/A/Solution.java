import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(token.nextToken());
        int N, d;
        ArrayList<Integer> result = new ArrayList<>();
        int[] arr;
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            token = new StringTokenizer(br.readLine());
            arr = new int[N];
            result.clear();
            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(token.nextToken());
            }
            for (int i = 0; i < N - 1; i++) {
                for (int j = i + 1; j < N; j++) {
                    if (i == j) continue;
                    d = arr[j] - arr[i];
                    if (result.indexOf(d) == -1) {
                        result.add(d);
                    }
                }
            }
            bw.write(result.size() + "\n");
        }

        bw.flush();
        bw.close();
    }
}
