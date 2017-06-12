import java.io.*;

public class ConcreteNamer implements Namer {
    private String name;

    public ConcreteNamer(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }

    public void name(BufferedWriter w){
        String s = "public class " + this.name + " ";

        try{
            w.write(s, 0, s.length());
        } catch(Exception e){
            System.out.println("Shit went down while writting name");
            e.printStackTrace();
        }
    }
}
