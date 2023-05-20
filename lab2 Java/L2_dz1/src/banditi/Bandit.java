package banditi;

public class Bandit {
	
	public enum Tim{
		A,
		B;
	}
	
	private Tim tim;
	private int zlatnici;
	
	public Bandit(Tim t) {
		tim=t;
		zlatnici=50;
	}

	public int dohvatiBrojZlatnika() {
		return zlatnici;
	}

	public void promeniBrojZlatnika(int zl) {
		this.zlatnici += zl;
	}

	public Tim dohvatiTim() {
		return tim; 
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(tim).append(zlatnici);
		return sb.toString();
		
	}
	
	
	
	
}
