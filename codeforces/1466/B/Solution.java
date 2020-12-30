import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer token = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(token.nextToken());
        int N, d;
        int[] arr;
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            token = new StringTokenizer(br.readLine());
            arr = new int[N];
            arr[0] = Integer.parseInt(token.nextToken());
            d = 1;
            int i = 1;
            for (i = 1; i < N; i++) {
                arr[i] = Integer.parseInt(token.nextToken());
                if (arr[i - 1] != arr[i]) {
                    d++;
                    if (i - 2 >= 0 && arr[i - 1] == arr[i - 2]) {
                        arr[i - 1]++;
                        if (arr[i - 1] != arr[i]) {
                            d++;
                        }
                    }
                }
            }
            i--;
            if (i - 1 >= 0 && arr[i] == arr[i - 1]) {
                d++;
            }
            bw.write(d + "\n");
        }

        bw.flush();
        bw.close();
    }
}
