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
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import vehicle.Vehicle;

public class EditVehicle {
	private static JFrame frame;
	private static String regexName = "[a-zA-Z\\s]+";
	private static String regexHP = "([1-9])([0-9])*";
	private static String regexVIN = "([0-9A-Z]){17}";
	private static String regexED = "([1-9])([0-9])*";
	private static String[] choises = {"NU", "DA"};
	private static void requestEdit(Container pane) {
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
		JButton verifyBtn = new JButton("Editeaza vehicul!");
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
								editVehicle(v);
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
	private static void editVehicle(Vehicle v) {
		Container pane = frame.getContentPane();
		pane.removeAll();
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
		c.gridy = 2;
		pane.add(owner, c);
		JTextField horsePower = new JTextField(v.getHorsePower().toString());
		c.gridy = 3;
		pane.add(horsePower, c);
		JTextField vin = new JTextField(v.getVin());
		c.gridy = 4;
		pane.add(vin, c);
		JTextField engineDisp = new JTextField(v.getEngineDisp().toString());
		c.gridy = 5;
		pane.add(engineDisp, c);
		GregorianCalendar dtReg = v.getRegistrationDate();
		JTextField dateReg = new JTextField(((Integer) dtReg.get(Calendar.DAY_OF_MONTH)).toString() + "-" + ((Integer) dtReg.get(Calendar.MONTH)).toString() + "-" + ((Integer) dtReg.get(Calendar.YEAR)).toString());
		dateReg.setEditable(false);
		c.gridy = 6;
		pane.add(dateReg, c);
		JTextField dateMod = new JTextField("DD-MM-YYYY");
		c.gridy = 7;
		pane.add(dateMod, c);
		JComboBox<String> stolen = new JComboBox<String>(choises);
		c.gridy = 8;
		if(v.getStolen() == true) {
			stolen.setSelectedIndex(1);
			stolen.setSelectedItem(1);
		}
		if(v.getStolen() == false) {
			stolen.setSelectedIndex(0);
			stolen.setSelectedItem(0);
		}
		pane.add(stolen, c);
		JButton regBtn = new JButton("Editeaza vehiculul!");
		c.gridx = 0;
		c.gridy = 9;
		pane.add(regBtn, c);
		JButton backBtn = new JButton("Inapoi");
		c.gridx = 2;
		pane.add(backBtn, c);
		frame.pack();
		Dimension screenDimension = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameDimension = frame.getSize();
		frame.setLocation(screenDimension.width/2 - frameDimension.width/2, screenDimension.height/2 - frameDimension.height/2);
		frame.validate();
		frame.repaint();
		backBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				frame.dispose();
				createAndShowGUI();
			}
		});
		regBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent ev) {
				Boolean isOk = true;
				Integer year = 0, month = 0, day = 0;
				if(!owner.getText().matches(regexName)) {
					isOk = false;
					labelOwner.setForeground(Color.RED);
				}
				else
					labelOwner.setForeground(Color.BLACK);
				if(!horsePower.getText().matches(regexHP)) {
					isOk = false;
					labelHP.setForeground(Color.RED);
				}
				else
					labelHP.setForeground(Color.BLACK);
				if(!vin.getText().matches(regexVIN)) {
					isOk = false;
					labelVIN.setForeground(Color.RED);
				}
				else
					labelVIN.setForeground(Color.BLACK);
				if(!engineDisp.getText().matches(regexED)) {
					isOk = false;
					labelED.setForeground(Color.RED);
				}
				else
					labelED.setForeground(Color.BLACK);
				if(dateMod.getText().length() == 10) {
					try {
						day = Integer.valueOf(dateMod.getText().substring(0, 2));
						month = Integer.valueOf(dateMod.getText().substring(3, 5));
						year = Integer.valueOf(dateMod.getText().substring(6));
					}
					catch(Exception e) {
						isOk = false;
						labelDateMod.setForeground(Color.RED);
					}
					if(day < 1 || day > 31) {
						isOk = false;
						labelDateMod.setForeground(Color.RED);
					}
					else if(month < 1 || month > 12) {
						isOk = false;
						labelDateMod.setForeground(Color.RED);
					}
					else if(year < 1900 || year > 2050) {
						isOk = false;
						labelDateMod.setForeground(Color.RED);
					}
					else
						labelDateMod.setForeground(Color.BLACK);
				}
				else {
					isOk = false;
					labelDateMod.setForeground(Color.RED);
				}
				if(isOk) {
					Boolean stn = false;
					if(stolen.getSelectedIndex() == 1) stn = true;
					registerEditedVehicle(new Vehicle(v.getRegistrationId(), v.getVehicleType(), owner.getText(), Integer.valueOf(horsePower.getText()), vin.getText(), Integer.valueOf(engineDisp.getText()), v.getRegistrationDate(), new GregorianCalendar(year, month, day), stn));
				}
			}
		});
		
	}
	private static void registerEditedVehicle(Vehicle v) {
		try {
			Socket socket = new Socket("localhost", 1234);
			ObjectOutputStream os = new ObjectOutputStream(socket.getOutputStream());
			ObjectInputStream is = new ObjectInputStream(socket.getInputStream());
			os.writeObject(v);
			Integer cs = 3, isOk = 0;
			os.writeObject(cs);
			try {
				isOk = (Integer) is.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
			if(isOk == 0) {
				JOptionPane.showMessageDialog(frame, "Editare esuata!");
			}
			else {
				JOptionPane.showMessageDialog(frame, "Vehiculul a fost editat cu succes!");
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
	private static void createAndShowGUI() {
		frame = new JFrame("Inmatriculare masina");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		requestEdit(frame.getContentPane());
		
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
