import java.util.Scanner;

interface Sports
{
    double spwt = 6.5;
}

class Student
{
    int rollno;
    void getRollNo(int r)
    {
        rollno = r;
    }
    void putRollNo()
    {
        System.out.println("Roll Number: " + rollno);
    }
}

class Test extends Student
{
    double mark1, mark2;
    void getMarks(double m1, double m2)
    {
        mark1 = m1;
        mark2 = m2;
    }
    void putMarks()
    {
        System.out.println("Mark 1: " + mark1);
        System.out.println("Mark 2: " + mark2);
    }
}

class Score extends Test implements Sports
{
    double total;
    void display()
    {
        total = mark1+mark2+spwt;
        putRollNo();
        putMarks();
        System.out.println("Sports Weightage: "+spwt);
        System.out.println("Total Score: "+total);
    }
}

public class q12_ScoreCalculation
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        Score s = new Score();

        System.out.print("Enter Roll Number: ");
        int roll = sc.nextInt();
        s.getRollNo(roll);

        System.out.print("Enter Mark for Subject 1: ");
        double m1 = sc.nextDouble();
        System.out.print("Enter Mark for Subject 2: ");
        double m2 = sc.nextDouble();
        s.getMarks(m1,m2);
        System.out.println("\n---Student Score Details---");
        s.display();
        sc.close();
    }
}
