import java.util.*;

public class DeleteCommand implements Command {
    public Object execute(int id, String name){
        List<Person> db = FileUtil.readDb();
        Person person = null;

        for(Person p: db){
            if(p.getId() == id) person = p;
        }

        if(person != null){
            db.remove(person);
        }

        FileUtil.writeDb(db);
        return null;
    }
}
