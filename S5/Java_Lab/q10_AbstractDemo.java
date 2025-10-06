import java.io.*;
abstract class Vehicle {
  abstract void engine();
}

class Car extends Vehicle {
  void engine(){
    System.out.println("Car has good engine!");
  }
}

class Truck extends Vehicle {
  void engine(){
    System.out.println("Truck has bad engine!");
  }
}

public class q10_AbstractDemo {
  public static void main(String[] args) {
    Vehicle v;
    v = new Car();
    v.engine();
    v = new Truck();
    v.engine();
  }
}
