package vehicle;
import java.io.Serializable;
import java.util.GregorianCalendar;

public class Vehicle implements Serializable{
	private static final long serialVersionUID = -5399605122490343339L;
    private String registrationId;
    private String vehicleType;
    private String owner;
    private Integer horsePower;
    private String vin;
    private Integer engineDisp;
    private GregorianCalendar registrationDate;
    private GregorianCalendar modificationDate;
    private GregorianCalendar removeDate;
    private Boolean inUse;
    private Boolean stolen;
    
    public Vehicle(String registrationId) {
    	this.registrationId = registrationId;
    }
    
    public Vehicle(String registrationId, String vehicleType, String owner, Integer horsePower, String vin, Integer engineDisp, GregorianCalendar registrationDate) {
        this.registrationId = registrationId;
        this.vehicleType = vehicleType;
        this.owner = owner;
        this.horsePower = horsePower;
        this.vin = vin;
        this.engineDisp = engineDisp;
        this.registrationDate = registrationDate;
        this.modificationDate = registrationDate;
        this.inUse = true;
        this.stolen = false;
    }
    
    public Vehicle(String registrationId, String vehicleType, String owner, Integer horsePower, String vin, Integer engineDisp, GregorianCalendar registrationDate, GregorianCalendar modificationDate) {
        this.registrationId = registrationId;
        this.vehicleType = vehicleType;
        this.owner = owner;
        this.horsePower = horsePower;
        this.vin = vin;
        this.engineDisp = engineDisp;
        this.registrationDate = registrationDate;
        this.modificationDate = modificationDate;
        this.inUse = true;
        this.stolen = false;
    }
    
    public Vehicle(String registrationId, String vehicleType, String owner, Integer horsePower, String vin, Integer engineDisp, GregorianCalendar registrationDate, GregorianCalendar modificationDate, Boolean stolen) {
        this.registrationId = registrationId;
        this.vehicleType = vehicleType;
        this.owner = owner;
        this.horsePower = horsePower;
        this.vin = vin;
        this.engineDisp = engineDisp;
        this.registrationDate = registrationDate;
        this.modificationDate = modificationDate;
        this.inUse = true;
        this.stolen = stolen;
    }
    
    public Vehicle(String registrationId, String vehicleType, String owner, Integer horsePower, String vin, Integer engineDisp, GregorianCalendar registrationDate, GregorianCalendar modificationDate, GregorianCalendar removeDate) {
        this.registrationId = registrationId;
        this.vehicleType = vehicleType;
        this.owner = owner;
        this.horsePower = horsePower;
        this.vin = vin;
        this.engineDisp = engineDisp;
        this.registrationDate = registrationDate;
        this.modificationDate = modificationDate;
        this.removeDate = removeDate;
        this.inUse = true;
        this.stolen = false;
    }

    public Vehicle(String registrationId, String vehicleType, String owner, Integer horsePower, String vin, Integer engineDisp, GregorianCalendar registrationDate, GregorianCalendar modificationDate, GregorianCalendar removeDate, Boolean inUse, Boolean stolen) {
        this.registrationId = registrationId;
        this.vehicleType = vehicleType;
        this.owner = owner;
        this.horsePower = horsePower;
        this.vin = vin;
        this.engineDisp = engineDisp;
        this.registrationDate = registrationDate;
        this.modificationDate = modificationDate;
        this.removeDate = removeDate;
        this.inUse = inUse;
        this.stolen = stolen;
    }
    
    public String getRegistrationId() {
        return registrationId;
    }

    public void setRegistrationId(String registrationId) {
        this.registrationId = registrationId;
    }

    public String getVehicleType() {
        return vehicleType;
    }

    public void setVehicleType(String vehicleType) {
        this.vehicleType = vehicleType;
    }

    public String getOwner() {
        return owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public Integer getHorsePower() {
        return horsePower;
    }

    public void setHorsePower(Integer horsePower) {
        this.horsePower = horsePower;
    }

    public String getVin() {
        return vin;
    }

    public void setVin(String vin) {
        this.vin = vin;
    }

    public Integer getEngineDisp() {
        return engineDisp;
    }

    public void setEngineDisp(Integer engineDisp) {
        this.engineDisp = engineDisp;
    }

    public GregorianCalendar getRegistrationDate() {
        return registrationDate;
    }

    public void setRegistrationDate(GregorianCalendar registrationDate) {
        this.registrationDate = registrationDate;
    }

    public GregorianCalendar getModificationDate() {
        return modificationDate;
    }

    public void setModificationDate(GregorianCalendar modificationDate) {
        this.modificationDate = modificationDate;
    }

    public GregorianCalendar getRemoveDate() {
        return removeDate;
    }

    public void setRemoveDate(GregorianCalendar removeDate) {
        this.removeDate = removeDate;
    }

    public Boolean getInUse() {
        return inUse;
    }

    public void setInUse(Boolean inUse) {
        this.inUse = inUse;
    }

    public Boolean getStolen() {
        return stolen;
    }

    public void setStolen(Boolean stolen) {
        this.stolen = stolen;
    }
}