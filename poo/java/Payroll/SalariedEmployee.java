import java.util.Date;

public class SalariedEmployee extends Employee{

    /* Atributos */
    private double weeklySalary;

    /* Construtor */
    public SalariedEmployee(String first, String last, String ssn, 
                            Date birthDate, int departmentCode,
                            double salary){

        super(first, last, ssn, birthDate, departmentCode); 
        this.setWeeklySalary(salary); 

    }

    /* Getters */
    public double getWeeklySalary(){
        return this.weeklySalary;
    }

    /* Setters */
    public void setWeeklySalary(double salary){
        this.weeklySalary = salary < 0.0 ? 0.0 : salary;
    }

    /* Calcula os ganhos do funcionario */
    public double earnings()                                            
    {       
        Date today = new Date();
        if(today.getMonth() == super.getPrivateBirthDate().getMonth())
            return this.getWeeklySalary()+150;
        return this.getWeeklySalary();
    }              

    /* Metodo invocado quando tentamos imprimir objetos desta classe */
    public String toString()                                     
    {                                                            
        return String.format( "salaried employee: %s\n%s: $%,.2f",
            super.toString(), "weekly salary", getWeeklySalary() );
    }
}
