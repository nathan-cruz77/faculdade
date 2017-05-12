public class Dummy {
    public static void main(String[] args) {
        Observed o1 = new Observed(1);
        Observed o2 = new Observed(2);
        Observed o3 = new Observed(3);
        
        ActualObserver obs_1 = new ActualObserver(1);
        ActualObserver obs_2 = new ActualObserver(2);
        ActualObserver obs_3 = new ActualObserver(3);
        
        System.out.println("============");

        o1.add_obs((Observer) obs_1);
        o1.add_obs((Observer) obs_2);
        o1.setPh(12);
        // obs_1 and obs_2 notified

        System.out.println("============");
        
        o2.add_obs((Observer) obs_2);
        o2.add_obs((Observer) obs_3);
        o2.setTemperature(19);
        // obs_2 and obs_3 notified
        
        System.out.println("============");
        
        o3.add_obs((Observer) obs_1);
        o3.add_obs((Observer) obs_2);
        o3.add_obs((Observer) obs_3);
        o3.setPressure(12);
        // obs_1, obs_2 and obs_3 notified
        
        System.out.println("============");
    }
}
