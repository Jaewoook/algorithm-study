import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] ox = new String[n];

        for (int i = 0; i < n; i++) {
            ox[i] = scanner.nextLine();
            int len = ox[i].length();
            int score = 0;
            int sum = 0;
            for (int j = 0; j < len; j++) {
                score = ox[i].charAt(j) == 'O' ? score + 1 : 0;
                sum += score;
            }
            System.out.println(sum);
        }
    }
}
