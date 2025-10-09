import java.util.Scanner;

class ArithmeticOperations {

    // Add two integers, return float
    public float add(int a, int b) {
        return (float) (a + b);
    }

    // Add two floats, return int
    public int add(float a, float b) {
        return (int) (a + b);
    }

    // Subtract two integers, return float
    public float subtract(int a, int b) {
        return (float) (a - b);
    }

    // Subtract two floats, return int
    public int subtract(float a, float b) {
        return (int) (a - b);
    }

    // Multiply two integers, return float
    public float multiply(int a, int b) {
        return (float) (a * b);
    }

    // Multiply two floats, return int
    public int multiply(float a, float b) {
        return (int) (a * b);
    }

    // Divide two integers, return float
    public float divide(int a, int b) {
        if (b == 0) {
            System.out.println("Error: Division by zero.");
            return 0.0f;
        }
        return (float) a / b;
    }

    // Divide two floats, return int
    public int divide(float a, float b) {
        if (b == 0.0f) {
            System.out.println("Error: Division by zero.");
            return 0;
        }
        return (int) (a / b);
    }
}

public class q04_ArithmeticOverloading {

    public static void main(String[] args) {
        ArithmeticOperations ao = new ArithmeticOperations();
        Scanner sc = new Scanner(System.in);

        System.out.println(
            "Performing operations on two integers (returns float):"
        );
        System.out.print("Enter two integers: ");
        int i1 = sc.nextInt();
        int i2 = sc.nextInt();
        System.out.println("Addition: " + ao.add(i1, i2));
        System.out.println("Subtraction: " + ao.subtract(i1, i2));
        System.out.println("Multiplication: " + ao.multiply(i1, i2));
        System.out.println("Division: " + ao.divide(i1, i2));

        System.out.println(
            "\nPerforming operations on two floats (returns int):"
        );
        System.out.print("Enter two float values: ");
        float f1 = sc.nextFloat();
        float f2 = sc.nextFloat();
        System.out.println("Addition: " + ao.add(f1, f2));
        System.out.println("Subtraction: " + ao.subtract(f1, f2));
        System.out.println("Multiplication: " + ao.multiply(f1, f2));
        System.out.println("Division: " + ao.divide(f1, f2));

        sc.close();
    }
}
