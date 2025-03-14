package it.polito.emergency;

import java.util.ArrayList;

public class Department {
    private String name;
    private Integer maxPatients;
    private ArrayList<String> patientDepartmentList = new ArrayList<>(); 
    
    
    public Department(String name, Integer maxPatients) {
		this.name = name;
		this.maxPatients = maxPatients;
	}
    
    
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public Integer getMaxPatients() {
        return maxPatients;
    }
    public void setMaxPatients(Integer maxPatients) {
        this.maxPatients = maxPatients;
    }
    public ArrayList<String> getPatientDepartmentList() {
        return patientDepartmentList;
    }
    public void setPatientDepartmentList(ArrayList<String> patientDepartmentList) {
        this.patientDepartmentList = patientDepartmentList;
    }
    public boolean hasAvailableBeds() {
        return patientDepartmentList.size() < maxPatients;}
}
