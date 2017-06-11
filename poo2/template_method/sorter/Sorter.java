import java.util.*;

public class Sorter implements Comparator<String> {
    public int compare(String arg_1, String arg_2) {
        char char_1 = lastChar(arg_1);
        char char_2 = lastChar(arg_2);

        if(char_1 > char_2) return 1;
        if(char_1 == char_2) return 0;
        return -1;
    }

    private char lastChar(String s){
        return s.charAt(s.length() - 1);
    }
}
