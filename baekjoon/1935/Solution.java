import java.util.Scanner;
import java.util.Stack;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Stack<Double> s = new Stack<>();
        int size = scanner.nextInt();
        double[] values = new double[size];
        String expression = scanner.next();
        for (int i = 0; i < size; i++) {
            values[i] = scanner.nextDouble();
        }

        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (isOperator(c)) {
                double arg2 = s.pop();
                double arg1 = s.pop();

                if (c == '+') {
                    arg1 += arg2;
                } else if (c == '-') {
                    arg1 -= arg2;
                } else if (c == '*') {
                    arg1 *= arg2;
                } else {
                    arg1 /= arg2;
                }
                s.push(arg1);
            } else {
                s.push(values[c - 'A']);
            }
        }

        System.out.printf("%.2f", s.pop());
    }

    static boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
}
