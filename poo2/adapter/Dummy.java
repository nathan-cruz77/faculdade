public class Dummy {
    public static void main(String[] args){
        OldApiProvider old_provider = new OldApiProvider(10);
        Client client = new Client(old_provider);
        client.consume_api();

        Adapter adp = new Adapter(5);
        Client another_client = new Client(adp);
        another_client.consume_api();
    }
}
