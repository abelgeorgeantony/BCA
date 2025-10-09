import java.applet.Applet;
import java.awt.*;

/* <applet code="q18a_OlympicsLogo" width=500 height=300></applet> */

public class q18a_OlympicsLogo extends Applet {
    public void paint(Graphics g) {
        // set stroke width
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(4));

        // draw circles with colors
        g.setColor(Color.blue);
        g.drawOval(50, 100, 80, 80);

        g.setColor(Color.black);
        g.drawOval(150, 100, 80, 80);

        g.setColor(Color.red);
        g.drawOval(250, 100, 80, 80);

        g.setColor(Color.yellow);
        g.drawOval(100, 140, 80, 80);

        g.setColor(Color.green);
        g.drawOval(200, 140, 80, 80);
    }
}
