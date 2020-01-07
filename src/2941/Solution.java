import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String presets[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

        for (int i = 0; i < 100; i++) {
            for (String s : presets) {
                if (input.contains(s)) {
                    input = input.replace(s, "0");
                }
            }
        }
        System.out.println(input.length());
    }
}
