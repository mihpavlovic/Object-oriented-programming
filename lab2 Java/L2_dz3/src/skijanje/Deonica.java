package skijanje;


public abstract class Deonica {
	protected double duzina;
	protected double nagib;
	protected double ubrzanje;
	protected char oznaka;
	
	public Deonica(double duz, double nag) {
		duzina=duz;
		nagib=nag;
	}

	public double duzina() {
		return duzina;
	}

	public double nagib() {
		return nagib;
	}
	
	public double vreme(double v) {
		double krajnja=this.brzina(v);
		double t = (krajnja - v) / ubrzanje;
		return t;
		
	}
	
	public double brzina(double v) {
		double krajnja = Math.sqrt(2 * ubrzanje * duzina + v*v);
		return krajnja;
	}
	
	public abstract double ubrzanje();

	public abstract char oznaka();

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(oznaka()).append("(").append(duzina()).append(",").append(nagib()).append(")");
		return sb.toString();
	}
	
	
	
}
