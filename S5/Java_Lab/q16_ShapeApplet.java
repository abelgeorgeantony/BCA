import java.applet.Applet;
import java.awt.*;

/*
<applet code="q16_ShapeApplet" width=400 height=400>
  <param name="rectX" value="50">
  <param name="rectY" value="50">
  <param name="rectWidth" value="150">
  <param name="rectHeight" value="100">
  <param name="circleX" value="250">
  <param name="circleY" value="100">
  <param name="circleRadius" value="60">
</applet>
*/

public class q16_ShapeApplet extends Applet
{
    int rectX, rectY, rectWidth, rectHeight;
    int circleX, circleY, circleRadius;

    public void init()
    {
        rectX = Integer.parseInt(getParameter("rectX"));
        rectY = Integer.parseInt(getParameter("rectY"));
        rectWidth = Integer.parseInt(getParameter("rectWidth"));
        rectHeight = Integer.parseInt(getParameter("rectHeight"));

        circleX = Integer.parseInt(getParameter("circleX"));
        circleY = Integer.parseInt(getParameter("circleY"));
        circleRadius = Integer.parseInt(getParameter("circleRadius"));
    }

    public void paint(Graphics g)
    {
        g.setColor(Color.blue);
        g.drawRect(rectX, rectY, rectWidth, rectHeight);

        g.setColor(Color.red);
        g.drawOval(circleX, circleY, circleRadius, circleRadius);
    }
}
