import java.applet.Applet;
import java.awt.*;

/* <applet code="q18b_TrafficLight" width=200 height=400></applet> */

public class q18b_TrafficLight extends Applet {
    public void paint(Graphics g) {
        // outline box
        g.setColor(Color.black);
        g.drawRect(50, 50, 100, 260);

        // red light
        g.setColor(Color.red);
        g.fillOval(75, 70, 50, 50);

        // yellow light
        g.setColor(Color.yellow);
        g.fillOval(75, 140, 50, 50);

        // green light
        g.setColor(Color.green);
        g.fillOval(75, 210, 50, 50);
    }
}
