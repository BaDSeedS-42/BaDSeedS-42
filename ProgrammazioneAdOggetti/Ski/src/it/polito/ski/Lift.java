package it.polito.ski;

import java.util.*;

public class Lift {
	private String name;
	private String code;
	
	private List<Slope> slopeList = new ArrayList<>();

	public Lift(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public List<Slope> getSlopeList() {
		return slopeList;
	}

	public void setSlopeList(List<Slope> slopeList) {
		this.slopeList = slopeList;
	}
}
