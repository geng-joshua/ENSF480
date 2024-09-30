//MoonRadiusException.java
package exceptions;
import interfaces.*;
public class MoonRadiusException extends RadiusException {
	public MoonRadiusException(Accessible a, String msg){
		super(a, msg + " out of bound in object: " + a.getOid());
  }
}