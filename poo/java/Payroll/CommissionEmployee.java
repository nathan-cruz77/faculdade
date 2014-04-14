import java.util.Date;


public class CommissionEmployee extends Employee{

    private double grossSales; // vendas brutas semanais       
    private double commissionRate; // porcentagem da comissão

    // construtor de cinco argumentos
    public CommissionEmployee(String first, String last, String ssn,
                              Date birthDate, int departmentCode,
                              double sales, double rate){
       super(first, last, ssn, birthDate, departmentCode);
       setGrossSales( sales );
       setCommissionRate( rate );
    } // fim do construtor CommissionEmployee de cinco argumentos              

    // configura a taxa de comissão
    public void setCommissionRate( double rate )
    {
       commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
    } // fim do método setCommissionRate 
 
    // retorna a taxa de comissão 
    public double getCommissionRate()
    {
       return commissionRate;
    } // fim do método getCommissionRate 
 
    // configura a quantidade de vendas brutas
    public void setGrossSales( double sales )
    {
       grossSales = ( sales < 0.0 ) ? 0.0 : sales;
    } // fim do método setGrossSales 
 
    // retorna a quantidade de vendas brutas 
    public double getGrossSales()
    {
       return grossSales;
    } // fim do método getGrossSales 
 
    // calcula os rendimentos; sobrescreve o método earnings em Employee
    public double earnings()                                            
    {               
        Date today = new Date();

        if(today.getMonth() == super.getPrivateBirthDate().getMonth())
            return (this.getCommissionRate()*this.getGrossSales()) + 150;
        return getCommissionRate() * getGrossSales();                    
    } // fim do método earnings              
 
    // retorna a representação String do objeto CommissionEmployee     
    public String toString()                                    
    {                                                           
       return String.format( "%s: %s\n%s: $%,.2f; %s: %.2f",    
          "commission employee", super.toString(),              
          "gross sales", getGrossSales(),                       
          "commission rate", getCommissionRate() );             
    } // fim do método toString
 } // fim da classe CommissionEmployee 
 
 
 /**************************************************************************
  * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
  * Pearson Education, Inc. All Rights Reserved.                           *
  *                                                                        *
  * DISCLAIMER: The authors and publisher of this book have used their     *
  * best efforts in preparing the book. These efforts include the          *
  * development, research, and testing of the theories and programs        *
  * to determine their effectiveness. The authors and publisher make       *
  * no warranty of any kind, expressed or implied, with regard to these    *
  * programs or to the documentation contained in these books. The authors *
  * and publisher shall not be liable in any event for incidental or       *
  * consequential damages in connection with, or arising out of, the       *
  * furnishing, performance, or use of these programs.                     *
  *************************************************************************/
