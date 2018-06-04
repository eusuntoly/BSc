package app;

import java.awt.Color;
import java.awt.ComponentOrientation;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import vehicle.Vehicle;

public class DeleteVehicle {
	private static JFrame frame;
	private static void createDeleteForm(Container pane) {
		pane.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		pane.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.fill = GridBagConstraints.HORIZONTAL;
		c.insets = new Insets(10, 20, 10, 20);
		c.weighty = 5;
		c.weightx = 0.5;
		c.ipadx = 30;
		c.ipady = 20;
		JLabel label = new JLabel("Introduceti numarul de inmatriculare");
		c.gridx = 0;
		c.gridy = 0;
		pane.add(label, c);
		JTextField textField = new JTextField();
		textField.setColumns(7);
		c.gridx = 1;
		c.gridy = 0;
		pane.add(textField, c);
		JButton backBtn = new JButton("Inapoi");
		c.gridx = 1;
		c.gridy = 1;
		backBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				Main.createAndShowGUI();
				frame.dispose();
			}
		});
		pane.add(backBtn, c);
		JButton verifyBtn = new JButton("Radiaza Vehicul");
		c.gridx = 0;
		c.gridy = 1;
		pane.add(verifyBtn, c);
		JLabel wrong = new JLabel("Numar de inmatriculare incorect!");
		wrong.setForeground(Color.RED);
		c.gridx = 0;
		c.gridy = 2;
		verifyBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent ev) {
				String regex1 = "([A-Z])([A-Z])([0-9])([0-9])([A-Z])([A-Z])([A-Z])";
				String regex2 = "([B])([0-9])([0-9])([0-9])([A-Z])([A-Z])([A-Z])";
				String id = textField.getText();
				if(id.matches(regex1) || id.matches(regex2)) {
					try {
						pane.remove(wrong);
						frame.revalidate();
						frame.repaint();
					}
					catch(Exception e){
		
					}
					deleteVehicle(new Vehicle(id));
				}
				else {
					pane.add(wrong, c);
					frame.revalidate();
					frame.repaint();
				}
			}
		});
	}
	private static void deleteVehicle(Vehicle v) {
		try {
			Socket socket = new Socket("localhost", 1234);
			ObjectOutputStream os = new ObjectOutputStream(socket.getOutputStream());
			ObjectInputStream is = new ObjectInputStream(socket.getInputStream());
			os.writeObject(v);
			Integer cs = 4, isOk = 0;
			os.writeObject(cs);
			try {
				isOk = (Integer) is.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
			if(isOk == 0) {
				JOptionPane.showMessageDialog(frame, "Numarul de inmatriculare nu exista!");
			}
			else {
				JOptionPane.showMessageDialog(frame, "Vehiculul a fost radiat cu succes!");
			}
			if(isOk == 1)
			socket.close();	
		}
		catch (UnknownHostException e) {
			e.printStackTrace();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void createAndShowGUI() {
		frame = new JFrame("Inmatriculare masina");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		createDeleteForm(frame.getContentPane());
		
		frame.pack();
		Dimension screenDimension = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameDimension = frame.getSize();
		frame.setLocation(screenDimension.width/2 - frameDimension.width/2, screenDimension.height/2 - frameDimension.height/2);
		frame.setVisible(true);
	}
	public static void main() {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createAndShowGUI();
			}
		});
	}
}
