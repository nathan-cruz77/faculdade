public class Dummy {
  public static void main(String[] args){
    Institution inst = new Institution();
    Person person = new Person();

    Congress cong;

    // 0
    cong = new Congress(inst);
    System.out.println("Assentos congresso_1 = " + cong.total_seats());

    // 1
    System.out.println("Participantes congresso_1 = " + cong.total_participants());

    // 1
    inst.addSon(person);
    cong = new Congress(inst);
    System.out.println("Assentos congresso_2 = " + cong.total_seats());

    // 2
    System.out.println("Participantes congresso_2 = " + cong.total_participants());
  }
}
