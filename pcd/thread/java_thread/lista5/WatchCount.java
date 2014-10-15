
public class WatchCount implements Runnable{

	private int my_id;
	private Condition A, B;

	public void WatchCount(int t){
		this.my_id = t;
	}

	public void Imprime(){
		System.out.println("Starting watch_count(): thread " + my_id);
	}

	public synchronized void Verifica(int count, int count_limit){
		if(count < count_limit){
			System.out.println("watch_cunt(): thread " + my_id + " going into wait...\n");
			//nao sei
			System.out.println("watch_count(): thread " + my_id + " Condition signal received.\n");
			count += 125;
			System.out.println("watch_count(): thread " + my_id + " count now = " + count + ".\n");
		}
	}

	public void run(){
		Imprime();
	}

}
