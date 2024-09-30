//RadiusException.java

package exceptions;

import interfaces.*;

public class RadiusException extends Exception {
	public RadiusException(Accessible a, String msg){
		super(msg + " out of bound in object: " + a.getOid());
  }
}