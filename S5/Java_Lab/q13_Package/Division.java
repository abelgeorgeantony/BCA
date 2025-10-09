package q13_Package;

public class Division
{
    public int div(int a, int b)
    {
        if(b==0)
        {
            System.out.println("Error: Division by zero!");
            return 0;
        }
        return (a+b);
    }
}
