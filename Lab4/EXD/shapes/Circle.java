// Circle.java
package shapes;
import exceptions.*;
import interfaces.*;

public class Circle extends Shape implements Lab0implementable{
	private double radius;
	static int id_counter = 0;
	
	public Circle(double x_origin, double y_origin, double radius,  String name)throws RadiusException
	{
		super(x_origin, y_origin, name);
	
		if(radius < 0){
			throw new RadiusException(this, "Circle Radius");
		}
		else
			this.radius = radius;
		id = "C" + ++id_counter;
		
	}
	
	public Object clone() throws CloneNotSupportedException {
		Circle obj = (Circle) super.clone();
		return obj;
	}

	public String getOid(){return id;}
	
	public void setRadius (double radius) throws RadiusException{
		if(radius < 0)
			throw new RadiusException(this, "Circle Radius");
			else
				this.radius = radius;
	}
	
	public double getRadius() 
	{
		return radius;
	}
	
	// to be added
	public void setName(String newname) {
		name = "Circle " + newname;
	}

	
	public double area() 
	{
		return Math.PI * Math.pow(radius, 2);
	}
	
	public double perimeter() 
	{
		return 2 * Math.PI * radius;
	}
	
	public double  volume()
	{
		return 0;
	}
	
	
	public String toString()
	{
		String s = super.toString()+ "\nRadius: " + radius;
		return s;
	}
	
}