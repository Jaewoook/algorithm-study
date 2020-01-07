import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        int num3 = scanner.nextInt();
        scanner.nextLine();

        long result = num1 * num2 * num3;
        int count[] = new int[10];

        for (long i = result; i > 0; i /= 10) {
            count[(int) i % 10]++;
        }
        for (int n : count) {
            System.out.println(n);
        }
    }
}
