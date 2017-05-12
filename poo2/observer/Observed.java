public class Observed extends Observable {
    private int ph;
    private int temperature;
    private int pressure;
    
    public Observed(int id){
        this.id = id;
    }
    
    public void setPh(int new_ph){
        this.ph = new_ph;
        this.custom_notify();
    }
    
    public void setTemperature(int new_temperature){
        this.temperature = new_temperature;
        this.custom_notify();
    }
    
    public void setPressure(int new_pressure){
        this.pressure = new_pressure;
        this.custom_notify();
    }
}
