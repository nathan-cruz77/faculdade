import java.util.*;

public class PublicationCollection implements Publication {
  private List<Publication> publications = new ArrayList<Publication>();
  public String name;

  public PublicationCollection(String name){
    this.name = name;
  }

  public List<Publication> getPublications(){ return this.publications; }
  public void addPublication(Publication pub){ this.publications.add(pub); }

  public String toString(){
    String res = "";

    for(Publication pub: this.publications) res += pub.toString();

    return res;
  }

  public int countPublications(){
    int sum = 0;

    for(Publication pub: this.publications) sum += pub.countPublications();

    return sum;
  }
}
