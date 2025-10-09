import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class q19_SwingCalculator extends JFrame implements ActionListener {

    // Declare components
    JTextField num1Field, num2Field, resultField;
    JButton addButton, subButton, mulButton, divButton, clearButton;

    // Constructor
    q19_SwingCalculator() {
        setTitle("Arithmetic Calculator");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(6, 2, 10, 10)); // rows, cols, hgap, vgap

        // Create components
        JLabel num1Label = new JLabel("Enter First Number:");
        JLabel num2Label = new JLabel("Enter Second Number:");
        JLabel resultLabel = new JLabel("Result:");

        num1Field = new JTextField();
        num2Field = new JTextField();
        resultField = new JTextField();
        resultField.setEditable(false); // user can’t type here

        addButton = new JButton("Add (+)");
        subButton = new JButton("Subtract (-)");
        mulButton = new JButton("Multiply (×)");
        divButton = new JButton("Divide (÷)");
        clearButton = new JButton("Clear");

        // Add components to frame
        add(num1Label); add(num1Field);
        add(num2Label); add(num2Field);
        add(resultLabel); add(resultField);

        add(addButton);
        add(subButton);
        add(mulButton);
        add(divButton);
        add(clearButton);

        // Register listeners
        addButton.addActionListener(this);
        subButton.addActionListener(this);
        mulButton.addActionListener(this);
        divButton.addActionListener(this);
        clearButton.addActionListener(this);

        // Center the window
        setLocationRelativeTo(null);
        setVisible(true);
    }

    // Perform actions
    public void actionPerformed(ActionEvent e) {
        try {
            double num1 = Double.parseDouble(num1Field.getText());
            double num2 = Double.parseDouble(num2Field.getText());
            double result = 0;

            if (e.getSource() == addButton)
                result = num1 + num2;
            else if (e.getSource() == subButton)
                result = num1 - num2;
            else if (e.getSource() == mulButton)
                result = num1 * num2;
            else if (e.getSource() == divButton) {
                if (num2 == 0)
                    throw new ArithmeticException("Cannot divide by zero");
                result = num1 / num2;
            } else if (e.getSource() == clearButton) {
                num1Field.setText("");
                num2Field.setText("");
                resultField.setText("");
                return;
            }

            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter valid numbers!");
        } catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }

    // Main method
    public static void main(String[] args) {
        new q19_SwingCalculator();
    }
}
