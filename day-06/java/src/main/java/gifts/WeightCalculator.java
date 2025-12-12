package gifts;

public class WeightCalculator {
    public static double averageWeight(int w[], int l) {
        int s = 0;
        for (int i = 0; i < l; i++) {
            s += w[i];
        }
        return s / l;
    }
}