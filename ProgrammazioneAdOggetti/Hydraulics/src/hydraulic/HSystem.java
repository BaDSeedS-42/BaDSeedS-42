package hydraulic;

import java.util.ArrayList;
import java.util.List;

/**
 * Main class that acts as a container of the elements for
 * the simulation of an hydraulics system 
 * 
 */
public class HSystem {
	
	protected List<Element> systemComponents;
	protected int numElements;
	
	public HSystem() {
		this.systemComponents = new ArrayList<Element>();
		this.numElements = 0;
	}

// R1
	/**
	 * Adds a new element to the system
	 * @param elem the new element to be added to the system
	 */
	public void addElement(Element elem){
		//TODO: to be implemented
		this.systemComponents.add(elem);
		this.numElements++;
		
	}
	
	/**
	 * returns the element added so far to the system
	 * @return an array of elements whose length is equal to 
	 * 							the number of added elements
	 */
	public Element[] getElements(){
		//TODO: to be implemented
		int i = 0;
		Element elements[] = new Element[this.numElements];
		for(Element el: systemComponents) {
			elements[i++] = el;
		}
		return elements;
	}

// R4
	/**
	 * starts the simulation of the system
	 */
	
	private void computeFlow(SimulationObserver observer, Element elem, double flow) {
		int i;
		if(elem == null) {
			return;
		}
		else {
			elem.computeFlow(flow);
			if(elem instanceof Tap) {
				observer.notifyFlow("Tap", elem.name, elem.inputFlow, elem.outputFlow);
			}
			else if(elem instanceof Split){
				observer.notifyFlow("Split", elem.name, elem.inputFlow, elem.outputFlow);
			}
			else if(elem instanceof Sink) {
				observer.notifyFlow("Sink", elem.name, elem.inputFlow, SimulationObserver.NO_FLOW);
			}
			for(i = 0; i < elem.maxConnectedElements; i++) {
				computeFlow(observer, elem.connectedElements[i], elem.outputFlow[i]);
			}
		}
	}
	
	public void simulate(SimulationObserver observer){
		//TODO: to be implemented
		for(Element elem: systemComponents) {
			if(elem instanceof Source) {
				elem.outputFlow[0] = elem.inputFlow;
				observer.notifyFlow("Source", elem.name, SimulationObserver.NO_FLOW, elem.outputFlow);
				computeFlow(observer, elem.connectedElements[0], elem.outputFlow[0]);
			}
		}
	}

// R6
	/**
	 * Prints the layout of the system starting at each Source
	 */
	private String printInfo(Element elem, int padding, boolean plus) {
		int i, j;
		String result = "";
		if(plus) {
			result += "+";
		}
		result += "-> ";
		if(elem == null) {
			result += "*\n";
			return result;
		}
		else {
			if(elem instanceof Tap) {
				result += elem.printInfo();
				padding += result.length();
				result += printInfo(elem.connectedElements[0], padding, false);
			}
			else if(elem instanceof Split) {
				result +=  elem.printInfo();
				padding += result.length();
				result += printInfo(elem.connectedElements[0], padding, true);
				for(i = 1; i < elem.maxConnectedElements; i++) {
					result += "\n";
					for(j = 0; j < padding; j++) {
						result += " ";
					}
					result += "|\n";
					for(j = 0; j < padding; j++) {
						result += " ";
					}
					result += printInfo(elem.connectedElements[i], padding, true);
				}
			}
			else if(elem instanceof Sink) {
				result += elem.printInfo();
				return result;
			}
		}
		return result;
	}
	
	public String layout(){
		//TODO: to be implemented
		int padding = 0;
		String result = "";
		for(Element elem: systemComponents) {
			if(elem instanceof Source) {
				result += elem.printInfo();
				padding += result.length();
				result += printInfo(elem.connectedElements[0], padding, false);
				result += "\n";
			}
		}
		return result;
	}

// R7
	/**
	 * Deletes a previously added element with the given name from the system
	 */
	public boolean deleteElement(String name) {
		//TODO: to be implemented
		int i, j, indexSelected = 0, indexPrev= 0, indexNext = 0, index = 0;
		String nameNext = null;
		boolean found = false;
		for(i = 0; i < this.numElements; i++) {
			if(this.getElements()[i].name == name) {
				if(this.getElements()[i].getConnectedElements() <= 1) {
					indexSelected = i;
					if(this.getElements()[i].getConnectedElements() != 0) {
						for(j = 0; j < this.getElements()[i].maxConnectedElements; j++) {
							if(this.getElements()[i].connectedElements[j] != null)
								nameNext = this.getElements()[i].connectedElements[j].name;
						}
						for(j = 0; j < this.numElements; j++) {
							if(this.getElements()[j].name == nameNext) {
								indexNext = j;
								break;
							}
						}
					}
					break;
				}
				else {
					return false;
				}
			
			}
		}
		for(i = 0; i < this.numElements && !found; i++) {
			for(j = 0; j < this.getElements()[i].maxConnectedElements; j++) {
				if(this.getElements()[i].connectedElements[j] != null && this.getElements()[i].connectedElements[j].name == name) {
					indexPrev = i;
					index = j;
					found = true;
					break;
				}
			}
		}
		if(i < this.numElements) {
			if(nameNext != null) {
				this.getElements()[indexPrev].connectedElements[index] = this.getElements()[indexNext];
			}
			else {
				this.getElements()[indexPrev].connectedElements[index] = null;
			}
		}
		this.numElements--;
		systemComponents.remove(indexSelected);
		return true;
	}

// R8
	/**
	 * starts the simulation of the system; if {@code enableMaxFlowCheck} is {@code true},
	 * checks also the elements maximum flows against the input flow
	 */
	
	private void computeMaxFlow(SimulationObserver observer, Element elem, double flow) {
		int i;
		if(elem == null) {
			return;
		}
		else {
			elem.computeFlow(flow);
			if(elem instanceof Tap) {
				if(elem.inputFlow > elem.maxFlow) {
					observer.notifyFlowError("Tap", elem.name, elem.inputFlow, elem.maxFlow);
				}
				observer.notifyFlow("Tap", elem.name, elem.inputFlow, elem.outputFlow);
			}
			else if(elem instanceof Split){
				if(elem.inputFlow > elem.maxFlow) {
					observer.notifyFlowError("Tap", elem.name, elem.inputFlow, elem.maxFlow);
				}
				observer.notifyFlow("Tap", elem.name, elem.inputFlow, elem.outputFlow);
			}
			else if(elem instanceof Sink) {
				if(elem.inputFlow > elem.maxFlow) {
					observer.notifyFlowError("Tap", elem.name, elem.inputFlow, elem.maxFlow);
				}
				observer.notifyFlow("Tap", elem.name, elem.inputFlow, SimulationObserver.NO_FLOW);
			}
			for(i = 0; i < elem.maxConnectedElements; i++) {
				computeMaxFlow(observer, elem.connectedElements[i], elem.outputFlow[i]);
			}
		}
	}
	
	public void simulate(SimulationObserver observer, boolean enableMaxFlowCheck) {
		//TODO: to be implemented
		if(!enableMaxFlowCheck) {
			this.simulate(observer);
		}
		else {
			for(Element elem: systemComponents) {
				if(elem instanceof Source) {
					elem.outputFlow[0] = elem.inputFlow;
					observer.notifyFlow("Source", elem.name, SimulationObserver.NO_FLOW, elem.outputFlow);
					computeMaxFlow(observer, elem.connectedElements[0], elem.outputFlow[0]);
				}
			}
		}
	}
}

//==========================================================
//==========================================================
//==========================================================

// package hydraulic;

// /**
//  * Main class that acts as a container of the elements for
//  * the simulation of an hydraulics system 
//  * 
//  */
// public class HSystem {

// 	Element[] elementArray = new Element[100];
// 	Integer i = 0;


// // R1
// 	/**
// 	 * Adds a new element to the system
// 	 * 
// 	 * @param elem the new element to be added to the system
// 	 */
// 	public void addElement(Element elem){
// 		elementArray[i++] = elem;
// 	}
	
// 	/**
// 	 * returns the element added so far to the system
// 	 * 
// 	 * @return an array of elements whose length is equal to 
// 	 * 							the number of added elements
// 	 */
// 	public Element[] getElements(){
// 		Element[] tmp = new Element[i];
		
// 		for(int j=0; j<i; j++)
// 			tmp[j] = elementArray[j];
		
// 		return tmp;
// 	}

// // R4
// 	/**
// 	 * starts the simulation of the system
// 	 * 
// 	 * The notification about the simulations are sent
// 	 * to an observer object
// 	 * 
// 	 * Before starting simulation the parameters of the
// 	 * elements of the system must be defined
// 	 * 
// 	 * @param observer the observer receiving notifications
// 	 */
// 	public void simulate(SimulationObserver observer){
// 		//TODO: to be implemented
// 	}

// // R6
// 	/**
// 	 * Prints the layout of the system starting at each Source
// 	 */
// 	public String layout(){
// 		//TODO: to be implemented
// 		return null;
// 	}

// // R7
// 	/**
// 	 * Deletes a previously added element 
// 	 * with the given name from the system
// 	 */
// 	public boolean deleteElement(String name) {
// 		//TODO: to be implemented
// 		return false;
// 	}

// // R8
// 	/**
// 	 * starts the simulation of the system; if {@code enableMaxFlowCheck} is {@code true},
// 	 * checks also the elements maximum flows against the input flow
// 	 * 
// 	 * If {@code enableMaxFlowCheck} is {@code false}  a normals simulation as
// 	 * the method {@link #simulate(SimulationObserver)} is performed
// 	 * 
// 	 * Before performing a checked simulation the max flows of the elements in thes
// 	 * system must be defined.
// 	 */
// 	public void simulate(SimulationObserver observer, boolean enableMaxFlowCheck) {
// 		//TODO: to be implemented
// 	}

// // R9
// 	/**
// 	 * creates a new builder that can be used to create a 
// 	 * hydraulic system through a fluent API 
// 	 * 
// 	 * @return the builder object
// 	 */
//     public static HBuilder build() {
// 		return new HBuilder();
//     }
// }
