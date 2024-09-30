//  Shape.java
package shapes;

public abstract class Shape {
	protected String name;
	protected String id;
	static int counter =0;
	Point origin;
	public abstract double area();
	public abstract double perimeter();
  public abstract double volume();
	
	
	public Shape(double x_origin, double y_origin, String name){
		
		origin = new Point(x_origin,y_origin);
		this.name = new String(name);
		counter++;
		id = "Abstract Parent";
	}
	
	public Object clone() throws CloneNotSupportedException {
		Shape obj = (Shape) super.clone();
		obj.origin = (Point) origin.clone();
		return obj;
	}

	public void setName(String name)
	{
		this.name = name;
	}
	
	public String getOid()
	{
		return id;
	}
	public Point  getOrigin()   
	{
		return origin;
	}
	
	public String  getName()   
	{
		return name;
	}  
	
	double  distance(   Shape  other)
	{
		return origin.distance(other.origin);
	}
	
	double  distance(   Shape  the_shape,    Shape  other)
	{
		return Point.distance(the_shape.origin, other.origin);
	}
	
	
	void  move(double dx, double dy)
	{
		origin.setx(origin.getx()+dx);
		origin.sety(origin.gety()+dy);
	}
	
	public String toString()
	{
		String s = "\nShape name: " + name + "\nShape Id: " + id + "\nOrigin: " + origin;
		return s;
	}
	
	public static int count()
	{
		return counter;
	}
	
}

