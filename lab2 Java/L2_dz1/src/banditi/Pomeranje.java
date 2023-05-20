package banditi;

public class Pomeranje extends Akcija {
	
	private Smer smer;
	
	public Pomeranje(Kompozicija k, Smer sm) {
		super(k);
		smer = sm;
	}
	
	@Override
	public void izvrsi(Bandit b) {
		try {
		Vagon v1 = super.kompozicija.dohvatiVagon(b);
		Vagon v2=super.kompozicija.dohvatiSusedniVagon(v1, smer);
		v1.ukloniBandita(b);
		v2.dodajBandita(b);
		}
		catch (GNepostojeciVagon e) {}

	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("Pomeranje: ").append(smer);
		return sb.toString();
	}

}
