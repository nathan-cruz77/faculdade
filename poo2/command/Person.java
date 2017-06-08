public class Person {
    private int id;
    private String name;

    public static Person create(int id, String name){
        Person p = new Person();

        p.id = id;
        p.name = name;

        return p;
    }

    public String toString(){
        return  "" + this.id + " " + this.name;
    }

    public int getId(){
        return this.id;
    }
}
