package app;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Main {
	private static JFrame frame;
	private static void createMenu(Container pane) {
		pane.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		pane.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.fill = GridBagConstraints.HORIZONTAL;
		c.insets = new Insets(10, 20, 10, 20);
		c.weighty = 5;
		c.weightx = 0.5;
		c.ipadx = 30;
		c.ipady = 20;
		JButton buttonReg = new JButton("Inmatriculare vehicul");
		c.gridx = 0;
		c.gridy = 0;
		buttonReg.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				javax.swing.SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						RegisterVehicle.main();
						frame.dispose();
					}
				});
			}
		});
		pane.add(buttonReg, c);
		JButton buttonEdit = new JButton("Editare vehicul");
		c.gridx = 0;
		c.gridy = 1;
		buttonEdit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				javax.swing.SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						EditVehicle.main();
						frame.dispose();
					}
				});
			}
		});
		pane.add(buttonEdit, c);
		JButton buttonDel = new JButton("Radiere vehicul");
		c.gridx = 0;
		c.gridy = 2;
		buttonDel.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				javax.swing.SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						DeleteVehicle.main();
						frame.dispose();
					}
				});
			}
		});
		pane.add(buttonDel, c);
		JButton buttonVerify = new JButton("Verificare vehicul");
		c.gridx = 0;
		c.gridy = 3;
		buttonVerify.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				javax.swing.SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						VerifyVehicle.main();
						frame.dispose();
					}
				});
			}
		});
		pane.add(buttonVerify, c);
	}
	protected static void createAndShowGUI() {
		frame = new JFrame("Birou inmatriculari");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		createMenu(frame.getContentPane());
		
		frame.pack();
		Dimension screenDimension = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameDimension = frame.getSize();
		frame.setLocation(screenDimension.width/2 - frameDimension.width/2, screenDimension.height/2 - frameDimension.height/2);
		frame.setVisible(true);
	}
	public static void main(String[] args) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createAndShowGUI();
			}
		});
	}
}
