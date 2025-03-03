package clinic;

public class Doctor {
	
	protected String first;
	protected String last;
	protected String ssn;
	protected int id;
	protected String specialization;
	
	public Doctor(String first, String last, String ssn, int id, String specialization) {
		this.first = first;
		this.last = last;
		this.ssn = ssn;
		this.id = id;
		this.specialization = specialization;
	}

	public String getFirst() {
		return this.first;
	}

	public String getLast() {
		return this.last;
	}

	public String getSsn() {
		return this.ssn;
	}

	public int getId() {
		return this.id;
	}

	public String getSpecialization() {
		return this.specialization;
	}
	
	

}


//=======================================================
//=======================================================
//=======================================================

// package clinic;

// public class Doctor {
//     private String name;
//     private String surname;
//     private String ssn;
//     private Integer badgeId;
//     private String specialization;
    
// 	public Doctor(String name, String surname, String ssn, Integer badgeId, String specialization) {
// 		this.name = name;
// 		this.surname = surname;
// 		this.ssn = ssn;
// 		this.badgeId = badgeId;
// 		this.specialization = specialization;
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
// 	public Integer getBadgeId() {
// 		return badgeId;
// 	}
// 	public void setBadgeId(Integer badgeId) {
// 		this.badgeId = badgeId;
// 	}
// 	public String getSpecialization() {
// 		return specialization;
// 	}
// 	public void setSpecialization(String specialization) {
// 		this.specialization = specialization;
// 	}


    
// }
