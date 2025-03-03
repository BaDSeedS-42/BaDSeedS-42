package it.polito.ski;

public class Slope {
	private String name;
	private String difficulty;
	private String liftName;

	public Slope(String name, String difficulty, String liftName) {
		this.name = name;
		this.difficulty = difficulty;
		this.liftName = liftName;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getDifficulty() {
		return difficulty;
	}
	public void setDifficulty(String difficulty) {
		this.difficulty = difficulty;
	}
	public String getLiftName() {
		return liftName;
	}
	public void setLiftName(String liftName) {
		this.liftName = liftName;
	}
}
