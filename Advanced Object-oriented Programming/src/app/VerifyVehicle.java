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
import java.util.Calendar;
import java.util.GregorianCalendar;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import vehicle.Vehicle;

public class VerifyVehicle {
	private static JFrame frame;
	private static void createVerifyForm(Container pane) {
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
		JButton verifyBtn = new JButton("Verifica!");
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
					try {
						Socket socket = new Socket("localhost", 1234);
						ObjectOutputStream os = new ObjectOutputStream(socket.getOutputStream());
						ObjectInputStream is = new ObjectInputStream(socket.getInputStream());
						os.writeObject(new Vehicle(id));
						Integer cs = 2, isOk = 0;
						os.writeObject(cs);
						try {
							isOk = (Integer) is.readObject();
						}
						catch (ClassNotFoundException e) {
							e.printStackTrace();
						}
						if(isOk == 0) {
							JOptionPane.showMessageDialog(frame, "Vehiculul nu exista!");
						}
						else {
							try {
								Vehicle v = (Vehicle) is.readObject();
								showVehicle(v);
							}
							catch (ClassNotFoundException e) {
								JOptionPane.showMessageDialog(frame, "Vehiculul nu exista!");
								e.printStackTrace();
							}
						}
						socket.close();	
					}
					catch (UnknownHostException e) {
						e.printStackTrace();
					}
					catch (IOException e) {
						e.printStackTrace();
					}
				}
				else {
					pane.add(wrong, c);
					frame.revalidate();
					frame.repaint();
				}
			}
		});
	}
	private static void showVehicle(Vehicle v) {
		frame.dispose();
		JFrame frameShow = new JFrame("Detalii vehicul");
		frameShow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container pane = frameShow.getContentPane();
		pane.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		pane.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.fill = GridBagConstraints.HORIZONTAL;
		c.insets = new Insets(10, 20, 10, 20);
		c.weighty = 5;
		c.weightx = 0.5;
		c.ipadx = 20;
		c.ipady = 10;
		
		//labels
		JLabel labelRegistrationId = new JLabel("Numar de inmatriculare:");
		c.gridx = 0;
		c.gridy = 0;
		pane.add(labelRegistrationId, c);
		JLabel label = new JLabel("Tipul vehiculului:");
		c.gridy = 1;
		pane.add(label, c);
		JLabel labelOwner = new JLabel("Proprietar:");
		c.gridy = 2;
		pane.add(labelOwner, c);
		JLabel labelHP = new JLabel("Cai putere:");
		c.gridy = 3;
		pane.add(labelHP, c);
		JLabel labelVIN = new JLabel("Serie sasiu:");
		c.gridy = 4;
		pane.add(labelVIN, c);
		JLabel labelED = new JLabel("Capacitate motor:");
		c.gridy = 5;
		pane.add(labelED, c);
		JLabel labelDateReg = new JLabel("Data intregistrarii:");
		c.gridy = 6;
		pane.add(labelDateReg, c);
		JLabel labelDateMod = new JLabel("Data modificarii:");
		c.gridy = 7;
		pane.add(labelDateMod, c);
		JLabel labelStolen = new JLabel("Furata:");
		c.gridy = 8;
		pane.add(labelStolen, c);
		c.gridx = 2;
		label = new JLabel("CP");
		c.gridy = 3;
		pane.add(label, c);
		label = new JLabel("cmc");
		c.gridy = 5;
		pane.add(label, c);
		c.gridx = 1;

		//editables
		JTextField registrationId = new JTextField(v.getRegistrationId());
		registrationId.setEditable(false);
		c.gridy = 0;
		pane.add(registrationId, c);
		JTextField vehicleType = new JTextField(v.getVehicleType());
		vehicleType.setEditable(false);
		c.gridy = 1;
		pane.add(vehicleType, c);
		JTextField owner = new JTextField(v.getOwner());
		owner.setEditable(false);
		c.gridy = 2;
		pane.add(owner, c);
		JTextField horsePower = new JTextField(v.getHorsePower().toString());
		horsePower.setEditable(false);
		c.gridy = 3;
		pane.add(horsePower, c);
		JTextField vin = new JTextField(v.getVin());
		vin.setEditable(false);
		c.gridy = 4;
		pane.add(vin, c);
		JTextField engineDisp = new JTextField(v.getEngineDisp().toString());
		engineDisp.setEditable(false);
		c.gridy = 5;
		pane.add(engineDisp, c);
		GregorianCalendar dtReg = v.getRegistrationDate();
		JTextField dateReg = new JTextField(((Integer) dtReg.get(Calendar.DAY_OF_MONTH)).toString() + "-" + ((Integer) dtReg.get(Calendar.MONTH)).toString() + "-" + ((Integer) dtReg.get(Calendar.YEAR)).toString());
		dateReg.setEditable(false);
		c.gridy = 6;
		pane.add(dateReg, c);
		GregorianCalendar dtMod = v.getRegistrationDate();
		JTextField dateMod = new JTextField(((Integer) dtMod.get(Calendar.DAY_OF_MONTH)).toString() + "-" + ((Integer) dtMod.get(Calendar.MONTH)).toString() + "-" + ((Integer) dtMod.get(Calendar.YEAR)).toString());
		dateMod.setEditable(false);
		c.gridy = 7;
		pane.add(dateMod, c);
		JTextField stolen;
		c.gridy = 8;
		if(v.getStolen() == true) {
			stolen = new JTextField("DA");
			stolen.setEditable(false);
			pane.add(stolen, c);
		}
		if(v.getStolen() == false) {
			stolen = new JTextField("NU");
			stolen.setEditable(false);
			pane.add(stolen, c);
		}
		JButton backBtn = new JButton("Inapoi");
		c.gridx = 2;
		c.gridy = 9;
		pane.add(backBtn, c);
		frameShow.pack();
		Dimension screenDimension = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameDimension = frameShow.getSize();
		frameShow.setLocation(screenDimension.width/2 - frameDimension.width/2, screenDimension.height/2 - frameDimension.height/2);
		frameShow.setVisible(true);
		backBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent ev) {
				frameShow.dispose();
				createAndShowGUI();
			}
		});
	}
	private static void createAndShowGUI() {
		frame = new JFrame("Verificare vehicul");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		createVerifyForm(frame.getContentPane());
		
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
