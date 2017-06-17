import java.io.*;
import java.util.*;

public class CommandReader{
    private InputStream input;
    private HashMap<String, Command> commands;

    public CommandReader(HashMap<String, Command> commands, FileInputStream stream){
        this.commands = commands;
        this.input = stream;
    }

    public void readCommands() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(input));

        String line;
        while((line = br.readLine()) != null) {
            int id = -1;
            String name = "";
            String command = line.split(" ")[0];

            System.out.println("\n===========================================");
            System.out.println("+" + line);

            if(!command.equals("all")) id = Integer.parseInt(line.split(" ")[1]);
            if(command.equals("new")) name = line.split(" ")[2];

            System.out.println("[DEBUG] Command: " + command);
            System.out.println("[DEBUG] Id: " + id);
            System.out.println("[DEBUG] Name: " + name);

            System.out.println("-" + this.commands.get(command).execute(id, name));
            System.out.println("===========================================");
        }
    }
}
