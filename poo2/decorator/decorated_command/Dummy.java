import java.util.*;
import java.io.*;

public class Dummy {
    public static void main(String[] args) throws IOException {
        HashMap<String, Command> commands = new HashMap<String, Command>();
        commands.put("all", new AllCommand());
        commands.put("get", new GetCommand());
        commands.put("delete", new DeleteCommand());
        commands.put("new", new NewCommand());

        new CommandReader(commands, new FileInputStream("test")).readCommands();
    }
}
