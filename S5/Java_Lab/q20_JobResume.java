import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class q20_JobResume extends JFrame implements ActionListener {
    // Components
    JLabel nameLabel, ageLabel, genderLabel, qualLabel, skillsLabel;
    JTextField nameField, ageField, skillsField;
    JComboBox<String> qualBox;
    JRadioButton maleBtn, femaleBtn;
    JButton submitBtn, clearBtn;
    JTextArea outputArea;
    ButtonGroup genderGroup;

    // Constructor
    q20_JobResume() {
        setTitle("Job Resume Form");
        setSize(500, 600);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setBackground(new Color(245, 245, 245));

        // Labels
        nameLabel = new JLabel("Name:");
        nameLabel.setBounds(50, 40, 150, 25);
        add(nameLabel);

        ageLabel = new JLabel("Age:");
        ageLabel.setBounds(50, 80, 150, 25);
        add(ageLabel);

        genderLabel = new JLabel("Gender:");
        genderLabel.setBounds(50, 120, 150, 25);
        add(genderLabel);

        qualLabel = new JLabel("Qualification:");
        qualLabel.setBounds(50, 160, 150, 25);
        add(qualLabel);

        skillsLabel = new JLabel("Skills:");
        skillsLabel.setBounds(50, 200, 150, 25);
        add(skillsLabel);

        // Text Fields
        nameField = new JTextField();
        nameField.setBounds(180, 40, 200, 25);
        add(nameField);

        ageField = new JTextField();
        ageField.setBounds(180, 80, 200, 25);
        add(ageField);

        // Gender Radio Buttons
        maleBtn = new JRadioButton("Male");
        maleBtn.setBounds(180, 120, 70, 25);
        femaleBtn = new JRadioButton("Female");
        femaleBtn.setBounds(250, 120, 100, 25);
        genderGroup = new ButtonGroup();
        genderGroup.add(maleBtn);
        genderGroup.add(femaleBtn);
        add(maleBtn);
        add(femaleBtn);

        // Qualification ComboBox
        String[] qualifications = {"BCA", "B.Sc", "B.Tech", "MCA", "MBA", "Other"};
        qualBox = new JComboBox<>(qualifications);
        qualBox.setBounds(180, 160, 200, 25);
        add(qualBox);

        // Skills Text Field
        skillsField = new JTextField();
        skillsField.setBounds(180, 200, 200, 25);
        add(skillsField);

        // Submit and Clear Buttons
        submitBtn = new JButton("Submit");
        submitBtn.setBounds(120, 250, 100, 30);
        clearBtn = new JButton("Clear");
        clearBtn.setBounds(250, 250, 100, 30);
        add(submitBtn);
        add(clearBtn);

        // Output TextArea
        outputArea = new JTextArea();
        outputArea.setBounds(50, 310, 380, 200);
        outputArea.setEditable(false);
        outputArea.setFont(new Font("Monospaced", Font.PLAIN, 14));
        add(outputArea);

        // Action Listeners
        submitBtn.addActionListener(this);
        clearBtn.addActionListener(this);

        setLocationRelativeTo(null);
        setVisible(true);
    }

    // Handle button clicks
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submitBtn) {
            String name = nameField.getText();
            String age = ageField.getText();
            String gender = maleBtn.isSelected() ? "Male" : femaleBtn.isSelected() ? "Female" : "Not Selected";
            String qualification = (String) qualBox.getSelectedItem();
            String skills = skillsField.getText();

            // Display in TextArea
            outputArea.setText("===== JOB RESUME =====\n");
            outputArea.append("Name: " + name + "\n");
            outputArea.append("Age: " + age + "\n");
            outputArea.append("Gender: " + gender + "\n");
            outputArea.append("Qualification: " + qualification + "\n");
            outputArea.append("Skills: " + skills + "\n");
            outputArea.append("======================\n");
            outputArea.append("Form Submitted Successfully ✅");
        }

        if (e.getSource() == clearBtn) {
            nameField.setText("");
            ageField.setText("");
            genderGroup.clearSelection();
            qualBox.setSelectedIndex(0);
            skillsField.setText("");
            outputArea.setText("");
        }
    }

    public static void main(String[] args) {
        new q20_JobResume();
    }
}
