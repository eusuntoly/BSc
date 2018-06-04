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
import java.util.GregorianCalendar;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import vehicle.Vehicle;

public class RegisterVehicle {
	private static JFrame frame;
	private static String regexName = "[a-zA-Z\\s]+";
	private static String regexId1 = "([A-Z])([A-Z])([0-9])([0-9])([A-Z])([A-Z])([A-Z])";
	private static String regexId2 = "([B])([0-9])([0-9])([0-9])([A-Z])([A-Z])([A-Z])";
	private static String regexHP = "([1-9])([0-9])*";
	private static String regexVIN = "([0-9A-Z]){17}";
	private static String regexED = "([1-9])([0-9])*";
	private static String[] vehicleTypes = {"moped", "motocicleta", "automobil", "autobuz", "troleibuz", "microbuz", "autoutilitara", "autovehicul tractor", "autoremorcher", "autotractor", "(semi)remorca", "vehicul special", "masina autopropulsata"}; 
	private static void createRegistrationForm(Container pane) {
		pane.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		pane.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.fill = GridBagConstraints.HORIZONTAL;
		c.insets = new Insets(10, 20, 10, 20);
		c.weighty = 5;
		c.weightx = 0.5;
		c.ipadx = 20;
		c.ipady = 10;
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
		JLabel labelDate = new JLabel("Data intregistrarii:");
		c.gridy = 6;
		pane.add(labelDate, c);
		c.gridx = 2;
		label = new JLabel("CP");
		c.gridy = 3;
		pane.add(label, c);
		label = new JLabel("cmc");
		c.gridy = 5;
		pane.add(label, c);
		c.gridx = 1;
		JTextField registrationId = new JTextField();
		c.gridy = 0;
		pane.add(registrationId, c);
		JComboBox<String> vehicleType = new JComboBox<String>(vehicleTypes);
		c.gridy = 1;
		vehicleType.setSelectedIndex(2);
		vehicleType.setSelectedItem(2);
		vehicleType.setEditable(true);
		pane.add(vehicleType, c);
		JTextField owner = new JTextField();
		c.gridy = 2;
		pane.add(owner, c);
		JTextField horsePower = new JTextField();
		c.gridy = 3;
		pane.add(horsePower, c);
		JTextField vin = new JTextField();
		c.gridy = 4;
		pane.add(vin, c);
		JTextField engineDisp = new JTextField();
		c.gridy = 5;
		pane.add(engineDisp, c);
		JTextField date = new JTextField("DD-MM-YYYY");
		c.gridy = 6;
		pane.add(date, c);
		JButton regBtn = new JButton("Inregistreaza vehiculul!");
		c.gridx = 0;
		c.gridy = 7;
		pane.add(regBtn, c);
		JButton backBtn = new JButton("Inapoi");
		c.gridx = 2;
		pane.add(backBtn, c);
		backBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				Main.createAndShowGUI();
				frame.dispose();
			}
		});
		regBtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent ev) {
				Boolean isOk = true;
				Integer year = 0, month = 0, day = 0;
				if(!registrationId.getText().matches(regexId1) && !registrationId.getText().matches(regexId2)) {
					isOk = false;
					labelRegistrationId.setForeground(Color.RED);
				}
				else
					labelRegistrationId.setForeground(Color.BLACK);
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
				if(date.getText().length() == 10) {
					try {
						day = Integer.valueOf(date.getText().substring(0, 2));
						month = Integer.valueOf(date.getText().substring(3, 5));
						year = Integer.valueOf(date.getText().substring(6));
					}
					catch(Exception e) {
						isOk = false;
						labelDate.setForeground(Color.RED);
					}
					if(day < 1 || day > 31) {
						isOk = false;
						labelDate.setForeground(Color.RED);
					}
					else if(month < 1 || month > 12) {
						isOk = false;
						labelDate.setForeground(Color.RED);
					}
					else if(year < 1900 || year > 2050) {
						isOk = false;
						labelDate.setForeground(Color.RED);
					}
					else
						labelDate.setForeground(Color.BLACK);
				}
				else {
					isOk = false;
					labelDate.setForeground(Color.RED);
				}
				if(isOk)
					registerVehicle(new Vehicle(registrationId.getText(), (String)vehicleType.getSelectedItem(), owner.getText(), Integer.valueOf(horsePower.getText()), vin.getText(), Integer.valueOf(engineDisp.getText()), new GregorianCalendar(year, month, day)));
			}
		});
	}
	private static void registerVehicle(Vehicle v) {
		try {
			Socket socket = new Socket("localhost", 1234);
			ObjectOutputStream os = new ObjectOutputStream(socket.getOutputStream());
			ObjectInputStream is = new ObjectInputStream(socket.getInputStream());
			os.writeObject(v);
			Integer cs = 1, isOk = 0;
			os.writeObject(cs);
			try {
				isOk = (Integer) is.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
			if(isOk == 0) {
				JOptionPane.showMessageDialog(frame, "Numarul de inmatriculare exista deja!");
			}
			else {
				JOptionPane.showMessageDialog(frame, "Vehiculul a fost inregistrat cu succes!");
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
		
		createRegistrationForm(frame.getContentPane());
		
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
