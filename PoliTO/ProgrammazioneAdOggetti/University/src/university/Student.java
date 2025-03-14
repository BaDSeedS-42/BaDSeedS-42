package university;

import java.util.Arrays;

public class Student {
	private int id;
	private String firstName;
	private String lastName;
	private final static int MAXATTENDEDCOURSES = 25;
	private int numAttendedCourses;
	private int numExam;
	private int attendedCourses[];
	private int examTaken[];
	
	public Student(int id, String firstName, String lastName) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.id = id;
		this.numAttendedCourses = 0;
		numExam = 0;
		attendedCourses = new int[MAXATTENDEDCOURSES];
		examTaken = new int[MAXATTENDEDCOURSES];
		Arrays.fill(examTaken, -1);
	}

	public void setId(int id) {
		this.id = id;
	}
	
	public int getId() {
		return this.id;
	}
	
	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public int getNumAttendedCourses() {
		return numAttendedCourses;
	}

	public void setNumAttendedCourses(int numAttendedCourses) {
		this.numAttendedCourses = numAttendedCourses;
	}

	public int[] getAttendedCourses() {
		return attendedCourses;
	}
	
	public void setAttendedCourses(int[] attendedCourses) {
		this.attendedCourses = attendedCourses;
	}

	public int getNumExam() {
		return numExam;
	}

	public void setNumExam(int numExam) {
		this.numExam = numExam;
	}
	
	public int[] getExamTaken(){
		return examTaken;
	}
	
	public int getIndexCourse(int codeCourse) {
		int i;
		for(i = 0; i < this.numAttendedCourses; i++) {
			if(this.attendedCourses[i] == codeCourse) {
				break;
			}
		}
		return i;
	}
	
	public double computeAvgStudent() {
		int i, sum = 0;
		double avg;
		if(this.numExam > 0) {
			for(i = 0; i < this.numAttendedCourses; i++) {
				if(this.examTaken[i] != -1) {
					sum += this.examTaken[i];
				}
			}
			avg = sum / this.numExam;
		}
		else {
			avg = -1.0;
		}
		return avg;
	}
	
	public double computeScore() {
		double score, bonus, avgStudent;
		
		
		avgStudent = this.computeAvgStudent();
		bonus = (this.numExam / this.numAttendedCourses) * 10;
		score = avgStudent + bonus;
		
		return score;
	}
}

//=====================================================================
//=====================================================================
//=====================================================================

    // private String name;
    // private String surname;
    // private Integer id;

    // public Student(String name, String surname, Integer id) {
	// 	this.name = name;
	// 	this.surname = surname;
	// 	this.id = id;
	// }

	// public String getName() {
	// 	return name;
	// }
	// public void setName(String name) {
	// 	this.name = name;
	// }
	// public String getSurname() {
	// 	return surname;
	// }
	// public void setSurname(String surname) {
	// 	this.surname = surname;
	// }
	// public Integer getId() {
	// 	return id;
	// }
	// public void setId(Integer id) {
	// 	this.id = id;
	// }
