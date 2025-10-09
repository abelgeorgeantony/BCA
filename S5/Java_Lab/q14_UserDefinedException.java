import java.util.Scanner;

class FirstLessThanSecondException extends Exception
{
    public FirstLessThanSecondException(String message)
    {
        super(message);
    }
}

public class q14_UserDefinedException
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        try
        {
            System.out.print("Enter the first number: ");
            int num1 = sc.nextInt();
            System.out.print("Enter the second number: ");
            int num2 = sc.nextInt();
            if(num1 < num2)
            {
                throw new FirstLessThanSecondException("Error: First number is less than the second number.");
            }
            int sum = num1+ num2;
            System.out.println("Sum of the two numbers: "+sum);
        }
        catch(FirstLessThanSecondException e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            sc.close();
        }
    }
}
