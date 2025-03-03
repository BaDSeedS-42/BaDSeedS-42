package social;

import java.util.ArrayList;
import java.util.List;

public class Person {
	
	protected String code;
	protected String name;
	protected String surname;
	protected List<String> friends;
	
	public Person(String code, String name, String surname) {
		this.code = code;
		this.name = name;
		this.surname = surname;
		this.friends = new ArrayList<>();
	}

	public String getCode() {
		return code;
	}

	public String getName() {
		return name;
	}

	public String getSurname() {
		return surname;
	}
	
	public List<String> getFriends(){
		return this.friends;
	}
}
