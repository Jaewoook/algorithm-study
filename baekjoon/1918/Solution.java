import java.util.Scanner;
import java.util.Stack;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<Character> stack = new Stack<>();
        stack.push(' ');

        String infixExpression = scanner.nextLine();
        for (int i = 0; i < infixExpression.length(); i++) {
            char c = infixExpression.charAt(i);
            int priority = getOperatorPriority(c);

            if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                while (stack.peek() != '(') {
                    System.out.print(stack.pop());
                }
                stack.pop();
            } else if (priority < 0) {
                System.out.print(c);
            } else if (priority > getOperatorPriority(stack.peek())) {
                stack.push(c);
            } else {
                while (priority <= getOperatorPriority(stack.peek())) {
                    System.out.print(stack.pop());
                }
                stack.push(c);
            }
        }

        while (stack.peek() != ' ') {
            System.out.print(stack.pop());
        }
    }

    static int getOperatorPriority(char c) {
        switch (c) {
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return -1;
        }
    }

}
