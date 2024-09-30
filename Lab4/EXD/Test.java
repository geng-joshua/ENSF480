// Test.java

import celestialBody.*;
import interfaces.*;
import shapes.*;
import exceptions.*;

public class Test {
	public static void main(String args[]) throws RadiusException, MoreThanLimitException {
		
		Point X = new Point(2, 2);
		Point Y = new Point(12, 21);
		
		System.out.print("Printing point X: should be at origin: (2, 2)");
		System.out.println(X);
		
		System.out.print("Priting point Y: should be at (12, 21):");
		System.out.println(Y);
		
		try{
			Point Z = (Point) X.clone();
			System.out.println(Z);
		}
		catch(CloneNotSupportedException c){
			System.out.println("clone failed to build the copy of a Point.");
		}
		
		Point [] point_array = new Point [11];
		for(int i=0; i< 11 ; i++)
			point_array[i] = new Point(100.00 + i, 200.00 + i);
		
		Moon [][] M = new Moon [2][];
		M[0] = new Moon [2];
		M[1] = new Moon [3];
		M[0][0] = new Moon(point_array[0], 1, "Hard Rock Moon", 443.211);
		M[0][1] = new Moon(point_array[1], 5, "Soft Rock Moon", 434312.3);
		M[1][0] = new Moon(point_array[2], 1, "Monkey Land", 9998);
	    M[1][1] = new Moon(point_array[3], 3, "Far Island", 9);
		M[1][2] = new Moon(point_array[4], 9, "Planet of the Apes", 32);
		try{
		    M[1][2]= new Moon(point_array[5],  11, "Black Rocks", 12);
		}catch(MoonRadiusException e){
			System.out.println("Moon Black Rocks was rebuilt. With the radius of 10.");
			M[1][2]= new Moon(point_array[6],  10, "Black Rocks", 12);
		}
				
		//Create planets
			
		Planet [] P = new Planet [2];
		try{
			
		  P[0] = new Planet(point_array[7], 10001311.0, "H4X0rZ", 600.00, M[0] );
		  P[1] = new Planet(point_array[8], 10021, "Tatooine", 10.00, M[1]);
		}
		catch (MoreThanLimitException s){
			System.out.println(s.getMessage() + " will be set to: 1" ) ;
			Moon [] NewMoon = new Moon[1];
			NewMoon[0] = new Moon (point_array[9], 9, "Mooni", 30);
			P[1] = new Planet(point_array[8], 10021, "Tatooine", 10.00, NewMoon);
		}
		//Test toString() method
		System.out.println(P[0]);
		System.out.println(P[1]);

		//Create the sun, its planets, and their moons
		Sun S = new Sun(point_array[10],1123, "the SUN", 10009999,P);
		System.out.println(S);
		// Testing interfaces
		System.out.println("\nTesting interfaces ..........");
		Circle small = new Circle(23, 25, 10, "small");
		access(small);
	} //END OF MAIN METHOD
	
	static public void access (Lab0implementable ac){
		ac.setName(ac.getName() );
		try{
			ac.setRadius(ac.getRadius() + 10) ;
	  }catch(RadiusException e){
		  System.out.println("In function access: ");
	  }
	
		System.out.println("Name: " + ac.getName());
		System.out.println("Object id: " + ac.getOid());
		System.out.println("Object's radius: " + ac.getRadius());		
		System.out.println("Object's Area: " + ac.area());
	}// END OF ACCESS METHOD
	
	
}
