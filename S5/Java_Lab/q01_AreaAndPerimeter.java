import java.io.*;
import java.util.Scanner;

class Area {

    int area;

    public Area(int side) {
        area = side * side;
    }

    public Area(int len, int bre) {
        area = len * bre;
    }
}

class Perimeter {

    int perimeter;

    public Perimeter(int side) {
        perimeter = 4 * side;
    }

    public Perimeter(int len, int bre) {
        perimeter = (2 * (len + bre));
    }
}

public class q01_AreaAndPerimeter {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter choice: ");
        System.out.println("1) Area:\n2) Perimeter\n");
        int choice = sc.nextInt();
        if (choice == 1) {
            System.out.println("Select shape: ");
            System.out.println("1) Square:\n2) Rectangle\n");
            choice = sc.nextInt();
            if (choice == 1) {
                System.out.println("Enter length of side:");
                int side = sc.nextInt();
                Area aobj = new Area(side);
                System.out.println("Area of Square: " + aobj.area);
            } else if (choice == 2) {
                System.out.println("Enter length and bredth:");
                int len = sc.nextInt();
                int bre = sc.nextInt();
                Area aobj = new Area(len, bre);
                System.out.println("Area of Rectangle: " + aobj.area);
            }
        } else if (choice == 2) {
            System.out.println("Select shape: ");
            System.out.println("1) Square:\n2) Rectangle\n");
            choice = sc.nextInt();
            if (choice == 1) {
                System.out.println("Enter length of side:");
                int side = sc.nextInt();
                Perimeter pobj = new Perimeter(side);
                System.out.println("Perimeter of Square: " + pobj.perimeter);
            } else if (choice == 2) {
                System.out.println("Enter length and bredth:");
                int len = sc.nextInt();
                int bre = sc.nextInt();
                Perimeter pobj = new Perimeter(len, bre);
                System.out.println("Perimeter of Rectangle: " + pobj.perimeter);
            }
        }

        sc.close();
    }
}
