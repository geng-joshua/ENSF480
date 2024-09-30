//File: Moon.java
package celestialBody;

import shapes.Point;
import exceptions.*;
import java.lang.String;

public class Moon extends CelestialBody {
	static private int counter = 0;
	private double distance_from_planet;

	
	public Moon(Point p, double radius, String name, double pl_distance) throws MoonRadiusException, RadiusException {
		super(p, radius, "Moon: " + name);
		if(radius > 10.00){
			throw new MoonRadiusException(this, "Moon Radius");
		}
		else
			this.radius = radius;
		Oid = "Moon" + ++counter;
		distance_from_planet = pl_distance;
	}
	
	public String toString() {
		return ( "\n  Name: " +"\"" + name  + "\"" + " Object ID: " + Oid +
						"\n  ---------------------\n  Radius: " + radius +  
						"\n  Area: " + area() + center + "\n  Distance from planet: " + distance_from_planet);
	}

	@Override	
	public double area() {
		return 4*3.14*radius*radius;
	}
	
	public void setRadius(double radius)throws MoonRadiusException{
		if(radius > 10.00)
			throw new MoonRadiusException(this, "Moon Radius");
		else
			this.radius = radius;
	}
		
	public void setName(String newname) {
		name = "Moon " + newname;
	}

	@Override
	public double perimeter() {
		return 2*3.14*radius;
	}	
	//END OF CLASS
}
