public class NameWithoutCommaCreator implements Creator {
    public NameWithoutComma create(String unparsedName) {
        String parsedName = this.parseName(unparsedName);
        String parsedLastName = this.parseLastName(unparsedName);
        
        NameWithoutComma name = new NameWithoutComma();

        name.setName(parsedName);
        name.setLastName(parsedLastName);
        
        return name;
    }
    
    private String parseName(String unparsed){
       return unparsed.split(" ")[0];
    }
    
    private String parseLastName(String unparsed){
       return unparsed.split(" ")[1];
    }
}
