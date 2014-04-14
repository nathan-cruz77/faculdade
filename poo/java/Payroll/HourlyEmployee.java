import java.util.Date;

public class HourlyEmployee extends Employee{

    /* Atributos */
    private double wage;
    private double hours;

    /* Construtor */
    public HourlyEmployee(String first, String last, String ssn,
                         Date birthDate, int departmentCode,
                         double hourlyWage, double hoursWorked){
        super(first, last, ssn, birthDate, departmentCode);
        this.setWage(hourlyWage);
        this.setHours(hoursWorked);
    }

    /* Getters */
    public double getWage(){
        return wage;
    } 
    public double getHours(){
        return hours;
    }

    /* Setters */
    public void setWage(double hourlyWage){
        wage = ( hourlyWage < 0.0 ) ? 0.0 : hourlyWage;
    }
    public void setHours( double hoursWorked )
    {
        this.hours = ((hoursWorked >= 0.0) && 
                      ( hoursWorked <= 168.0)) ? hoursWorked : 0.0;
    }

    /* Calcula os rendimentos do empregado */
    public double earnings(){
        Date today=  new Date();
        float bonus = 0;
        if(today.getMonth() == super.getPrivateBirthDate().getMonth())
            bonus = 150;
        if (getHours() <= 40) return getWage() * getHours() + bonus;
        else 
            return (40 * getWage() + ( getHours() - 40 ) * getWage() * 1.5) + 150;
    }              

    /* Metodo invocado quando tentamos imprimir objetos desta classe */
    public String toString(){
        return String.format("hourly employee: %s\n%s: $%,.2f; %s: %,.2f",
                             super.toString(), "hourly wage", getWage(),
                             "hours worked", getHours());
    }
}
