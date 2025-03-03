package diet;

public class RawMaterial implements NutritionalElement {
	
	protected String name;
	protected double calories;
	protected double proteins;
	protected double carbs;
	protected double fat;

	public RawMaterial(String name, double calories, double proteins, double carbs, double fat) {
		this.name = name;
		this.calories = calories;
		this.proteins = proteins;
		this.carbs = carbs;
		this.fat = fat;
	}

	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return this.name;
	}

	@Override
	public double getCalories() {
		// TODO Auto-generated method stub
		return this.calories;
	}

	@Override
	public double getProteins() {
		// TODO Auto-generated method stub
		return this.proteins;
	}

	@Override
	public double getCarbs() {
		// TODO Auto-generated method stub
		return this.carbs;
	}

	@Override
	public double getFat() {
		// TODO Auto-generated method stub
		return this.fat;
	}

	@Override
	public boolean per100g() {
		// TODO Auto-generated method stub
		return true;
	}

}


//=====================================================
//=====================================================
//=====================================================

// package diet;

// public class RawMaterial implements NutritionalElement{
//     private String name;
// 	private double calories;
// 	private double proteins;
// 	private double carbs;
// 	private double fat;
	
//     public RawMaterial(String name, double calories, double proteins, double carbs, double fat) {
// 		this.name = name;
// 		this.calories = calories;
// 		this.proteins = proteins;
// 		this.carbs = carbs;
// 		this.fat = fat;
// 	}

// 	public String getName() {
// 		return name;
// 	}
// 	public void setName(String name) {
// 		this.name = name;
// 	}
// 	public double getCalories() {
// 		return calories;
// 	}
// 	public void setCalories(double calories) {
// 		this.calories = calories;
// 	}
// 	public double getProteins() {
// 		return proteins;
// 	}
// 	public void setProteins(double proteins) {
// 		this.proteins = proteins;
// 	}
// 	public double getCarbs() {
// 		return carbs;
// 	}
// 	public void setCarbs(double carbs) {
// 		this.carbs = carbs;
// 	}
// 	public double getFat() {
// 		return fat;
// 	}
// 	public void setFat(double fat) {
// 		this.fat = fat;
// 	}

// 	@Override
// 	public boolean per100g() {
// 		// TODO Auto-generated method stub
// 		throw new UnsupportedOperationException("Unimplemented method 'per100g'");
// 	}

// }
