import java.util.*;

public class NewCommand implements Command {
    public Object execute(int id, String name){
        List<Person> db = FileUtil.readDb();
        db.add(Person.create(id, name));
        FileUtil.writeDb(db);

        return null;
    }
}
