import java.io.DataInputStream;
import java.io.IOException;

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

public class q02_Fibonacci {

    public static void main(String[] args) throws IOException {
        DataInputStream dis = new DataInputStream(System.in);
        System.out.print("Enter the limit for the Fibonacci series: ");
        String input = dis.readLine();
        int limit = Integer.parseInt(input);

        Generator fibGenerator = new Generator();
        fibGenerator.generate(limit);
    }
}
