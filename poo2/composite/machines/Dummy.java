public class Dummy {

    public static void main(String[] args){
        MachineComponent machines = new MachineComposite();
        MachineComponent sub_machine = new MachineComposite();
        
        sub_machine.add(new Machine());
        sub_machine.add(new Machine());

        machines.add(new Machine());
        machines.add(sub_machine);
        machines.add(new Machine());
        machines.add(sub_machine);
        
        System.out.println("Folhas: " + machines.getMachineCount());
    }
}
