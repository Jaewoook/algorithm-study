import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        int count = 0;
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();

            int len = s.length();
            int groupStartAt = -1;
            boolean grouped = true;
            for (int j = 0; j < len; j++) {
                char c = s.charAt(j);
                if (groupStartAt < 0) {
                    groupStartAt = j;
                } else if (s.indexOf(c) < groupStartAt) {
                    groupStartAt = -2;
                } else if (s.charAt(groupStartAt) != c) {
                    groupStartAt = j;
                }
                if (groupStartAt == -2) {
                    grouped = false;
                    break;
                }
            }
            if (grouped) {
                count++;
            }
        }
        System.out.println(count);
    }
}
