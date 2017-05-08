public class Dummy {
  public static void main(String[] args){
    Article a1 = new Article("Mastering bullshit", new String[]{"Bla", "Zumba"});
    Article a2 = new Article("Mastering Lich King Strategy", new String[]{"Murigod", "Hahahá"});
    Article a3 = new Article("Single point of failure", new String[]{"Bla", "Hahahá"});

    PublicationCollection journal, magazine, notebook;

    magazine = new PublicationCollection("MAGAZINE - I have no idea what it all means");
    magazine.addPublication(a1);

    notebook = new PublicationCollection("NOTEBOOK - INhuman");
    notebook.addPublication(a2);
    notebook.addPublication(magazine);

    journal = new PublicationCollection("JOURNAL - FIRE");
    journal.addPublication(a3);
    journal.addPublication(notebook);

    System.out.println("\nTotal publications on Journal: " + journal.countPublications());
    System.out.println("\nPublications:\n" + journal.toString());
  }
}
