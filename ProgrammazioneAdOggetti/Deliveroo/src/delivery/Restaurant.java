package delivery;

import java.util.*;

public class Restaurant {

	private String category;
	private String name;
	private List<Dish> dishList = new ArrayList<>();
	

	public Restaurant(String category, String name) {
		this.category = category;
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}
	
	public void addDish(String name, Float price) {
		Dish d = new Dish(name, price);
		dishList.add(d);
	}

	public boolean isDishPresent(String name) {
		for(Dish d : dishList) {
			if(d.getName().equals(name))
					return true;
		}
		return false;
	}
	
	public List<Dish> getDishList() {
		return dishList;
	}
	
}