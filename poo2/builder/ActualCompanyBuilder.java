public class ActualCompanyBuilder implements CompanyBuilder {
    private Company company;

    public ActualCompanyBuilder(){
        this.company = new Company();
    }

    @Override
    public Company build(){
        return this.company;
    }

    @Override
    public CompanyBuilder setResponsible(Person person){
        this.company.setResponsible(person);
        return this;
    }
}
