package revija;

public class Velicina {
	public enum Oznaka{
		S,
		M,
		L;
	}
	private Oznaka oznaka;
	
	public Velicina (Oznaka o){
		oznaka=o;
	}
	
	
	public Oznaka dohvOznaku() {
		return oznaka;
	}
	
	public boolean manja (Velicina druga) {
		if(this.oznaka.compareTo(druga.oznaka)>=0)
			return false;
		return true;
		
		
	}
	
	@Override
	public String toString() {
		return oznaka.toString();
	}
	/*
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Velicina v1= new Velicina(Velicina.Oznaka.S);
		Velicina v2= new Velicina(Velicina.Oznaka.M);
		System.out.println(v1 + " " + v2);
		System.out.println(v2.manja(v1));
	}*/
}
