import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Generator {

    public void generate(int limit) {
        int n1 = 0,
            n2 = 1;

        for (int i = 1; i <= limit; ++i) {
            System.out.print(n1 + " ");

            int sum = n1 + n2;
            n1 = n2;
            n2 = sum;
        }
        System.out.println();
    }
}

public class q2_Fibonacci {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(
            new InputStreamReader(System.in)
        );
        System.out.print("Enter the limit for the Fibonacci series: ");
        String input = reader.readLine();
        int limit = Integer.parseInt(input);

        Generator fibGenerator = new Generator();
        fibGenerator.generate(limit);
    }
}
