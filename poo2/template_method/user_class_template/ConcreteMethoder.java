import java.io.*;

public class ConcreteMethoder implements Methoder {
    private String method;
    private String message;

    public ConcreteMethoder(String method, String msg){
        this.method = method;
        this.message = msg;
    }

    public String getMethod(){
        return this.method;
    }

    public void method(BufferedWriter w){
        String s = " public void " +
                   this.method +
                   "(){ System.out.println(\"" + this.message +"\"); }" +
                   " }";

        try {
            w.write(s, 0, s.length());
        } catch(Exception e){
            System.out.println("Shit went down while writting method");
            e.printStackTrace();
        }
    }
}
