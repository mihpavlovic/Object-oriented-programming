package skijanje;

public class Teska extends Deonica {

	public Teska(double duz, double nag) {
		super(duz, nag);
		super.oznaka = 'T';
		double rez = 9.81 * Math.sin(super.nagib *Math.PI /180);
		super.ubrzanje=rez;
	}

	@Override
	public double ubrzanje() {
		return super.ubrzanje;
	}

	@Override
	public char oznaka() {
		return super.oznaka;
	}

}
