import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < cases; i++) {
            int num = scanner.nextInt();
            int[] scores = new int[num];
            int sum = 0;
            float avg = 0f;
            for (int j = 0; j < num; j++) {
                scores[j] = scanner.nextInt();
                sum += scores[j];
            }
            scanner.nextLine();

            avg = (float) sum / num;
            int good = 0;
            for (int score : scores) {
                good = score > avg ? good + 1 : good;
            }
            System.out.println(String.format("%.3f", Math.round((float) good / num * 100000) / 1000f) + "%");
        }
    }
}
