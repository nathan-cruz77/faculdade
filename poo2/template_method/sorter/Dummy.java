import java.util.*;

public class Dummy {
    public static void main(String[] args) {
        String[] strings = {
            "string4",
            "string1",
            "string3"
        };

        System.out.println("==================== Unsorted ===================");
        for(String s: strings){ System.out.println(s); }
        System.out.println("=================================================");
        Arrays.sort(strings, new Sorter());
        for(String s: strings){ System.out.println(s); }
        System.out.println("==================== Sorted =====================");
    }
}
