package it.polito.emergency;

import it.polito.emergency.EmergencyApp.*;

public class Patient {
    private String fiscalCode;
    private String name;
    private String surname;
    private String dateOfBirth;
    private String reason;
    private String dateTimeAccepted;
    private PatientStatus status;


	public Patient(String fiscalCode, String name, String surname, String dateOfBirth, String reason,
			String dateTimeAccepted) {
		this.fiscalCode = fiscalCode;
		this.name = name;
		this.surname = surname;
		this.dateOfBirth = dateOfBirth;
		this.reason = reason;
		this.dateTimeAccepted = dateTimeAccepted;
	}


	public void setFiscalCode(String fiscalCode) {
        this.fiscalCode = fiscalCode;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setDateOfBirth(String dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public void setReason(String reason) {
        this.reason = reason;
    }

    public void setDateTimeAccepted(String dateTimeAccepted) {
        this.dateTimeAccepted = dateTimeAccepted;
    }

    public String getFiscalCode() {
        return fiscalCode;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public String getReason() {
        return reason;
    }

    public String getDateTimeAccepted() {
        return dateTimeAccepted;
    }

    public PatientStatus getStatus() {
        return status;
    }
    
    public void setStatus(PatientStatus status) {
		this.status = status;
	}
}
