package it.polito.emergency;

public class Report {
    private String id;
    private String professionalId;
    private String fiscalCode;
    private String date;
    private String description;


    public Report(Integer id, String professionalId, String fiscalCode, String date, String description) {
		this.id = Integer.toString(id);
		this.professionalId = professionalId;
		this.fiscalCode = fiscalCode;
		this.date = date;
		this.description = description;
	}


	public void setId(String id) {
		this.id = id;
	}

	public void setProfessionalId(String professionalId) {
		this.professionalId = professionalId;
	}

	public void setFiscalCode(String fiscalCode) {
		this.fiscalCode = fiscalCode;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getId() {
        return id;
    }

    public String getProfessionalId() {
        return professionalId;
    }

    public String getFiscalCode() {
        return fiscalCode;
    }

    public String getDate() {
        return date;
    }


    public String getDescription() {
        return description;
    }
}
