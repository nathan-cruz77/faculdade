import java.util.*;

public class AllCommand implements Command {
    public Object execute(int i, String j){
        return FileUtil.readDb();
    }
}
