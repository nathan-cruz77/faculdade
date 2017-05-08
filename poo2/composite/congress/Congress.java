public class Congress {
  private Component participants;

  public Congress(Component participants){
    this.participants = participants;
  }

  public int total_seats(){
    // Account only for people
    return this.participants.getSeats();
  }

  public int total_participants(){
    // Account for insitutions && people
    return this.participants.getParticipants();
  }
}
