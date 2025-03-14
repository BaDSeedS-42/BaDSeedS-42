package hydraulic;

/**
 * Represents the sink, i.e. the terminal element of a system
 *
 */
public class Sink extends Element {

	/**
	 * Constructor
	 * @param name name of the sink element
	 */
	public Sink(String name) {
		this.name = name;
		this.maxConnectedElements = 0;
	}
	
	public void computeFlow(double flow) {
		this.inputFlow = flow;
	}
	
	@Override
	public String printInfo() {
		return "[" + this.name + "]Sink";
	}
	
	@Override
	public void setMaxFlow(double maxFlow) {
		this.maxFlow = maxFlow;
	}
}


//=================================================================
//=================================================================
//=================================================================

// package hydraulic;

// /**
//  * Represents the sink, i.e. the terminal element of a system
//  *
//  */
// public class Sink extends Element {

// 	/**
// 	 * Constructor
// 	 * @param name name of the sink element
// 	 */
// 	public Sink(String name) {
// 		this.name = name;
// 	}

// 	@Override
// 	public void connect(Element elem) {
// 	}
// }
