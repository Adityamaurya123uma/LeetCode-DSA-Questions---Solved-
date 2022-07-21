class Pen {
    String color;

    public void printrang() {
        System.out.println("The color of this Pen is " + this.color);
    }
}

public class OOPS {
    public static void main(String args[]) {
        Pen p1 = new Pen();
        p1.color = "blue";

        Pen p2 = new Pen();
        p2.color = "black";

        Pen p3 = new Pen();
        p3.color = "red";

        p3.printrang();
        p1.printrang();
        p2.printrang();
    }
}
