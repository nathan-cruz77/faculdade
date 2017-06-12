import java.io.*;

public class ClassTemplate {
    private Namer namer;
    private Extender extender;
    private Methoder methoder;

    public ClassTemplate(){}
    public ClassTemplate(Namer n, Extender e, Methoder m){
        this.setNamer(n);
        this.setExtender(e);
        this.setMethoder(m);
    }

    public void setNamer(Namer n){ this.namer = n; }
    public void setExtender(Extender e) { this.extender = e; }
    public void setMethoder(Methoder m) { this.methoder = m; }

    public void buildClass() throws IOException {
        String filename = this.namer.getName() + ".java";
        BufferedWriter writer = null;

        try {
            writer = new BufferedWriter(new FileWriter(filename));
            this.namer.name(writer);
            this.extender.extend(writer);
            this.methoder.method(writer);
        } catch(Exception e) {
            System.out.println("Some shit went down!!!");
            e.printStackTrace();
        } finally {
            writer.close();
        }
    }
}
