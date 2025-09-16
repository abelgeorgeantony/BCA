import java.util.Scanner;

class Room {

    float length;
    float breadth;

    float area() {
        return (float) (length * breadth);
    }
}

class Bedroom extends Room {

    float height;

    float volume() {
        return (float) (length * breadth * height);
    }
}

public class q7_SingleInheritance {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Bedroom bedroom = new Bedroom();
        System.out.println("Enter length of the room:");
        bedroom.length = scan.nextFloat();
        System.out.println("Enter breadth of the room:");
        bedroom.breadth = scan.nextFloat();
        System.out.println("Enter height of the room:");
        bedroom.height = scan.nextFloat();

        System.out.println("Area of the room: " + bedroom.area());
        System.out.println("Volume of the bedroom: " + bedroom.volume());
    }
}
