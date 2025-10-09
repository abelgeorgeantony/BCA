import java.util.Scanner;

class Student {

    int id;
    String name;

    // Parameterized constructor
    public Student(int id, String name) {
        System.out.println("Constructor called for object with id: " + id);
        this.id = id;
        this.name = name;
    }

    void display() {
        System.out.println("ID: " + id + ", Name: " + name);
    }
}

public class q05_ConstructorExample {

    public static void main(String[] args) {
        // Creating objects and passing arguments to the constructor
        Student obj1 = new Student(101, "Alice");
        Student obj2 = new Student(102, "Bob");

        System.out.println("\nDisplaying details of obj1:");
        obj1.display();

        System.out.println("\nDisplaying details of obj2:");
        obj2.display();
    }
}
