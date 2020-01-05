import java.util.Arrays;
import java.util.Scanner;

class Study {
    public static void main(String args[]) {
        int n, m, cardNum[], sum = 0;

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        scanner.nextLine();

        cardNum = new int[n];
        for (int i = 0; i < n; i++) {
            cardNum[i] = scanner.nextInt();
        }
        scanner.nextLine();

        Arrays.sort(cardNum);

        for (int i = cardNum.length - 1; i >= 2; i--) {
            if (cardNum[i] >= m) {
                //  다른 카드 찾음
                continue;
            }

            for (int j = i - 1; j >= 1; j--) {
                int twoCards = cardNum[i] + cardNum[j];
                if (twoCards < m) {
                    for (int k = j - 1; k >= 0; k--) {
                        int threeCards = twoCards + cardNum[k];
                        if (threeCards <= m) {
                            sum = Math.max(threeCards, sum);
                        }
                    }
                }
            }
        }

        System.out.println(sum);
    }
}