package delivery;

public class Order {

	int[] quantities;
	String[] dishNames;
	String customerName;
	String restaurantName;
	int deliveryTime;
	int deliveryDistance;
	
	Restaurant restaurant;
	Integer id=0;
	
	Boolean delivered = false;
	
	public Order(String[] dishNames, int[] quantities, String customerName, String restaurantName,
			int deliveryTime, int deliveryDistance, Integer id, Restaurant restaurant) {
		this.dishNames = dishNames;
		this.quantities = quantities;
		this.customerName = customerName;
		this.restaurantName = restaurantName;
		this.deliveryTime = deliveryTime;
		this.deliveryDistance = deliveryDistance;
		this.id=id;
		this.restaurant = restaurant;
	}

	public String[] getdishNames() {
		return dishNames;
	}
	public void setdishNames(String[] dishNames) {
		this.dishNames = dishNames;
	}
	
	public int[] getQuantities() {
		return quantities;
	}
	public void setQuantity(int[] quantities) {
		this.quantities = quantities;
	}
	
	public String getCustomerName() {
		return customerName;
	}
	public void setCustomerName(String customerName) {
		this.customerName = customerName;
	}
	
	public String getRestaurantName() {
		return restaurantName;
	}
	public void setRestaurantName(String restaurantName) {
		this.restaurantName = restaurantName;
	}
	
	public Integer getDeliveryTime() {
		return deliveryTime;
	}
	public void setDeliveryTime(int deliveryTime) {
		this.deliveryTime = deliveryTime;
	}
	
	public Integer getDeliveryDistance() {
		return deliveryDistance;
	}
	public void setDeliveryDistance(int deliveryDistance) {
		this.deliveryDistance = deliveryDistance;
	}
	
	public Boolean getDelivered() {
		return delivered;
	}
	public void setDelivered(boolean delivered) {
		this.delivered = delivered;
	}
	
	public Integer getId() {
		return id;
	}
}
