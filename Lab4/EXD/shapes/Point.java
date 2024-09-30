package shapes;

public class Point{
	private double x_coordinate, y_coordinate;
	static int counter = 0;
	String id;
	
	public Point(double a, double b)
	{
		x_coordinate = a;
		y_coordinate = b;
		id = "P" + ++counter;
	}
	
	public String toString()   
	{
		String s;
		s = "\nPoint Id: " + id + "\nX_coordinate: " + x_coordinate +  "\nY-coordinate: " + y_coordinate;
		return s;
	}
	
	public double  getx()   
	{
		return x_coordinate;
	}
	
	void  setx(double newvalue)
	{
		x_coordinate = newvalue;
	}
	
	public double  gety()   
	{
		return y_coordinate;
	}
	
	public void  sety(double newvalue)
	{
		y_coordinate = newvalue;
	}
	
	public double  distance(Point  other)
	{
		double dist_x = other.x_coordinate - x_coordinate;
		double dist_y = other.y_coordinate - y_coordinate;
		
		return (Math.sqrt(Math.pow(dist_x, 2) + Math.pow(dist_y, 2)));
	}
	
	static double  distance (Point  that, Point  other)
	{
		double dist_x = other.x_coordinate - that.x_coordinate;
		double dist_y = other.y_coordinate - that.y_coordinate;
		
		return (Math.sqrt(Math.pow(dist_x, 2) + Math.pow(dist_y, 2)));
	}
	
	public static int count()
	{
		return counter;
	}
	
	public Object clone() throws CloneNotSupportedException {
		return super.clone();
		
	}
	
	public static void main(String [] args)
	{
		Point a = new Point (5, 6);
		Point b = new Point (45, 69);
		System.out.println(a.distance(b));
		Point.distance(a, b);
		System.out.println(a);
		
	}
}