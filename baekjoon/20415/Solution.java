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
        StringTokenizer token = null;

        int N = Integer.parseInt(br.readLine());
        token = new StringTokenizer(br.readLine());
        int[] grades = new int[4];
        for (int i = 0; i < 4; i++) {
            grades[i] = Integer.parseInt(token.nextToken());
        }
        String line = br.readLine();
        int[] purchased = new int[N + 1];
        int sum = 0;
        for (int i = 1; i < N + 1; i++) {
            switch (line.charAt(i - 1)) {
                case 'B':
                purchased[i] = grades[0] - 1 - purchased[i - 1];
                if (purchased[i] < 0) purchased[i] = 0;
                if (purchased[i] + purchased[i - 1] >= grades[0]) {
                    sum += grades[0] -1 - purchased[i - 1];
                }
                break;
                case 'S':
                purchased[i] = grades[1] - 1 - purchased[i - 1];
                if (purchased[i] < 0) purchased[i] = 0;
                if (purchased[i] + purchased[i - 1] >= grades[1]) {
                    sum += grades[1] -1 - purchased[i - 1];
                }
                break;
                case 'G':
                purchased[i] = grades[2] - 1 - purchased[i - 1];
                if (purchased[i] < 0) purchased[i] = 0;
                if (purchased[i] + purchased[i - 1] >= grades[2]) {
                    sum += grades[2] -1 - purchased[i - 1];
                }
                break;
                case 'P':
                purchased[i] = grades[3] - 1 - purchased[i- 1];
                if (purchased[i] < 0) purchased[i] = 0;
                if (purchased[i] + purchased[i - 1] >= grades[3]) {
                    sum += grades[3] -1 - purchased[i - 1];
                }
                break;
                case 'D':
                purchased[i] = grades[3];
                break;
            }
            sum += purchased[i];
        }

        bw.write(sum + "\n");
        bw.flush();
        bw.close();
    }
}
