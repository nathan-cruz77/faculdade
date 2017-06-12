import java.io.*;

public class ConcreteMethoder implements Methoder {
    private String method;

    public ConcreteMethoder(String method){
        this.method = method;
    }

    public String getMethod(){
        return this.method;
    }

    public void method(BufferedWriter w){
        String s = " public void " +
                   this.method +
                   "(){ System.out.println(\"Dynamic-ish built method\"); }" +
                   " }";

        try {
            w.write(s, 0, s.length());
        } catch(Exception e){
            System.out.println("Shit went down while writting method");
            e.printStackTrace();
        }
    }
}
