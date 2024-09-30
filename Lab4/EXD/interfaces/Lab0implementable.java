//Constants.java
package interfaces;

import exceptions.RadiusException;

public interface Lab0implementable extends Calculable, Accessible{
   
	static final int CELESTIAL = 100;
	static final int SHAPE = 200;
	static final int CIRCLE = 2000;
	static final int PLANET = 10000;
	static final int SUN = 1000;
	static final int MOON = 100000;
	abstract double getRadius();
	abstract void setRadius(double value)throws RadiusException;
}

