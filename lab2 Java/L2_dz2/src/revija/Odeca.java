package revija;

public class Odeca implements Nosivo {
	private String naziv;
	private Velicina velicina;
	
	public Odeca(String ime, Velicina v){
		naziv=ime;
		velicina=v;
	}

	public String dohvNaziv() {
		return naziv;
	}

	public Velicina dohvVelicinu() {
		return velicina;
	}
	
	@Override
	public boolean odgovara(Model m) {
		// TODO Auto-generated method stub
		Velicina velModela = m.dohvVelicinu();
		//ako su iste vrati true
		if(m.dohvVelicinu().dohvOznaku()== velicina.dohvOznaku())
			return true;
		//ako nisu vidi odnos
		else
			return velModela.manja(this.velicina);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "odeća " + naziv +" " +velicina;
	}
}
