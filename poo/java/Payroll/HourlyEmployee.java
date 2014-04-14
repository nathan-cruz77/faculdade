import java.util.Date;

public class HourlyEmployee extends Employee{

   /* Atributos */
   private double wage;
   private double hours;

   public HourlyEmployee(String first, String last, String ssn,
                         Date birthDate, int departmentCode,
                         double hourlyWage, double hoursWorked){
      super(first, last, ssn, birthDate, departmentCode);
      this.setWage(hourlyWage); // valida a remunera��o por hora
      this.setHours(hoursWorked); // valida as horas trabalhadas
   } // fim do construtor HourlyEmployee com cinco argumentos

   // configura a remunera��o
   public void setWage(double hourlyWage){
      wage = ( hourlyWage < 0.0 ) ? 0.0 : hourlyWage;
   }

   // retorna a remunera��o
   public double getWage()
   {
      return wage;
   } // fim do m�todo getWage

   // configura as horas trabalhadas
   public void setHours( double hoursWorked )
   {
      hours = ( ( hoursWorked >= 0.0 ) && ( hoursWorked <= 168.0 ) ) ?
         hoursWorked : 0.0;
   } // fim do m�todo setHours

   // retorna as horas trabalhadas
   public double getHours()
   {
      return hours;
   } // fim do m�todo getHours

   // calcula os rendimentos; sobrescreve o m�todo earnings em Employee
   public double earnings(){
        Date today=  new Date();
        float bonus = 0;
        if(today.getMonth() == super.getPrivateBirthDate().getMonth())
            bonus = 150;
      if ( getHours() <= 40 ) // nenhuma hora extra                           
         return getWage() * getHours() + bonus;                                
      else                                                             
         return (40 * getWage() + ( getHours() - 40 ) * getWage() * 1.5) + 150;
   } // fim do m�todo earnings              

   // retorna a representa��o de String do objeto HourlyEmployee              
   public String toString()                                              
   {                                                                     
      return String.format( "hourly employee: %s\n%s: $%,.2f; %s: %,.2f",
         super.toString(), "hourly wage", getWage(),                     
         "hours worked", getHours() );                                   
   } // fim do m�todo toString
} // fim da classe HourlyEmployee


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
