package university;

import java.util.Arrays;

public class Course {

	private int code;
	private String title;
	private String teacher;
	private static final int MAXATTENDINGSTUDENTS = 100;
	private int numAttendingStudent;
	private int numExam;
	private int attendingStudents[];
	private int examResult[];
	
	public Course(int code, String title, String teacher) {
		this.code = code;
		this.title = title;
		this.teacher = teacher;
		numAttendingStudent = 0;
		numExam = 0;
		attendingStudents = new int[MAXATTENDINGSTUDENTS];
		examResult = new int[MAXATTENDINGSTUDENTS];
		Arrays.fill(examResult, -1);
	}

	public int getCode() {
		return code;
	}

	public void setCode(int code) {
		this.code = code;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getTeacher() {
		return teacher;
	}

	public void setTeacher(String teacher) {
		this.teacher = teacher;
	}

	public int getNumAttendingStudent() {
		return numAttendingStudent;
	}

	public void setNumAttendingStudent(int numAttendingStudent) {
		this.numAttendingStudent = numAttendingStudent;
	}

	public int[] getAttendingStudents() {
		return attendingStudents;
	}

	public int getNumExam() {
		return numExam;
	}

	public void setNumExam(int numExam) {
		this.numExam = numExam;
	}
	
	public int[] getExamResult() {
		return examResult;
	}
	
	public int getIndexStudent(int idStudent) {
		int i;
		for(i = 0; i < this.numAttendingStudent; i++) {
			if(this.attendingStudents[i] == idStudent) {
				break;
			}
		}
		return i;
	}
	
}


//=====================================================================
//=====================================================================
//=====================================================================

// package university;

// public class Course {
//     private String title;
//     private String teacher;
//     private Integer courseId;
    
//     public Course(String title, String teacher, Integer courseId) {
//         this.title = title;
//         this.teacher = teacher;
//         this.courseId = courseId;
//     }
	
//     public String getTitle() {
// 		return title;
// 	}
// 	public void setTitle(String title) {
// 		this.title = title;
// 	}
// 	public String getTeacher() {
// 		return teacher;
// 	}
// 	public void setTeacher(String teacher) {
// 		this.teacher = teacher;
// 	}
// 	public Integer getCourseId() {
// 		return courseId;
// 	}
// 	public void setCourseId(Integer courseId) {
// 		this.courseId = courseId;
// 	}
// }
