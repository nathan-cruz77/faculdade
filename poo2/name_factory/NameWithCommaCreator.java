public class NameWithCommaCreator implements Creator {
    public NameWithComma create(String unparsedName) {
        String parsedName = this.parseName(unparsedName);
        String parsedLastName = this.parseLastName(unparsedName);
        
        NameWithComma name = new NameWithComma();

        name.setName(parsedName);
        name.setLastName(parsedLastName);
        
        return name;
    }
    
    private String parseName(String unparsed){
       return unparsed.split(", ")[1];
    }
    
    private String parseLastName(String unparsed){
       return unparsed.split(", ")[0];
    }
}
