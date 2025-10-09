import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/* 
<applet code="q17_FaceApplet" width=400 height=400>
</applet>
*/

public class q17_FaceApplet extends Applet implements ActionListener {
    Button happyBtn, sadBtn;
    String mood = ""; // to track which face to draw

    public void init() {
        happyBtn = new Button("Funny Face");
        sadBtn = new Button("Sad Face");

        add(happyBtn);
        add(sadBtn);

        happyBtn.addActionListener(this);
        sadBtn.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == happyBtn) {
            mood = "happy";
        } else if (e.getSource() == sadBtn) {
            mood = "sad";
        }
        repaint();
    }

    public void paint(Graphics g) {
        g.drawRect(0, 0, getWidth() - 1, getHeight() - 1);

        if (mood.equals("happy")) {
            // Face
            g.drawOval(100, 100, 200, 200);
            // Eyes
            g.fillOval(150, 150, 20, 20);
            g.fillOval(230, 150, 20, 20);
            // Smile
            g.drawArc(150, 180, 100, 50, 0, -180);
        } 
        else if (mood.equals("sad")) {
            // Face
            g.drawOval(100, 100, 200, 200);
            // Eyes
            g.fillOval(150, 150, 20, 20);
            g.fillOval(230, 150, 20, 20);
            // Sad mouth
            g.drawArc(150, 200, 100, 50, 0, 180);
        }
    }
}
