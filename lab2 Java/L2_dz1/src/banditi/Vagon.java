package banditi;

import java.util.ArrayList;
import java.util.List;

public class Vagon {
	private List<Bandit> lista;
	
	public Vagon() {
		lista = new ArrayList<>();
	}
	
	public void dodajBandita(Bandit b) {
		lista.add(b);
	}
	
	public int dohvatiBrojBandita() {
		return lista.size();
	}
	
	public boolean sadrziBandita(Bandit b) {
		return lista.contains(b);
	}
	
	public void ukloniBandita(Bandit b) {
		if(sadrziBandita(b)) lista.remove(b);
	}
	
	public Bandit dohvatiBandita(int i) {
		return lista.get(i);
	}
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		boolean ima = false;
		for(Bandit tren : lista) {
			ima=true;
			sb.append(tren).append(",");
		}
		if (ima)
			sb.deleteCharAt(sb.length()-1);
		sb.append("]");
		return sb.toString();
	}
	
}
