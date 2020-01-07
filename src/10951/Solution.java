import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String in = scanner.nextLine();
            String n[] = in.split(" ");
            System.out.println(Integer.parseInt(n[0]) + Integer.parseInt(n[1]));
        }
    }
}
