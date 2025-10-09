import q13_Package.*;

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

        Addition aob = new Addition();
        Subtraction sob = new Subtraction();
        Multiplication mob = new Multiplication();
        Division dob = new Division();

        System.out.println("Addition: " + aob.add(x,y));
        System.out.println("Subtraction: " + sob.sub(x,y));
        System.out.println("Multiplication: " + mob.mul(x,y));
        System.out.println("Division: " + dob.div(x,y));
        sc.close();

    }
}
