import java.util.Enumeration;

public class Client {
    private OldApiProvider api_provider;

    public Client(OldApiProvider api_provider) {
        this.api_provider = api_provider;
    }

    public void consume_api(){
        while(this.api_provider.hasMoreElements()){
            System.out.print(this.api_provider.nextElement() + " ");
        }

        System.out.println();
    }
}
