public class Article implements Publication {
  private String name;
  private String[] authors;

  public Article(String name, String[] authors){
    this.name = name;
    this.authors = authors;
  }

  public String toString(){
    String res = "\n==============\nTítulo: " + this.name + "\n";

    res += "Autores: ";
    res += String.join(", ", this.authors);

    return res + "\n==============\n";
  }

  public int countPublications(){ return 1; }
}
