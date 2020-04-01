import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        double price[] = {350.34, 230.90, 190.55, 125.30, 180.90};
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += price[j] * scanner.nextInt();
            }
            scanner.nextLine();
            System.out.println("$" + String.format("%.2f", sum));
        }
    }
}
