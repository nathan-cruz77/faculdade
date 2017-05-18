public class Director {
    private PersonBuilder person_builder;
    private CompanyBuilder company_builder;

    public Director(PersonBuilder person_builder, CompanyBuilder company_builder){
        this.person_builder = person_builder;
        this.company_builder = company_builder;
    }

    public Person buildPerson(){
        // Pretend these come from a database or something
        String id = "very random and unique id";
        String name = "real name of a person";

        return this.person_builder.setId(id).setName(name).build();
    }
    public Company buildCompany(){
        // Pretend these come from a database or something
        String id = "very random and unique id";
        String name = "real name of a person";
        Person responsible = this.person_builder.setId(id).setName(name).build();

        return this.company_builder.setResponsible(responsible).build();
    }
}
