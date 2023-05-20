package revija;

public class Kombinacija {
	private int n;
	private int tren;
	private Nosivo niz[];
	
	public Kombinacija(int broj){
		niz = new Nosivo[broj];
		n=broj;
		tren=0;
	}

	public int dohvMaxBrStvari() {
		return n;
	}

	public int dohvBrStvari() {
		return tren;
	}
	
	public void dodaj(Nosivo zaDodavanje) throws GDodavanje {
		if(tren>=n) throw new GDodavanje();
		niz[tren]=zaDodavanje;
		this.tren++;
	}
	
	public Nosivo dohvStvar(int indeks) throws GIndeks {
		if(indeks < 0 || indeks >=n || niz[indeks] ==null) 
			throw new GIndeks();
		return niz[indeks];
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		boolean ima = false;
		for(Nosivo tr: niz) {
			ima=true;
			if(tr!=null)
				sb.append(tr).append(",");
		}
		if (ima)
			sb.deleteCharAt(sb.length()-1);
		sb.append("]");
		return sb.toString();
	}
	public static void main(String[] args) {
		
	}
	
	
	
}
