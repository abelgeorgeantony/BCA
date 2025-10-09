import java.util.Scanner;

// Parent class
class Bank {
    double getRateOfInterest() {
        return 0.0; // default rate
    }
}

// Child classes overriding method
class SBI extends Bank {
    double getRateOfInterest() {
        return 8.0;
    }
}

class ICICI extends Bank {
    double getRateOfInterest() {
        return 7.0;
    }
}

class AXIS extends Bank {
    double getRateOfInterest() {
        return 9.0;
    }
}

public class q09_MethodOverriding {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Choose Bank:");
        System.out.println("1. SBI");
        System.out.println("2. ICICI");
        System.out.println("3. AXIS");
        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();

        Bank b; // reference of parent

        switch (choice) {
            case 1:
                b = new SBI();
                break;
            case 2:
                b = new ICICI();
                break;
            case 3:
                b = new AXIS();
                break;
            default:
                System.out.println("Invalid choice!");
                sc.close();
                return;
        }

        // Method overriding in action
        System.out.println("Rate of Interest: " + b.getRateOfInterest() + "%");

        sc.close();
    }
}
