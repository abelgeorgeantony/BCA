import q13_Package.Operations;

import java.util.Scanner;

public class q13_ArithOperation
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int x = sc.nextInt();

        System.out.print("Enter second number: ");
        int y = sc.nextInt();

        Operations op = new Operations();

        System.out.println("Addition: " + op.add(x,y));
        System.out.println("Subtraction: " + op.sub(x,y));
        System.out.println("Multiplication: " + op.mul(x,y));
        System.out.println("Division: " + op.div(x,y));
        sc.close();

    }
}
