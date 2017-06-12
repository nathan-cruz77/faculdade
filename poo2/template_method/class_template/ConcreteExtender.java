import java.io.*;

public class ConcreteExtender implements Extender {
    private String extension;

    public ConcreteExtender(String extension){
        this.extension = extension;
    }

    public String getExtension(){
        return this.extension;
    }

    public void extend(BufferedWriter w){
        String s;

        if(this.extension == null || this.extension.isEmpty())
            s = "{ ";
        else
            s = "extends " + this.extension + " { ";

        try {
            w.write(s, 0, s.length());
        } catch(Exception e){
            System.out.println("Shit went down while writting extension");
            e.printStackTrace();
        }
    }
}
