package hydraulic;


/**
 * Represents the generic abstract element of an hydraulics system.
 * It is the base class for all elements.
 *
 * Any element can be connect to a downstream element
 * using the method {@link #connect(Element) connect()}.
 * 
 * The class is abstract since it is not intended to be instantiated,
 * though all methods are defined to make subclass implementation easier.
 */
public abstract class Element {
	
	protected String name;
	protected int maxConnectedElements;
	protected Element connectedElements[];
	protected double inputFlow;
	protected double maxFlow;
	protected double outputFlow[];
	
	/**
	 * getter method for the name of the element
	 * 
	 * @return the name of the element
	 */
	public String getName() {
		return this.name;
	}
	
	/**
	 * Connects this element to a given element.
	 * The given element will be connected downstream of this element
	 * 
	 * In case of element with multiple outputs this method operates on the first one,
	 * it is equivalent to calling {@code connect(elem,0)}. 
	 * 
	 * @param elem the element that will be placed downstream
	 */
	public void connect(Element elem) {
		// does nothing by default
	}
	
	/**
	 * Connects a specific output of this element to a given element.
	 * The given element will be connected downstream of this element
	 * 
	 * @param elem the element that will be placed downstream
	 * @param index the output index that will be used for the connection
	 */
	public void connect(Element elem, int index){
		// does nothing by default
	}
	
	/**
	 * Retrieves the single element connected downstream of this element
	 * 
	 * @return downstream element
	 */
	public Element getOutput(){
		return null;
	}

	/**
	 * Retrieves the elements connected downstream of this element
	 * 
	 * @return downstream element
	 */
	public Element[] getOutputs(){
		return null;
	}
	
	public void computeFlow(double flow) {
		
	}
	
	public String printInfo() {
		return null;
	}
	
	public int getConnectedElements() {
		return 0;
	}
	
	/**
	 * Defines the maximum input flow acceptable for this element
	 * 
	 * @param maxFlow maximum allowed input flow
	 */
	public void setMaxFlow(double maxFlow) {
		// does nothing by default
	}
}

//==========================================================
//==========================================================
//==========================================================

// package hydraulic;


// /**
//  * Represents the generic abstract element of an hydraulics system.
//  * It is the base class for all elements.
//  *
//  * Any element can be connect to a downstream element
//  * using the method {@link #connect(Element) connect()}.
//  * 
//  * The class is abstract since it is not intended to be instantiated,
//  * though all methods are defined to make subclass implementation easier.
//  */
// public abstract class Element {
// 	String name;
	
// 	Element nexElement;
// 	Element prevElement;

// 	Element exit0;
// 	Element exit1;

// 	Element[] outputs;
	
// 	/**
// 	 * getter method for the name of the element
// 	 * 
// 	 * @return the name of the element
// 	 */
// 	public String getName() {
// 		return this.name;
// 	}
	
// 	/**
// 	 * Connects this element to a given element.
// 	 * The given element will be connected downstream of this element
// 	 * 
// 	 * In case of element with multiple outputs this method operates on the first one,
// 	 * it is equivalent to calling {@code connect(elem,0)}. 
// 	 * 
// 	 * @param elem the element that will be placed downstream
// 	 */
// 	public void connect(Element elem) {
// 		// does nothing by default
// 	}
	
// 	/**
// 	 * Connects a specific output of this element to a given element.
// 	 * The given element will be connected downstream of this element
// 	 * 
// 	 * @param elem the element that will be placed downstream
// 	 * @param index the output index that will be used for the connection
// 	 */
// 	public void connect(Element elem, int index){
// 		// does nothing by default
// 	}
	
// 	/**
// 	 * Retrieves the single element connected downstream of this element
// 	 * 
// 	 * @return downstream element
// 	 */
// 	public Element getOutput(){
// 		return nexElement;
// 	}

// 	/**
// 	 * Retrieves the elements connected downstream of this element
// 	 * 
// 	 * @return downstream element
// 	 */
// 	public Element[] getOutputs(){
// 		return outputs;
// 	}
	
// 	/**
// 	 * Defines the maximum input flow acceptable for this element
// 	 * 
// 	 * @param maxFlow maximum allowed input flow
// 	 */
// 	public void setMaxFlow(double maxFlow) {
// 		// does nothing by default
// 	}
// }
