import java.util.Scanner;
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] num = {0, 0, 0};

        num[0] = scanner.nextInt();
        num[1] = scanner.nextInt();
        num[2] = scanner.nextInt();

        scanner.nextLine();

        Arrays.sort(num);

        System.out.println(num[1]);
    }
}
