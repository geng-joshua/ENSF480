//File: Sun.java
package celestialBody;

import shapes.Point;
import exceptions.*;
import interfaces.*;

import java.io.*;
import java.lang.String;

public class Sun extends CelestialBody {
	
	private double min_distance;
	Planet[] planets;
	int num_planets;
	static private int counter = 0;
	
	public Sun(Point p, double radius, String name, double distance, Planet[]planets) throws MoreThanLimitException, RadiusException
	{
		super(p, radius, "Sun: " + name);
		min_distance = distance;
		num_planets = planets.length;
		Oid = "Sun" + ++counter;
		this.planets = planets;
		
		if(num_planets > 5){

			throw new MoreThanLimitException("Sun ");
		}
	}
  
	public String toString() {
		//Create the string header (does not change regardless of number of planets)
		String temp =  "\nName: " +"\"" + name  + "\"" + " Object ID: " + 
		Oid + "\n---------------------\nRadius: " + radius +  
		"\nArea: " + area() + center + 
		"\nMinimum Approach Distance: " + min_distance + "\nNumber of Planets: " +
		num_planets;
		
		//Add list of moons
		for(int i = 0; i<num_planets; i++)
			//If there is no planet at this location, don't add it (would cause null pointer exception)
			if(planets[i] != null)
				temp += planets[i].toString();
		
		return temp;
	}

	public void setName(String newname) {
		name = "Sun: " + newname;
	}
	
	@Override	
	public double area() {
		return (4 * 3.1415 * radius * radius);
	}

	@Override
	public double perimeter() {
		return (2 * 3.1415 * radius);
	}
	
	
	//END OF CLASS
}
