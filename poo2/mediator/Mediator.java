public interface Mediator {
    public void send(String msg, Colleague c);
    public void addColleague(Colleague c);
}
