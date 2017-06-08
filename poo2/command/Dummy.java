import java.util.*;

public class Dummy {
    public static void main(String[] args){
        HashMap<String, Command> commands = new HashMap<String, Command>();
        commands.put("all", new AllCommand());
        commands.put("get", new GetCommand());
        commands.put("delete", new DeleteCommand());
        commands.put("new", new NewCommand());

        Scanner stdin = new Scanner(System.in);
        String command = stdin.next();

        int id = -1;
        String name = "";

        if(command != "all")
            id = stdin.nextInt();

        if(command == "new")
            name = stdin.next();

        commands.get(command).execute(id, name);
    }
}
