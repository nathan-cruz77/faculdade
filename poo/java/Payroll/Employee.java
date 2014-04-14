import java.util.Date;

public abstract class Employee{

    /* Atributos */
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;
    private Date privatebirthDate;
    private int departmentCode;

    /* Construtor */
    public Employee(String first, String last, String ssn,
                    Date birthDate, int departmentCode){
        this.firstName = first;
        this.lastName = last;
        this.socialSecurityNumber = ssn;
        this.privatebirthDate = birthDate;
        this.departmentCode = departmentCode;
    }
    
    /* Getters */
    public String getFirstName(){
       return this.firstName;
    }
    public String getLastName(){
       return this.lastName;
    }
    public String getSocialSecurityNumber(){
       return this.socialSecurityNumber;
    }
    public Date getPrivateBirthDate(){
        return this.privatebirthDate;
    }
    public int getDepartmentCode(){
        return this.departmentCode;
    }

    /* Setters */
    public void setFirstName(String first){
       this.firstName = first;
    } 
    public void setLastName(String last){
       this.lastName = last;
    }
    public void setSocialSecurityNumber(String ssn){
       this.socialSecurityNumber = ssn;
    }
    public void setPrivateBirthDate(Date birthDate){
        this.privatebirthDate = birthDate;
    }
    public void setDepartmentCode(int departmentCode){
        this.departmentCode = departmentCode;
    }
    
    /* Representacao textual do objeto */
    public String toString(){
       return String.format( "%s %s\nSocial Security Number: %s\nDepartment Code: %s", 
          getFirstName(), getLastName(), getSocialSecurityNumber(), getDepartmentCode() );
    }
 
    /* Metodo abstrato sobrescrito pelas subclasses */
    public abstract double earnings();
 } 
