import java.util.Date;

public class PayrollSystemTest{
   public static void main(String args[]){
      
        /* Instancia os funcionarios */       
        SalariedEmployee salariedEmployee = 
            new SalariedEmployee("John", "Smith", "111-11-1111",
                                 new Date(90,5,27), 1, 800.00 );
        HourlyEmployee hourlyEmployee =
            new HourlyEmployee("Karen", "Price", "222-22-2222",
                               new Date(83,12,22), 2, 16.75, 40);
        CommissionEmployee commissionEmployee =
            new CommissionEmployee("Sue", "Jones", "333-33-3333",
                                   new Date(89,10,12), 3, 10000, .06);
         BasePlusCommissionEmployee basePlusCommissionEmployee =
            new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444",
                                           new Date(86,3,6), 4, 5000,
                                           .04, 300 );

        /* Calcula o ganho de cada funcionario */
        System.out.println( "Employees processed individually:\n" );

        System.out.printf( "%s\n%s: $%,.2f\n\n", 
            salariedEmployee, "earned", salariedEmployee.earnings() );
        System.out.printf( "%s\n%s: $%,.2f\n\n",
            hourlyEmployee, "earned", hourlyEmployee.earnings() );
        System.out.printf( "%s\n%s: $%,.2f\n\n",
            commissionEmployee, "earned", commissionEmployee.earnings() );
        System.out.printf( "%s\n%s: $%,.2f\n\n", 
            basePlusCommissionEmployee, 
            "earned", basePlusCommissionEmployee.earnings() );

        /* Cria um vetor para armazenar os funcionarios */
        Employee employees[] = new Employee[4];

        // inicializa o array com Employees          
        employees[ 0 ] = salariedEmployee;          
        employees[ 1 ] = hourlyEmployee;            
        employees[ 2 ] = commissionEmployee;        
        employees[ 3 ] = basePlusCommissionEmployee;

        System.out.println( "Employees processed polymorphically:\n" );

        /* Processa arbitrariamente o vetor de empregados */
        for ( Employee currentEmployee : employees ){
            System.out.println(currentEmployee);

            /* Determina se elemento eh um BasePlusCommissionEmployee */
            if (currentEmployee instanceof BasePlusCommissionEmployee) 
            {
                BasePlusCommissionEmployee employee = 
                    ( BasePlusCommissionEmployee ) currentEmployee;

                double oldBaseSalary = employee.getBaseSalary();
                employee.setBaseSalary( 1.10 * oldBaseSalary );
                System.out.printf( 
                    "new base salary with 10%% increase is: $%,.2f\n",
                    employee.getBaseSalary() );
            }

            System.out.printf("earned $%,.2f\n\n",
                              currentEmployee.earnings());
      }

      /* Obtem o nome do tipo de cada objeto no vetor de funcionarios */
        for ( int j = 0; j < employees.length; j++ )      
            System.out.printf("Employee %d is a %s\n", j,
                              employees[j].getClass().getName());
    }
}
