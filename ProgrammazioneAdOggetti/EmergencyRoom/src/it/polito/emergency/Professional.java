package it.polito.emergency;

import java.util.ArrayList;

public class Professional {
    private String id;
    private String name;
    private String surname;
    private String specialization;
    private String period;
    private String workingHours;
    
    private String startingDate;
    private String endingDate;
    
    
    
    public Professional(String id, String name, String surname, String specialization, String period) {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.specialization = specialization;
        this.period = period;
    }
    
    
    public void setId(String id) {
        this.id = id;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public void setSurname(String surname) {
        this.surname = surname;
    }
    
    public void setSpecialization(String specialization) {
        this.specialization = specialization;
    }
    
    public void setPeriod(String period) {
        this.period = period;
    }
    
    public void setWorkingHours(String workingHours) {
        this.workingHours = workingHours;
    }
    
    public String getId() {
        return id;
    }
    
    public String getName() {
        return name;
    }
    
    public String getSurname() {
        return surname;
    }
    
    public String getSpecialization() {
        return specialization;
    }
    
    public String getPeriod() {
        return period;
    }
    
    public String getWorkingHours() {
        return workingHours;
    }

    public String getStartingDate() {
        String[] tmp = period.split(" to ");
        startingDate = tmp[0];
        return startingDate;
    }
    
    public String getEndingDate() {
        String[] tmp = period.split(" to ");
        endingDate = tmp[1];
        return endingDate;
    }

    public Boolean isInService(String startingDate, String endingDate){
    if(Integer.parseInt(getStartingDate().split("-")[0]) <= Integer.parseInt(startingDate.split("-")[0]) && Integer.parseInt(getEndingDate().split("-")[0]) >= Integer.parseInt(endingDate.split("-")[0]) && Integer.parseInt(getStartingDate().split("-")[1]) <= Integer.parseInt(startingDate.split("-")[1]) && Integer.parseInt(getEndingDate().split("-")[1]) >= Integer.parseInt(endingDate.split("-")[1]))
        return true;
    return false;}
}
