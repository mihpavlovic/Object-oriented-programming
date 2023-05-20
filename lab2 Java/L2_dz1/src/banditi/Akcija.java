package banditi;

public abstract class Akcija {
	protected Kompozicija kompozicija;
	
	public Akcija(Kompozicija k) {
		kompozicija=k;
	}
	
	public abstract void izvrsi(Bandit b);
}
