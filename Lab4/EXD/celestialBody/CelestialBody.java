
//File: CelestialBody.java
 package celestialBody;

 import shapes.Point;
 import exceptions.*;
 import interfaces.*;

// import java.io.*;
// import java.lang.*;

abstract public class CelestialBody implements Cloneable, Lab0implementable{
	
	protected Point center;
	protected double radius;
	protected String name;
	static private int counter = 0;
	protected String Oid;
	
	public CelestialBody(Point p, double radius, String name) throws RadiusException {
		center = p;
		Oid = "CB" + ++counter;
		
		if(radius < 0)
			throw new RadiusException(this, "Celestial Body Radius");
		else
			this.radius = radius;
			
		this.name = name;
	}
	
	
	
	public Object clone() throws CloneNotSupportedException {
		CelestialBody obj = (CelestialBody) super.clone();
		obj.center = (Point) center.clone();
		return obj;
	}
	
	public String toString() {
		return ( "\nName: " + name + "Object ID: " + Oid +
						"\n---------------------\nRadius: " + radius +  
						"\n" + center  );
	}
	
	public void setRadius(double radius)throws RadiusException
	{
		if(radius < 0){
			throw new RadiusException(this, "Celestial Body Radius");
		}
		else
			this.radius = radius;
	}
	
	
	public double getRadius()
	{
		return radius;
	}
	
	
	public void setName(String newname) {
		name = "Celestial Body:" + newname;
	}
	
	public String getName() {
		return name;
	}
	
	public String getOid() {
		return Oid;
	}	
}  
//END OF CLASS


