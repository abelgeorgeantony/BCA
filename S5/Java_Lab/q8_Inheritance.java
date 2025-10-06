import java.io.*;
import java.util.Scanner;

class Student {
  String name;
  int roll_no;
}

class Exam extends Student {
  float marks[] = new float[6];
  void ReadMarks() {
    Scanner scan = new Scanner(System.in);
    for(int i = 0; i < 6; i++) {
      System.out.println("Enter mark of " + (i+1) + "th subject: ");
      marks[i] = scan.nextFloat();
    }
  }
  float Sum() {
    float total = 0;
    for(int i = 0; i < 6; i++) {
      total = total + marks[i];
    }
    return total;
  }
}

class Result extends Exam {
  float total_marks;
  Result() {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter name: ");
    name = scan.nextLine();
    System.out.println("Enter Roll number: ");
    roll_no = scan.nextInt();
    ReadMarks();
    total_marks = Sum();
  }
  void Display() {
    System.out.println("Name: " + name);
    System.out.println("Roll Number: " + roll_no);
    System.out.println("Total Marks: " + total_marks);
  }
}


public class q8_Inheritance {
  public static void main(String args[]) {
    Result resobj = new Result();
    resobj.Display();
  }
}
