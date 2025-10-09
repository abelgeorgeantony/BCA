import java.io.*;
import java.util.Scanner;

interface Shape {
  public void calculateArea();
}

class Circle implements Shape {
  public static final double PI = 3.14159;
  float radius;
  Circle() {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter radius of circle:");
    radius = scan.nextFloat();
  }
  public void calculateArea() {
    System.out.println("Area of circle: " + (PI*(radius*radius)));
  }
}

public class q11_ShapeInterface {
  public static void main(String[] args) {
    Circle c1 = new Circle();
    c1.calculateArea();
  }
}
