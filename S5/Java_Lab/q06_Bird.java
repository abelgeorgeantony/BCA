import java.util.Scanner;

// Program: Constructor Overloading Example with Scanner
// Aim: Write a program in JAVA to create a class Bird and 
//      declare different parameterized constructors to display the name of Birds.

class Bird {
    String name;
    String color;
    String type;

    // Constructor 1 - only name
    Bird(String name) {
        this.name = name;
        System.out.println("Bird Name: " + name);
    }

    // Constructor 2 - name and color
    Bird(String name, String color) {
        this.name = name;
        this.color = color;
        System.out.println("Bird Name: " + name + ", Color: " + color);
    }

    // Constructor 3 - name, color and age
    Bird(String name, String color, String type) {
        this.name = name;
        this.color = color;
        this.type = type;
        System.out.println("Bird Name: " + name + ", Color: " + color + ", Bird Type: " + type );
    }
}

public class q06_Bird {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Using first constructor
        System.out.print("Enter bird name: ");
        String name1 = sc.nextLine();
        Bird b1 = new Bird(name1);

        // Using second constructor
        System.out.print("Enter bird name: ");
        String name2 = sc.nextLine();
        System.out.print("Enter bird color: ");
        String color2 = sc.nextLine();
        Bird b2 = new Bird(name2, color2);

        // Using third constructor
        System.out.print("Enter bird name: ");
        String name3 = sc.nextLine();
        System.out.print("Enter bird color: ");
        String color3 = sc.nextLine();
        System.out.print("Enter bird type: ");
        String type3 = sc.nextLine();
        Bird b3 = new Bird(name3, color3, type3);

        sc.close();
    }
}
