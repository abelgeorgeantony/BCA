import java.util.Scanner;

class OddThread extends Thread
{
    private int limit;
    public OddThread(int limit)
    {
        this.limit = limit;
    }

    @Override
    public void run()
    {
        System.out.println("Odd numbers:");
        for(int i = 1; i <= limit; i+=2)
        {
            System.out.println(i);
            try
            {
                Thread.sleep(500);
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

class EvenThread extends Thread
{
    private int limit;
    public EvenThread(int limit)
    {
        this.limit = limit;
    }

    @Override
    public void run()
    {
        System.out.println("Even numbers:");
        for(int i = 2; i <= limit; i+=2)
        {
            System.out.println(i);
            try
            {
                Thread.sleep(500);
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

public class q15_OddEvenThreads
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the limit: ");
        int limit = sc.nextInt();

        OddThread odd = new OddThread(limit);
        EvenThread even = new EvenThread(limit);
        odd.start();
        even.start();
    }
}
