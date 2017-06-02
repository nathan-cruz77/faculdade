public class NameFactory {
    public static Name create(String unparsed){
        if(unparsed.contains(","))
            return new NameWithCommaCreator().create(unparsed);
        return new NameWithoutCommaCreator().create(unparsed);
    }
}
