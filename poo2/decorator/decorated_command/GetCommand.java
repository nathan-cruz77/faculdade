import java.util.*;

public class GetCommand implements Command {
    public Object execute(int id, String name){
        List<Person> db = FileUtil.readDb();

        for(Person p: db){
            if(p.getId() == id) return p;
        }

        return null;
    }
}
