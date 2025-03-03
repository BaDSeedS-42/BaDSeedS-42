package hydraulic;

/**
 * Represents a source of water, i.e. the initial element for the simulation.
 *
 * Lo status of the source is defined through the method
 * {@link #setFlow(double) setFlow()}.
 */
public class Source extends Element {
	
	/**
	 * constructor
	 * @param name name of the source element
	 */
	public Source(String name) {
		this.name = name;
		this.maxConnectedElements = 1;
		this.connectedElements = new Element[this.maxConnectedElements];
		this.outputFlow = new double[this.maxConnectedElements];
	}
	
	@Override
	public void connect(Element elem) {
		this.connectedElements[0] = elem;
	}
	
	@Override
	public Element getOutput(){
		return connectedElements[0];
	}

	/**
	 * Define the flow of the source to be used during the simulation
	 *
	 * @param flow flow of the source (in cubic meters per hour)
	 */
	public void setFlow(double flow){
		this.inputFlow = flow;
	}
	
	@Override
	public String printInfo() {
		return "[" + this.name + "]Source ";
	}
	
	@Override
	public int getConnectedElements() {
		if(this.connectedElements[0] == null) {
			return 0;
		}
		return 1;
	}

}


//=================================================================
//=================================================================
//=================================================================

// package hydraulic;

// /**
//  * Represents a source of water, i.e. the initial element for the simulation.
//  *
//  * Lo status of the source is defined through the method
//  * {@link #setFlow(double) setFlow()}.
//  */
// public class Source extends Element {
// 	Double flow;

// 	/**
// 	 * constructor
// 	 * @param name name of the source element
// 	 */
// 	public Source(String name) {
// 		this.name = name;
// 	}

// 	@Override
// 	public void connect(Element elem) {
// 		nexElement = elem;
// 	}

// 	/**
// 	 * Define the flow of the source to be used during the simulation
// 	 *
// 	 * @param flow flow of the source (in cubic meters per hour)
// 	 */
// 	public void setFlow(double flow){
// 		this.flow = flow;
// 	}

// }
