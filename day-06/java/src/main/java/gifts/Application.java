package gifts;

import static gifts.WeightCalculator.averageWeight;

public class Application {
    public static void main(String[] args) {
        int[] weights1 = {2, 5, 7, 10};
        int[] weights2 = {2};

        System.out.printf("Average weight for 4 gifts: %.2f%n", averageWeight(weights1, 4));
        System.out.printf("Average weight for 1 gift: %.2f%n", averageWeight(weights2, 1));
    }
}
