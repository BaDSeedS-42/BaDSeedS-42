package clinic;

public class Patient {
	
	protected String first;
	protected String last;
	protected String ssn;
	
	public Patient(String first, String last, String SSN) {
		this.first = first;
		this.last = last;
		this.ssn = SSN;
	}

	public String getFirst() {
		return this.first;
	}

	public String getLast() {
		return this.last;
	}

	public String getSSN() {
		return this.ssn;
	}
	
	

}


//=======================================================
//=======================================================
//=======================================================

// package clinic;

// public class Patient {
//     private String name;
//     private String surname;
//     private String ssn;
    
// 	public Patient(String name, String surname, String ssn) {
// 		this.name = name;
// 		this.surname = surname;
// 		this.ssn = ssn;
// 	}
    
// 	public String getName() {
// 		return name;
// 	}
// 	public void setName(String name) {
// 		this.name = name;
// 	}
// 	public String getSurname() {
// 		return surname;
// 	}
// 	public void setSurname(String surname) {
// 		this.surname = surname;
// 	}
// 	public String getSsn() {
// 		return ssn;
// 	}
// 	public void setSsn(String ssn) {
// 		this.ssn = ssn;
// 	}
// }
