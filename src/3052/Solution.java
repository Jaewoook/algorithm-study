import java.util.Scanner;
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num[] = new int[10];

        for (int i = 0; i < 10; i++) {
            num[i] = scanner.nextInt() % 42;
        }
        Arrays.sort(num);

        int count = 0, prev = 0;
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                count++;
            } else {
                count = prev != num[i] ? count + 1 : count;
            }
            prev = num[i];
        }
        System.out.println(count);
    }
}
