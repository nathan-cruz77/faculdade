public class Dummy {
    public static void main(String[] args){
        Subject real_sub = new ActualSubject();
        Subject fake_sub = new SubjectProxy(real_sub);

        Client c1 = new Client(fake_sub);
        Client c2 = new Client(real_sub);

        System.out.println("======== Real subject ========");
        c2.remoteOperation();
        System.out.println("==============================\n");

        // Using proxy
        System.out.println("============ Proxy ===========");
        c1.remoteOperation();
        System.out.println("==============================\n");
    }
}
