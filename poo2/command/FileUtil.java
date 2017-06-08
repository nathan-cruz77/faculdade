import java.util.*;
import java.io.*;

public class FileUtil {
    public static List<Person> readDb(){
        List<Person> people = new ArrayList<Person>();

        for(String data: readDbFile("dummy.db")){
            String[] parts = data.split(" ");

            int id = Integer.parseInt(parts[0]);
            String name =  "";
            for(int i = 1; i < parts.length; i++){ name += parts[i]; }

            people.add(Person.create(id, name));
        }

        return people;
    }

    public static void writeDb(List<Person> people){
        List<String> data = new ArrayList<String>();
        for(Person p: people){
            data.add(p.toString());
        }

        writeDbFile(data, "dummy.db");
    }

    public static List<String> readDbFile(String filename){
        List<String> records = new ArrayList<String>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line;

            while ((line = reader.readLine()) != null){
                records.add(line);
            }

            reader.close();
        }
        catch(FileNotFoundException e){
            return records;
        }
        catch(Exception e) {
            System.out.println("Some shit happened. =/");
            System.err.format("Exception occurred trying to read '%s'.", filename);
            e.printStackTrace();
        }

        return records;
    }

    public static void writeDbFile(List<String> data, String filename){
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename));

            for(String line: data){
                writer.write(line, 0, line.length());
                writer.newLine();
            }
            writer.close();
        }
        catch(Exception e) {
            System.out.println("Some shit happened. =/");
            System.err.format("Exception occurred trying to read '%s'.", filename);
            e.printStackTrace();
        }
    }
}
