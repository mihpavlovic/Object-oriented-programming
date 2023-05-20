package skijanje;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Staza {
	private String ime;
	private List<Deonica> staza;
	
	public Staza(String i) {
		ime = i;
		staza= new ArrayList<>();
	}
	
	public void dodaj(Deonica d) {
		staza.add(d);
	}
	
	public int broj() {
		return staza.size();
	}
	
	public double duzina() {
		double rez=0;
		for(Deonica d : staza) {
			rez+=d.duzina();
		}
		return rez;
	}
	
	public double nagib() {
		double rez=0;
		for(Deonica d : staza) {
			if(d.nagib>rez) rez = d.nagib;
		}
		return rez;
	}
	
	public char oznaka() throws GOznaka {
		//provera da li je prazna lista deonica
		if(staza.size() == 0) throw new GOznaka();

		//pravljenje niza oznaka
		char arrOznaka[];
		arrOznaka = new char [staza.size()];
		int k =0;
		for(Deonica d : staza) {
			arrOznaka[k]=d.oznaka;
			k++;
		}
		char max, tren;
		int trenP, maxP;
		max=arrOznaka[0];
		maxP=0;
		for(int i = 0; i < arrOznaka.length;i++)
		{
			tren = arrOznaka[i];
			trenP=1;
			for(int j = i+1; j<arrOznaka.length;j++)
			{
				if(tren == arrOznaka[j]) trenP++;
			}
			if(trenP>maxP)
			{
				max=tren;
				maxP=trenP;
			}
		}
		
		
		/*
		Arrays.sort(arrOznaka);
		
		//pronalazak najcesceg elementa
		char max, tren;
		int trenP=0, maxP=0;
		max=arrOznaka[0];
		tren = max;
		trenP=maxP=1;
		for(int j =1; j<arrOznaka.length;j++) {
			if(arrOznaka[j]==tren) {
				trenP++;
				if(trenP>maxP) {
					maxP=trenP;
					max=tren;
				}
			}
			else {
				tren=arrOznaka[j];
				trenP=1;
			}
		}*/
		arrOznaka=null;
		return max;
		
	}

	public double vreme(double v) {
		double speed=v;
		double t=0;
		for(Deonica d : staza) {
			t += d.vreme(speed);
			speed = d.brzina(speed);
		}
		return t;
	}
	
	public double brzina(double v) {
		double speed=v;
		for(Deonica d : staza) {
			speed = d.brzina(speed);
		}
		return speed;
	}
	

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(ime).append("|").append(broj()).append("|").append(duzina()).append("|").append(nagib()).append('\n');
		sb.append("[");
		boolean ima=false;
		for(Deonica d: staza) {
			ima=true;
			sb.append(d).append(",");
		}
		if(ima)
			sb.deleteCharAt(sb.length()-1);
		sb.append("]");
		return sb.toString();
	}

	
}
