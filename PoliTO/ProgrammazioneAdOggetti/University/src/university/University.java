package university;

import java.util.logging.Logger;

/**
 * This class represents a university education system.
 * 
 * It manages students and courses.
 *
 */
public class University {

	// private String universityName;
	// private String rectorName;
	// private String rectorSurname;

	// private Integer studentIndex = 0;
	// //private TreeMap<Integer, Student> studentMap = new TreeMap<>();
	// Student[] studentArray = new Student[100];
	// private static final int MIN_ID_STUDENTI = 10_000;
	
	// private static final int MIN_ID_CORSO = 10;
	// private Integer courseIndex = 0;
	// Course[] courseArray = new Course[50];

	private String name;
	private String rectorFirstName;
	private String rectorLastName;
	private int IDSTUD;
	private int CODECOURSE;
	private static final int MAXSTUD = 1000;
	private static final int SHIFTIDSTUD = 10000;
	private static final int MAXCOURSE = 50;
	private static final int SHIFTCODECOURSE = 10;
	private Student students[];
	private Course courses[];

	// R1
	/**
	 * Constructor
	 * 
	 * @param name name of the university
	 */
	public University(String name) {
		// // Example of logging
		// // logger.info("Creating extended university object");
		// logger.info("Creating extended university object");
		// this.universityName = name;
		this.name = name;
		this.IDSTUD = 0;
		this.CODECOURSE = 0;
		this.students = new Student[MAXSTUD];
		this.courses = new Course[MAXCOURSE];
	}

	/**
	 * Getter for the name of the university
	 * 
	 * @return name of university
	 */
	public String getName() {
		// return universityName;
		return this.name;
	}

	/**
	 * Defines the rector for the university
	 * 
	 * @param first first name of the rector
	 * @param last  last name of the rector
	 */
	public void setRector(String first, String last) {
		// this.rectorName = first;
		// this.rectorSurname = last;
		this.rectorFirstName = first;
		this.rectorLastName = last;
	}

	/**
	 * Retrieves the rector of the university with the format "First Last"
	 * 
	 * @return name of the rector
	 */
	public String getRector() {
		// return rectorName + " " + rectorSurname;
		return this.rectorFirstName + " " + this.rectorLastName;
	}

	// R2
	/**
	 * Enrol a student in the university
	 * The university assigns ID numbers
	 * progressively from number 10000.
	 * 
	 * @param first first name of the student
	 * @param last  last name of the student
	 * 
	 * @return unique ID of the newly enrolled student
	 */
	public int enroll(String first, String last) {
		// Student s = new Student(first, last, MIN_ID_STUDENTI + studentIndex);
		// this.studentArray[studentIndex] = s;
		
		// return studentIndex++ + MIN_ID_STUDENTI;
		this.students[this.IDSTUD] = new Student(IDSTUD + SHIFTIDSTUD, first, last);
		IDSTUD++;
		logger.info("New student enrolled: " + String.valueOf(IDSTUD + SHIFTIDSTUD - 1) + ", " + first + " " + last);
		return IDSTUD + SHIFTIDSTUD - 1;
	}

	/**
	 * Retrieves the information for a given student.
	 * The university assigns IDs progressively starting from 10000
	 * 
	 * @param id the ID of the student
	 * 
	 * @return information about the student
	 */
	public String student(int id) {		
		// return  studentArray[id - MIN_ID_STUDENTI].getId() + " " +  studentArray[id - MIN_ID_STUDENTI].getName() + " " + studentArray[id - MIN_ID_STUDENTI].getSurname();
		String first, last;
		first = this.students[id - SHIFTIDSTUD].getFirstName();
		last = this.students[id - SHIFTIDSTUD].getLastName();
		return String.valueOf(id) + " " + first + " " + last;
	}

	// R3
	/**
	 * Activates a new course with the given teacher
	 * Course codes are assigned progressively starting from 10.
	 * 
	 * @param title   title of the course
	 * @param teacher name of the teacher
	 * 
	 * @return the unique code assigned to the course
	 */
	public int activate(String title, String teacher) {
		// Course c = new Course(title, teacher, courseIndex + MIN_ID_CORSO);
		// this.courseArray[courseIndex] = c;

		// return courseIndex++ + MIN_ID_CORSO;
		this.courses[this.CODECOURSE] = new Course(CODECOURSE + SHIFTCODECOURSE, title, teacher);
		CODECOURSE++;
		logger.info("New course activated: " + String.valueOf(CODECOURSE + SHIFTCODECOURSE - 1) + ", " + title + " " + teacher);
		return CODECOURSE + SHIFTCODECOURSE - 1;
	}

	/**
	 * Retrieve the information for a given course.
	 * 
	 * The course information is formatted as a string containing
	 * code, title, and teacher separated by commas,
	 * e.g., {@code "10,Object Oriented Programming,James Gosling"}.
	 * 
	 * @param code unique code of the course
	 * 
	 * @return information about the course
	 */
	public String course(int code) {
		// return  courseArray[code - MIN_ID_CORSO].getCourseId() + " " +  courseArray[code - MIN_ID_CORSO].getTitle() + " " + courseArray[code - MIN_ID_CORSO].getTeacher();
		String title, teacher;
		title = this.courses[code - SHIFTCODECOURSE].getTitle();
		teacher = this.courses[code - SHIFTCODECOURSE].getTeacher();
		return String.valueOf(code) + "," + title + "," + teacher;
	}

	// R4
	/**
	 * Register a student to attend a course
	 * 
	 * @param studentID  id of the student
	 * @param courseCode id of the course
	 */
	public void register(int studentID, int courseCode) {
		this.students[studentID - SHIFTIDSTUD].getAttendedCourses()[this.students[studentID - SHIFTIDSTUD].getNumAttendedCourses()] = courseCode;
		this.courses[courseCode - SHIFTCODECOURSE].getAttendingStudents()[this.courses[courseCode - SHIFTCODECOURSE].getNumAttendingStudent()] = studentID;
		this.students[studentID - SHIFTIDSTUD].setNumAttendedCourses(this.students[studentID - SHIFTIDSTUD].getNumAttendedCourses() + 1);
		this.courses[courseCode - SHIFTCODECOURSE].setNumAttendingStudent(this.courses[courseCode - SHIFTCODECOURSE].getNumAttendingStudent() + 1);
		logger.info("Student " + String.valueOf(studentID) + " signed up for course " + String.valueOf(courseCode));
	}

	/**
	 * Retrieve a list of attendees.
	 * 
	 * The students appear one per row (rows end with `'\n'`)
	 * and each row is formatted as describe in in method {@link #student}
	 * 
	 * @param courseCode unique id of the course
	 * @return list of attendees separated by "\n"
	 */
	public String listAttendees(int courseCode) {
		String result = "";
		int i;
		for(i = 0; i < this.courses[courseCode - SHIFTCODECOURSE].getNumAttendingStudent(); i++) {
			result += student(this.courses[courseCode - SHIFTCODECOURSE].getAttendingStudents()[i]) + "\n";
		}
		return result;
	}

	/**
	 * Retrieves the study plan for a student.
	 * 
	 * The study plan is reported as a string having
	 * one course per line (i.e. separated by '\n').
	 * The courses are formatted as describe in method {@link #course}
	 * 
	 * @param studentID id of the student
	 * 
	 * @return the list of courses the student is registered for
	 */
	public String studyPlan(int studentID) {
		String result = "";
		int i;
		for(i = 0; i < this.students[studentID - SHIFTIDSTUD].getNumAttendedCourses(); i++) {
			result += course(this.students[studentID - SHIFTIDSTUD].getAttendedCourses()[i]) + "\n";
		}
		return result;
	}

	// R5
	/**
	 * records the grade (integer 0-30) for an exam can
	 * 
	 * @param studentId the ID of the student
	 * @param courseID  course code
	 * @param grade     grade ( 0-30)
	 */
	public void exam(int studentId, int courseID, int grade) {
		if(grade >= 0 && grade <= 30) {
			this.students[studentId - SHIFTIDSTUD].getExamTaken()[this.students[studentId - SHIFTIDSTUD].getIndexCourse(courseID)] = grade;
			this.courses[courseID - SHIFTCODECOURSE].getExamResult()[this.courses[courseID - SHIFTCODECOURSE].getIndexStudent(studentId)] = grade;
			this.students[studentId - SHIFTIDSTUD].setNumExam(this.students[studentId - SHIFTIDSTUD].getNumExam() + 1);
			this.courses[courseID - SHIFTCODECOURSE].setNumExam(this.courses[courseID - SHIFTCODECOURSE].getNumExam() + 1);
			logger.info("Student " + String.valueOf(studentId) + " took an exam in course " + String.valueOf(courseID) + " with grade " + String.valueOf(grade));
		}
		else {
			System.out.println("Grade not valid!");
		}
	}

	/**
	 * Computes the average grade for a student and formats it as a string
	 * using the following format
	 * 
	 * {@code "Student STUDENT_ID : AVG_GRADE"}.
	 * 
	 * If the student has no exam recorded the method
	 * returns {@code "Student STUDENT_ID hasn't taken any exams"}.
	 * 
	 * @param studentId the ID of the student
	 * @return the average grade formatted as a string.
	 */
	public String studentAvg(int studentId) {
		double avgGrade;
		if(this.students[studentId - SHIFTIDSTUD].getNumExam() == 0) {
			return "Student " + String.valueOf(studentId) + " hasn't taken any exams";
		}
		else {
			avgGrade = this.students[studentId - SHIFTIDSTUD].computeAvgStudent();
			return "Student " + String.valueOf(studentId) + ": " + String.valueOf(avgGrade);
		}
	}

	/**
	 * Computes the average grades of all students that took the exam for a given
	 * course.
	 * 
	 * The format is the following:
	 * {@code "The average for the course COURSE_TITLE is: COURSE_AVG"}.
	 * 
	 * If no student took the exam for that course it returns
	 * {@code "No student has taken the exam in COURSE_TITLE"}.
	 * 
	 * @param courseId course code
	 * @return the course average formatted as a string
	 */
	public String courseAvg(int courseId) {
		int i, sum = 0;
		double avgGrade;
		if(this.courses[courseId - SHIFTCODECOURSE].getNumExam() == 0) {
			return "No student has taken the exam in " + this.courses[courseId - SHIFTCODECOURSE].getTitle();
		}
		else {
			for(i = 0; i < this.courses[courseId - SHIFTCODECOURSE].getNumAttendingStudent(); i++) {
				if(this.courses[courseId - SHIFTCODECOURSE].getExamResult()[i] != -1) {
					sum += this.courses[courseId - SHIFTCODECOURSE].getExamResult()[i];
				}
			}
			avgGrade = sum / this.courses[courseId - SHIFTCODECOURSE].getNumExam();
			return "The average for the course " + this.courses[courseId - SHIFTCODECOURSE].getTitle() + " is: " + String.valueOf(avgGrade);
		}
	}

	// R6
	/**
	 * Retrieve information for the best students to award a price.
	 * 
	 * The students' score is evaluated as the average grade of the exams they've
	 * taken.
	 * To take into account the number of exams taken and not only the grades,
	 * a special bonus is assigned on top of the average grade:
	 * the number of taken exams divided by the number of courses the student is
	 * enrolled to, multiplied by 10.
	 * The bonus is added to the exam average to compute the student score.
	 * 
	 * The method returns a string with the information about the three students
	 * with the highest score.
	 * The students appear one per row (rows are terminated by a new-line character
	 * {@code '\n'})
	 * and each one of them is formatted as:
	 * {@code "STUDENT_FIRSTNAME STUDENT_LASTNAME : SCORE"}.
	 * 
	 * @return info on the best three students.
	 */
	private static int computeIMin(int bestStudents[], double bestScores[]) {
		int i;
		if(bestScores[0] <= bestScores[1] && bestScores[0] <= bestScores[2]) {
			i = 0;
		}
		else if(bestScores[1] <= bestScores[0] && bestScores[1] <= bestScores[2]) {
			i = 1;
		}
		else {
			i = 2;
		}
		return i;
	}
	
	private static void swap(int idStud, double score, int iMin, int bestStudents[], double bestScores[]) {
		
		bestStudents[iMin] = idStud;
		bestScores[iMin] = score;
	}
	
	private static void arraySort(int bestStudents[], double bestScores[]) {
		int i, j, tempId;
		double tempScore;
		for(i = 1; i < 3; i++) {
			tempId = bestStudents[i];
			tempScore = bestScores[i];
			j = i - 1;
			while(j >= 0 && bestScores[j] > tempScore) {
				University.swap(bestStudents[j], bestScores[j], j + 1, bestStudents, bestScores);
				j--;
			}
			bestStudents[j + 1] = tempId;
			bestScores[j + 1] = tempScore;
		}
	}
	
	public String topThreeStudents() {
		int bestStudents[] = {-1, -1, -1};
		double bestScores[] = {-1.0, -1.0, -1.0};
		int iMin, i;
		double minScore, score;
		String result = "";
		
		
		for(i = 0; i < IDSTUD; i++) {
			iMin = University.computeIMin(bestStudents, bestScores);
			minScore = bestScores[iMin];
			score = this.students[i].computeScore();
			if(score > minScore) {
				University.swap(i + SHIFTIDSTUD, score, iMin, bestStudents, bestScores);
			}
		}
		University.arraySort(bestStudents, bestScores);
		for(i = 2; i >= 0; i--) {
			if(bestStudents[i] != -1) {
				result += this.students[bestStudents[i] - SHIFTIDSTUD].getFirstName() + " " + this.students[bestStudents[i] - SHIFTIDSTUD].getLastName() + " : " + String.valueOf(bestScores[i]) + "\n";
			}
		}
		return result;
	}

	// R7
	/**
	 * This field points to the logger for the class that can be used
	 * throughout the methods to log the activities.
	 */
	public static final Logger logger = Logger.getLogger("University");

}
