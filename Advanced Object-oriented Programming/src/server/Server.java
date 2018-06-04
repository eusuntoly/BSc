package server;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Calendar;
import java.util.GregorianCalendar;

import vehicle.Vehicle;


public class Server extends Thread{
	private ServerSocket serverSocket;
	static final String JDBC_DRIVER = "oracle.jdbc.driver.OracleDriver";  
	final static String DB_URL=   "jdbc:oracle:thin:@localhost:1521/orcl";
	final static String DB_USER = "eusuntoly";
	final static String DB_PASSWORD = "yoyoyoL0LY97";
	public Server(int port) throws IOException {
		serverSocket = new ServerSocket(port);
		serverSocket.setSoTimeout(0);
	}
	public void run() {
		while(true) {
			try {
				Socket server = serverSocket.accept();
				ObjectOutputStream os = new ObjectOutputStream(server.getOutputStream());
				ObjectInputStream is = new ObjectInputStream(server.getInputStream());
				Vehicle v = (Vehicle) is.readObject();
				Integer cs = (Integer) is.readObject();
				Connection conn = null;
				Statement stmt = null;
				try {
					Class.forName(JDBC_DRIVER);
					conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
					stmt = conn.createStatement();
					String sql = null;
					if(cs == 1) {
						sql = "SELECT registration_id FROM vehicles WHERE registration_id = '" + v.getRegistrationId() + "'";
						ResultSet rs = stmt.executeQuery(sql);
						if(rs.next()) {
							os.writeObject(0);
						}
						else {
							sql = "INSERT INTO vehicles VALUES('" + v.getRegistrationId() + "', '" + v.getVehicleType() + "', '" + v.getOwner() + "', " + v.getHorsePower() + ", '" + v.getVin() + "', " + v.getEngineDisp() + ", TO_DATE('" + v.getRegistrationDate().get(Calendar.DAY_OF_MONTH) + "-" + v.getRegistrationDate().get(Calendar.MONTH) + "-" + v.getRegistrationDate().get(Calendar.YEAR) + "', 'DD-MM-YYYY')" + ", TO_DATE('" + v.getRegistrationDate().get(Calendar.DAY_OF_MONTH) + "-" + v.getRegistrationDate().get(Calendar.MONTH) + "-" + v.getRegistrationDate().get(Calendar.YEAR) + "', 'DD-MM-YYYY'), '" + (v.getStolen() ? "DA" : "NU") + "', 'DA')";
							stmt.executeUpdate(sql);
							os.writeObject(1);
						}
						rs.close();
					}
					else if(cs == 2) {
						sql = "SELECT registration_id, vehicle_type, owner, horse_power, vin, engine_disp, stolen, registration_date, modification_date FROM vehicles WHERE registration_id = '" + v.getRegistrationId() + "'";
						ResultSet rs = stmt.executeQuery(sql);
						if(!rs.next()) {
							os.writeObject(0);
						}
						else {
							os.writeObject(1);
							Vehicle vh = new Vehicle(v.getRegistrationId());
							vh.setVehicleType(rs.getString("vehicle_type"));
							vh.setOwner(rs.getString("owner"));
							vh.setHorsePower(rs.getInt("horse_power"));
							vh.setVin(rs.getString("vin"));
							vh.setEngineDisp(rs.getInt("engine_disp"));
							vh.setStolen(rs.getString("stolen").equals("DA") ? true : false);
							String dtRegistred = rs.getDate("registration_date").toString();
							vh.setRegistrationDate(new GregorianCalendar(Integer.valueOf(dtRegistred.substring(0,  4)), Integer.valueOf(dtRegistred.substring(5, 7)), Integer.valueOf(dtRegistred.substring(8, 10))));
							String dtModified = rs.getDate("modification_date").toString();
							vh.setModificationDate(new GregorianCalendar(Integer.valueOf(dtModified.substring(0,  4)), Integer.valueOf(dtModified.substring(5, 7)), Integer.valueOf(dtModified.substring(8, 10))));
							os.writeObject(vh);
						}
						rs.close();
					}
					else if(cs == 3) {
						sql = "INSERT INTO vehicles_history SELECT * FROM vehicles WHERE registration_id = '" + v.getRegistrationId() + "'";
						stmt.executeUpdate(sql);
						sql = "DELETE FROM vehicles WHERE registration_id = '" + v.getRegistrationId() + "'";
						stmt.executeUpdate(sql);
						sql = "INSERT INTO vehicles VALUES('" + v.getRegistrationId() + "', '" + v.getVehicleType() + "', '" + v.getOwner() + "', " + v.getHorsePower() + ", '" + v.getVin() + "', " + v.getEngineDisp() + ", TO_DATE('" + v.getRegistrationDate().get(Calendar.DAY_OF_MONTH) + "-" + v.getRegistrationDate().get(Calendar.MONTH) + "-" + v.getRegistrationDate().get(Calendar.YEAR) + "', 'DD-MM-YYYY')" + ", TO_DATE('" + v.getModificationDate().get(Calendar.DAY_OF_MONTH) + "-" + v.getModificationDate().get(Calendar.MONTH) + "-" + v.getModificationDate().get(Calendar.YEAR) + "', 'DD-MM-YYYY'), '" + (v.getStolen() ? "DA" : "NU") + "', '" + (v.getInUse() ? "DA" : "NU") + "')";
						stmt.executeUpdate(sql);
						os.writeObject(1);
					}
					else if(cs == 4) {
						sql = "SELECT registration_id, registration_date FROM vehicles WHERE registration_id = '" + v.getRegistrationId() + "'";
						ResultSet rs = stmt.executeQuery(sql);
						if(!rs.next())
							os.writeObject(0);
						else {
							os.writeObject(1);
							sql = "INSERT INTO registration_history VALUES('" + rs.getString("registration_id") + "', TO_DATE(substr('" + rs.getString("registration_date") + "', 0, 10), 'yyyy-mm-dd'), TO_DATE('31-05-2018', 'dd-mm-yyyy'))";
							stmt.executeUpdate(sql);
							sql = "DELETE FROM vehicles WHERE registration_id = '" + v.getRegistrationId() + "'";
							stmt.executeUpdate(sql);
						}
						rs.close();
					}
				}
				catch(SQLException se){
				      //Handle errors for JDB
					  os.writeObject(0);
				      se.printStackTrace();
				}
				catch(Exception e){
				      //Handle errors for Class.forName
				      e.printStackTrace();
				}
				finally{
				      //finally block used to close resources
				      try{
				         if(stmt != null)
				            stmt.close();
				      }
				      catch(SQLException se2){
				      
				      }
				      try{
				         if(conn!=null)
				            conn.close();
				      }
				      catch(SQLException se){
				         se.printStackTrace();
				      }
				}
				server.close();
			}
			catch (SocketTimeoutException s) {
	            System.out.println("Socket timed out!");
	            break;
	        }
			catch (IOException e) {
	            e.printStackTrace();
	            break;
	        } catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
		}
	}
	public static void main(String[] args) {
		int port = 1234;
		try {
			Thread t = new Server(port);
			t.start();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
}
