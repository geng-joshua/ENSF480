//File: Planet.java
package celestialBody;

import shapes.Point;
import exceptions.*;
import interfaces.*;

//import java.io.*;
import java.lang.String;

public class Planet extends CelestialBody implements Accessible, Calculable {	
	static private int counter = 0;
	private Moon[] moons;
	private int num_moons;
	private double orbital_distance;
	
	public Planet(Point p, double radius, String name, double distance, 
	               Moon[] moons) throws MoreThanLimitException, RadiusException {
		super(p, radius, "Planet: " + name);
		Oid = "Planet" + ++counter;
		orbital_distance = distance;
		num_moons = moons.length;
		this.moons = moons;
		
		if(num_moons > 5) {
			throw new MoreThanLimitException("Planet");
		}
	}
	
	public String toString() {
		//Create the header for the string (does not change regardless of number of moons)
		String temp = "\n\n Name: " +"\"" + name  + "\""+ " Object ID: " + 
		Oid +  "\n ---------------------\n Radius: " + radius +  
		"\n Area: " + area() + center + "\n Orbital Distance: " + orbital_distance +
		"\n Number of moons: " + num_moons;
		
		//Add list of moons
		for(int i = 0; i<num_moons; i++)
			//If there is no moon here, dont add it (would cause null pointer exception)
			if(moons[i] != null)
				temp += moons[i].toString();
		
		return temp;
	}
	
	public void setName(String newname) {
		name = "Planet: " + newname;
	}
	
	@Override
	public double area() {
		return (4 * 3.14 *radius*radius);
	}
	//END OF CLASS          

	@Override
	public double perimeter() {
		return (2 * 3.14 *radius);
	}
}
