import java.util.Scanner;

class ShapeCalculator {

    // Method to calculate area of a square
    public double calculateArea(double side) {
        return side * side;
    }

    // Method to calculate area of a rectangle
    public double calculateArea(double length, double breadth) {
        return length * breadth;
    }

    // Method to calculate perimeter of a square
    public double calculatePerimeter(double side) {
        return 4 * side;
    }

    // Method to calculate perimeter of a rectangle
    public double calculatePerimeter(double length, double breadth) {
        return 2 * (length + breadth);
    }
}

public class q03_MethodOverloading {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ShapeCalculator calculator = new ShapeCalculator();

        System.out.println("Choose a shape:");
        System.out.println("1. Square");
        System.out.println("2. Rectangle");
        int choice = sc.nextInt();

        if (choice == 1) {
            System.out.print("Enter the side of the square: ");
            double side = sc.nextDouble();
            System.out.println(
                "Area of the square: " + calculator.calculateArea(side)
            );
            System.out.println(
                "Perimeter of the square: " +
                calculator.calculatePerimeter(side)
            );
        } else if (choice == 2) {
            System.out.print("Enter the length of the rectangle: ");
            double length = sc.nextDouble();
            System.out.print("Enter the breadth of the rectangle: ");
            double breadth = sc.nextDouble();
            System.out.println(
                "Area of the rectangle: " +
                calculator.calculateArea(length, breadth)
            );
            System.out.println(
                "Perimeter of the rectangle: " +
                calculator.calculatePerimeter(length, breadth)
            );
        } else {
            System.out.println("Invalid choice.");
        }

        sc.close();
    }
}
