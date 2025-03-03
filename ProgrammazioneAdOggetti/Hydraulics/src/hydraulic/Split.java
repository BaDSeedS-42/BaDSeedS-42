package hydraulic;

/**
 * Represents a split element, a.k.a. T element
 * 
 * During the simulation each downstream element will
 * receive a stream that is half the input stream of the split.
 */

public class Split extends Element {

	/**
	 * Constructor
	 * @param name name of the split element
	 */
	public Split(String name) {
		this.name = name;
		this.maxConnectedElements = 2;
		this.connectedElements = new Element[this.maxConnectedElements];
		this.outputFlow = new double[this.maxConnectedElements];
	}
	
	@Override
	public void connect(Element elem) {
		this.connectedElements[0] = elem;
	}
	
	@Override
	public void connect(Element elem, int index) {
		this.connectedElements[index] = elem;
	}
	
	@Override
	public Element[] getOutputs() {
		return this.connectedElements;
	}
	
	public void computeFlow(double flow) {
		this.inputFlow = flow;
		this.outputFlow[0] = flow / 2;
		this.outputFlow[1] = flow / 2;
	}
	
	@Override
	public String printInfo() {
		return "[" + this.name + "]Split ";
	}
	
	@Override
	public int getConnectedElements() {
		int i, n = 0;
		for(i = 0; i < this.maxConnectedElements; i++) {
			if(this.connectedElements[i] != null) {
				n++;
			}
		}
		return n;
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
//  * Represents a split element, a.k.a. T element
//  * 
//  * During the simulation each downstream element will
//  * receive a stream that is half the input stream of the split.
//  */

// public class Split extends Element {

// 	Element[] outputs = new Element[2];

// 	/**
// 	 * Constructor
// 	 * @param name name of the split element
// 	 */
// 	public Split(String name) {
// 		this.name = name;
// 	}

// 	public void connect(Element elem, int index){
// 		outputs[index] = elem;
// 	}
// }
