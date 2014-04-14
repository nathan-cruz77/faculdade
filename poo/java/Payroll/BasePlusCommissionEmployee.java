import java.util.Date;

public class BasePlusCommissionEmployee extends CommissionEmployee{

    /* Atributos */
    private double baseSalary;

    /* Construtor */
    public BasePlusCommissionEmployee(String first, String last, 
                                     String ssn, Date birthDate,
                                     int departmentCode, double sales,
                                     double rate, double salary){
        super(first, last, ssn, birthDate, departmentCode, sales, rate);
        setBaseSalary(salary);
    }

    /* Getters */
    public double getBaseSalary()
    {
       return baseSalary;
    }

    /* Setters */
    public void setBaseSalary( double salary ){
        baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
    }        

    /* Calcula os ganhos mensais */
    public double earnings(){
        return getBaseSalary() + super.earnings();                        
    }              

    /* Metodo invocado quando tentamos imprimir objetos desta classe */
    public String toString(){                                                                   
       return String.format("%s %s; %s: $%,.2f",                       
                            "base-salaried", super.toString(),                            
                            "base salary", getBaseSalary() );                             
    }
} 
