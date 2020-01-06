import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        float[] scores = new float[n];
        float max = 0;

        for (int i = 0; i < n; i++) {
            scores[i] = scanner.nextFloat();
            max = Math.max(scores[i], max);
        }
        scanner.nextLine();

        float sum = 0;
        for (int i = 0; i < n; i++) {
            scores[i] = scores[i] / max * 100;
            sum += scores[i];
        }

        System.out.println(sum / n);
    }
}
