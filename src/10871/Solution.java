import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        scanner.nextLine();

        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = scanner.nextInt();
        }
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            if (num[i] < x) {
                System.out.print(num[i] + " ");
            }
        }
    }
}
