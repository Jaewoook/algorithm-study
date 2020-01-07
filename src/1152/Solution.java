import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine().trim();

        System.out.println(line.length() == 0 ? 0 : !line.contains(" ") ? 1 : line.split(" ").length);
    }
}
