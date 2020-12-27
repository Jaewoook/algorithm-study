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
        //  S G P D
        int[] grades = new int[5];
        for (int i = 0; i < 4; i++) {
            grades[i] = Integer.parseInt(token.nextToken());
        }
        String line = br.readLine();
        int[] purchased = new int[N + 1];
        int sum = 0;
        for (int i = 0; i < line.length(); i++) {
            switch (line.charAt(i)) {
                case 'B':
                purchased[i + 1] = grades[0] - purchased[i] - 1;
                break;
                case 'S':
                purchased[i + 1] = grades[1] - purchased[i] - 1;
                break;
                case 'G':
                purchased[i + 1] = grades[2] - purchased[i] - 1;
                break;
                case 'P':
                purchased[i + 1] = grades[3] - purchased[i] - 1;
                break;
                case 'D':
                purchased[i + 1] = grades[3];
                break;
            }
            sum += purchased[i + 1];
        }

        bw.write(sum + "\n");
        bw.flush();
        bw.close();
    }
}
