public class Dummy {
    public static void main(String[] args){
        ActualPersonBuilder person_builder = new ActualPersonBuilder();
        ActualCompanyBuilder company_builder = new ActualCompanyBuilder();
        Director director = new Director(person_builder, company_builder);

        Person p0 = director.buildPerson();
        System.out.println("\n=======================");
        System.out.println("Person object created!");

        Company c0 = director.buildCompany();
        System.out.println("Company object created!");
        System.out.println("=======================\n");
    }
}
