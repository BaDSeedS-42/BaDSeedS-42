package social;

import java.util.ArrayList;
import java.util.List;

public class Group {
	
	protected String name;
	protected List<String> people;
	
	public Group(String name) {
		this.name = name;
		this.people = new ArrayList<>();
	}

	public String getName() {
		return name;
	}

	public List<String> getPeople() {
		return people;
	}
	
}


//============================================================
//============================================================
//============================================================

// package social;

// import java.util.*;

// public class Group {
//     private String name;

//     private ArrayList<Subscriber> subscriberList = new ArrayList<>();

// 	public Group(String name) {
// 		this.name = name;
// 	}

// 	public String getName() {
// 		return name;
// 	}
// 	public void setName(String name) {
// 		this.name = name;
// 	}
//     public ArrayList<Subscriber> getSubscriberList() {
// 		return subscriberList;
// 	}
// 	public void setSubscriberList(ArrayList<Subscriber> subscriberList) {
// 		this.subscriberList = subscriberList;
//     }
// }
