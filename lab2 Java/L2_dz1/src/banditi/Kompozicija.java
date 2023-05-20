package banditi;

import java.util.ArrayList;
import java.util.List;

public class Kompozicija {
	List<Vagon> lista;
	
	public Kompozicija() {
		lista = new ArrayList<>();
	}
	
	
	public void dodajVagon(Vagon v) {
		lista.add(v);
	}
	
	public Vagon dohvatiVagon(Bandit b) throws GNepostojeciVagon {
		for(Vagon tren : lista) {
			if(tren.sadrziBandita(b)) return tren;
		}
		throw new GNepostojeciVagon();
	}
	
	public Vagon dohvatiSusedniVagon(Vagon v, Smer sm) throws GNepostojeciVagon {
		if(v==null) throw new GNepostojeciVagon();
		int index = lista.indexOf(v);
		if(index == -1 || (index==lista.size()-1 && sm==Smer.IZA) || (index ==0 && sm ==Smer.ISPRED)) {
			throw new GNepostojeciVagon();
		}
		if(sm == Smer.IZA) index++;
		else index--;
		return lista.get(index);
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		boolean ima = false;
		for(Vagon tren : lista) {
			ima=true;
			sb.append(tren).append("_");
		}
		if (ima)
			sb.deleteCharAt(sb.length()-1);
		return sb.toString();
	}
	public static void main(String[] args) {
		Kompozicija k = new Kompozicija();
		Vagon v = new Vagon();
		k.dodajVagon(v);
		System.out.println(k);
	}

}
