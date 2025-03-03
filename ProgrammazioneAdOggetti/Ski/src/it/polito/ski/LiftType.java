package it.polito.ski;

import java.util.*;

public class LiftType {
	private String code;
	private String category;
	private Integer seats;
	
	private HashSet<Lift> liftSet = new HashSet<>();
	
	public LiftType(String code, String category, Integer seats) {
		this.code = code;
		this.category = category;
		this.seats = seats;
	}
	
	public String getCode() {
		return code;
	}
	
	public void setCode(String code) {
		this.code = code;
	}
	
	public String getCategory() {
		return category;
	}
	
	public void setCategory(String category) {
		this.category = category;
	}
	
	public Integer getSeats() {
		return seats;
	}
	
	public void setSeats(Integer seats) {
		this.seats = seats;
	}
	public Set<Lift> getLiftSet() {
		return liftSet;
	}
	
	public void setLiftSet(String name) {
		Lift l = new Lift(name);
		liftSet.add(l);
	}
}
