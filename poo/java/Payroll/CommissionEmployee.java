import java.util.Date;


public class CommissionEmployee extends Employee{
    
    /* Atributos */
    private double grossSales;
    private double commissionRate;

    /* Construtor */
    public CommissionEmployee(String first, String last, String ssn,
                              Date birthDate, int departmentCode,
                              double sales, double rate){
        super(first, last, ssn, birthDate, departmentCode);
        this.setGrossSales(sales);
        this.setCommissionRate(rate);
    }

    /* Getters */
    public double getGrossSales(){
        return this.grossSales;
    }
    public double getCommissionRate(){
        return this.commissionRate;
    }

    /* Setters */
    public void setGrossSales(double sales){
        this.grossSales = ( sales < 0.0 ) ? 0.0 : sales;
    }
 
    public void setCommissionRate(double rate){
        this.commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
    } 
 
    /* Calcula os ganhos do funcionario */
    public double earnings(){
        Date today = new Date();

        if(today.getMonth() == super.getPrivateBirthDate().getMonth())
            return (this.getCommissionRate()*this.getGrossSales()) + 150;
        return getCommissionRate() * getGrossSales();                    
    }              
 
    /* Metodo invocado quando tentamos imprimir objetos desta classe */
    public String toString()                                    
    {                                                           
       return String.format( "%s: %s\n%s: $%,.2f; %s: %.2f",    
          "commission employee", super.toString(),              
          "gross sales", getGrossSales(),                       
          "commission rate", getCommissionRate() );             
    }
 }
