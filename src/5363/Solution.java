import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String lang[] = scanner.nextLine().split(" ");
            shift(lang, 2);
            System.out.println(String.join(" ", lang));
        }
    }

    static String[] shift(String[] arr, int move) {
        int len = arr.length;
        String tmp = arr[0];
        for (int i = 1; i < len; i++) {
            arr[i - 1] = arr[i];
        }
        arr[len - 1] = tmp;

        if (move > 1) {
            return shift(arr, move - 1);
        } else {
            return arr;
        }
    }
}
