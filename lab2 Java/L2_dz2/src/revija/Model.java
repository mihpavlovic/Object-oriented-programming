package revija;

public class Model {
	private static int totalID=0;
	private int ID;
	Velicina velicina;
	
	public Model(Velicina v){
		ID=totalID++;
		velicina=v;
	}
	
	public int dohvId() {
		return ID;
	}

	public Velicina dohvVelicinu() {
		return velicina;
	}

	@Override
	public String toString() {
		return "Model " + ID + " ("+ velicina + ")";
	}
/*
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
*/
}
