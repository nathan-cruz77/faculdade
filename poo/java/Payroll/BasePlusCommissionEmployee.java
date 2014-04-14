import java.util.Date;

public class BasePlusCommissionEmployee extends CommissionEmployee{

    /* Atributos */
    private double baseSalary;

   public BasePlusCommissionEmployee(String first, String last, 
                                     String ssn, Date birthDate,
                                     int departmentCode, double sales,
                                     double rate, double salary){
      super(first, last, ssn, birthDate, departmentCode, sales, rate);
      setBaseSalary( salary ); // valida e armazena sal�rio-base
   } // fim do construtor BasePlusCommissionEmployee de seis argumentos

   // configura o sal�rio-base                                    
   public void setBaseSalary( double salary )
   {
      baseSalary = ( salary < 0.0 ) ? 0.0 : salary; // n�o-negativo
   } // fim do m�todo setBaseSalary                         

   // retorna o sal�rio-base                                   
   public double getBaseSalary()
   {
      return baseSalary;
   } // fim do m�todo getBaseSalary                            

   // calcula os vencimentos; sobrescreve o m�todo earnings em CommissionEmployee
   public double earnings()                                             
   {       
        Date today = new Date();       

        if(today.getMonth() == super.getPrivateBirthDate().getMonth())
            return this.getBaseSalary() + super.earnings() + 150;
        return getBaseSalary() + super.earnings();                        
   } // fim do m�todo earnings              

   // retorna a representa��o String do objeto BasePlusCommissionEmployee
   public String toString()                                            
   {                                                                   
      return String.format( "%s %s; %s: $%,.2f",                       
         "base-salaried", super.toString(),                            
         "base salary", getBaseSalary() );                             
   } // fim do m�todo toString                                            
} // fim da classe BasePlusCommissionEmployee 


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
