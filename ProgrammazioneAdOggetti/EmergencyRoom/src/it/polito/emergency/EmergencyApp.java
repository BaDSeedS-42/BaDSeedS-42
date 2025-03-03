package it.polito.emergency;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.TreeMap;

public class EmergencyApp {

    TreeMap<String, Professional> professionalMap = new TreeMap<>();
    TreeMap<String, Department> departmentsMap = new TreeMap<>();
    TreeMap<String, Patient> patientsMap = new TreeMap<>();
    TreeMap<String, Report> reportMap = new TreeMap<>();
    TreeMap<String, Patient> patientProfessionalMap = new TreeMap<>();
    
    private Integer id = 0;



    public enum PatientStatus {
        ADMITTED,
        DISCHARGED,
        HOSPITALIZED
    }
    
    /**
     * Add a professional working in the emergency room
     * 
     * @param id
     * @param name
     * @param surname
     * @param specialization
     * @param period
     * @param workingHours
     */
    public void addProfessional(String id, String name, String surname, String specialization, String period) {
        professionalMap.put(id, new Professional(id,name,surname,specialization,period));
    }

    /**
     * Retrieves a professional utilizing the ID.
     *
     * @param id The id of the professional.
     * @return A Professional.
     * @throws EmergencyException If no professional is found.
     */    
    public Professional getProfessionalById(String id) throws EmergencyException {
        if(!professionalMap.containsKey(id))
            throw new EmergencyException();
        return professionalMap.get(id);
    }

    /**
     * Retrieves the list of professional IDs by their specialization.
     *
     * @param specialization The specialization to search for among the professionals.
     * @return A list of professional IDs who match the given specialization.
     * @throws EmergencyException If no professionals are found with the specified specialization.
     */    
    public List<String> getProfessionals(String specialization) throws EmergencyException {
        List<String> tmp = new ArrayList<>();

        tmp = professionalMap.values().stream()
                                      .filter(professionals->professionals.getSpecialization().equals(specialization))
                                      .map(Professional::getId)
                                      .toList();

        if(tmp.isEmpty())
            throw new EmergencyException();        
        return tmp;
    }

    /**
     * Retrieves the list of professional IDs who are specialized and available during a given period.
     *
     * @param specialization The specialization to search for among the professionals.
     * @param period The period during which the professional should be available, formatted as "YYYY-MM-DD to YYYY-MM-DD".
     * @return A list of professional IDs who match the given specialization and are available during the period.
     * @throws EmergencyException If no professionals are found with the specified specialization and period.
     */    
    public List<String> getProfessionalsInService(String specialization, String period) throws EmergencyException {
        List<String> tmp = new ArrayList<>();
        String[] dates = period.split(" to ");

        String startingDate =  dates[0];
        String endingDate = dates[1];

        tmp = professionalMap.values().stream()
                                    .filter(professionals->professionals.getSpecialization().equals(specialization))
                                    .filter(x->x.isInService(startingDate,endingDate).equals(true))
                                    .map(Professional::getId)
                                    .toList();
        if(tmp.isEmpty())
            throw new EmergencyException();        
        return tmp;
    }

    /**
     * Adds a new department to the emergency system if it does not already exist.
     *
     * @param name The name of the department.
     * @param maxPatients The maximum number of patients that the department can handle.
     * @throws EmergencyException If the department already exists.
     */
    public void addDepartment(String name, int maxPatients) {
		departmentsMap.put(name, new Department(name,maxPatients));
    }

    /**
     * Retrieves a list of all department names in the emergency system.
     *
     * @return A list containing the names of all registered departments.
     * @throws EmergencyException If no departments are found.
     */
    public List<String> getDepartments() throws EmergencyException {
        List<String> tmp = new ArrayList<>();

        tmp = departmentsMap.keySet().stream().toList();

        if(tmp.isEmpty())
            throw new EmergencyException();        
        return tmp;
    }

    /**
     * Reads professional data from a CSV file and stores it in the application.
     * Each line of the CSV should contain a professional's ID, name, surname, specialization, period of availability, and working hours.
     * The expected format of each line is: matricola, nome, cognome, specializzazione, period, orari_lavoro
     * 
     * @param reader The reader used to read the CSV file. Must not be null.
     * @return The number of professionals successfully read and stored from the file.
     * @throws IOException If there is an error reading from the file or if the reader is null.
     */
    public int readFromFileProfessionals(Reader reader) throws IOException {
        int n = 0; //numero di professionisti letti
		String line;
		List<String> values = new ArrayList<>();
        if(reader==null) throw new IOException();
        BufferedReader bufferedReader = new BufferedReader(reader);

		try {
			
            while((line = bufferedReader.readLine()) != null) {
				values = Arrays.asList(line.split(","));
				professionalMap.put(values.get(0), new Professional(values.get(0),values.get(1),values.get(2),values.get(3),values.get(4)));
                n++;
			}
		}
		catch(IOException e) {
			throw new IOException();
		}
		return n-1;
    }

    /**
     * Reads department data from a CSV file and stores it in the application.
     * Each line of the CSV should contain a department's name and the maximum number of patients it can accommodate.
     * The expected format of each line is: nome_reparto, num_max
     * 
     * @param reader The reader used to read the CSV file. Must not be null.
     * @return The number of departments successfully read and stored from the file.
     * @throws IOException If there is an error reading from the file or if the reader is null.
     */    
    public int readFromFileDepartments(Reader reader) throws IOException {
        int n = 0; //numero di dipartimenti letti
		String line;
		List<String> values = new ArrayList<>();
        if(reader==null) throw new IOException();
        BufferedReader bufferedReader = new BufferedReader(reader);

		try {
						
            while((line = bufferedReader.readLine()) != null) {
                if(n>0){
				values = Arrays.asList(line.split(","));
				departmentsMap.put(values.get(0), new Department(values.get(0),Integer.parseInt(values.get(1))));
                }
                n++;
			}
		}
		catch(IOException e) {
			throw new IOException();
		}
		return n-1;
    }

    /**
     * Registers a new patient in the emergency system if they do not exist.
     * 
     * @param fiscalCode The fiscal code of the patient, used as a unique identifier.
     * @param name The first name of the patient.
     * @param surname The surname of the patient.
     * @param dateOfBirth The birth date of the patient.
     * @param reason The reason for the patient's visit.
     * @param dateTimeAccepted The date and time the patient was accepted into the emergency system.
     */
    public Patient addPatient(String fiscalCode, String name, String surname, String dateOfBirth, String reason, String dateTimeAccepted) {
        if(patientsMap.keySet().contains(fiscalCode)){
            patientsMap.get(fiscalCode).setStatus(PatientStatus.ADMITTED);
            return patientsMap.get(fiscalCode);
        }
        patientsMap.put(fiscalCode, new Patient(fiscalCode,name,surname,dateOfBirth,reason,dateTimeAccepted));
        patientsMap.get(fiscalCode).setStatus(PatientStatus.ADMITTED);
        return patientsMap.get(fiscalCode);
    }

    /**
     * Retrieves a patient or patients based on a fiscal code or surname.
     *
     * @param identifier Either the fiscal code or the surname of the patient(s).
     * @return A single patient if a fiscal code is provided, or a list of patients if a surname is provided.
     *         Returns an empty collection if no match is found.
     */    
    public List<Patient> getPatient(String identifier) throws EmergencyException {
        List<Patient> tmp = new ArrayList<>();
        String[] fcOrSurname = identifier.split("[0123456789]");

        if(fcOrSurname.length < 1) //è cf
            tmp.add(patientsMap.get(identifier));

        else //è surname
        tmp = patientsMap.values().stream()
                                  .filter(x->x.getSurname().equals(identifier))
                                  .toList();

        if(tmp.isEmpty())
            List.of();
        return tmp;
    }

    /**
     * Retrieves the fiscal codes of patients accepted on a specific date, 
     * sorted by acceptance time in descending order.
     *
     * @param date The date of acceptance to filter the patients by, expected in the format "yyyy-MM-dd".
     * @return A list of patient fiscal codes who were accepted on the given date, sorted from the most recent.
     *         Returns an empty list if no patients were accepted on that date.
     */
    public List<String> getPatientsByDate(String date) {
        List<String> tmp = new ArrayList<>();

        tmp = patientsMap.values().stream()
                                  .filter(x->x.getDateTimeAccepted().equals(date))
                                  .sorted(Comparator.comparing(x -> x.getSurname() + " " + x.getName()))
                                  .map(Patient::getFiscalCode)
                                  .toList();

        if(tmp.isEmpty())
            new ArrayList<String>();        
        return tmp;
    }

    /**
     * Assigns a patient to a professional based on the required specialization and checks availability during the request period.
     *
     * @param fiscalCode The fiscal code of the patient.
     * @param specialization The required specialization of the professional.
     * @return The ID of the assigned professional.
     * @throws EmergencyException If the patient does not exist, if no professionals with the required specialization are found, or if none are available during the period of the request.
     */
    public String assignPatientToProfessional(String fiscalCode, String specialization) throws EmergencyException {
        if (!patientsMap.containsKey(fiscalCode)) throw new EmergencyException();
        String professionalId =  professionalMap.values().stream()
            .filter(p -> p.getSpecialization().equals(specialization))
            .findFirst().orElseThrow(EmergencyException::new)
            .getId();
        patientProfessionalMap.put(professionalId, patientsMap.get(fiscalCode));
        return professionalId;

    }

    public Report saveReport(String professionalId, String fiscalCode, String date, String description) throws EmergencyException {
        Report r = new Report(++id,professionalId, fiscalCode, date, description);
        if(!professionalMap.keySet().contains(professionalId))
        throw new EmergencyException();
       //reportMap.put(id++, r);
        return r;
    }

    /**
     * Either discharges a patient or hospitalizes them depending on the availability of space in the requested department.
     * 
     * @param fiscalCode The fiscal code of the patient to be discharged or hospitalized.
     * @param departmentName The name of the department to which the patient might be admitted.
     * @throws EmergencyException If the patient does not exist or if the department does not exist.
     */
    public void dischargeOrHospitalize(String fiscalCode, String departmentName) throws EmergencyException {
        if (!patientsMap.containsKey(fiscalCode) || !departmentsMap.containsKey(departmentName)) throw new EmergencyException();
        patientsMap.get(fiscalCode).setStatus(departmentsMap.get(departmentName).hasAvailableBeds() ? PatientStatus.HOSPITALIZED : PatientStatus.DISCHARGED);
        if(departmentsMap.get(departmentName).hasAvailableBeds()) departmentsMap.get(departmentName).getPatientDepartmentList().add(fiscalCode);
    }

    /**
     * Checks if a patient is currently hospitalized in any department.
     *
     * @param fiscalCode The fiscal code of the patient to verify.
     * @return 0 if the patient is currently hospitalized, -1 if not hospitalized or discharged.
     * @throws EmergencyException If no patient is found with the given fiscal code.
     */
    public int verifyPatient(String fiscalCode) throws EmergencyException{
    if (patientsMap.getOrDefault(fiscalCode, null) == null) throw new EmergencyException();
    return patientsMap.getOrDefault(fiscalCode, null).getStatus() == PatientStatus.DISCHARGED ? 0 : 1;
    }

    /**
     * Returns the number of patients currently being managed in the emergency room.
     *
     * @return The total number of patients in the system.
     */    
    public int getNumberOfPatients() {
        return (int) patientsMap.values().stream().filter(p -> p.getStatus() == PatientStatus.ADMITTED).count();
    }

    /**
     * Returns the number of patients admitted on a specified date.
     *
     * @param dateString The date of interest provided as a String (format "yyyy-MM-dd").
     * @return The count of patients admitted on that date.
     */
    public int getNumberOfPatientsByDate(String date) {
        return (int) patientsMap.values().stream().filter(x->x.getDateTimeAccepted().equals(date)).count();
    }

    public int getNumberOfPatientsHospitalizedByDepartment(String departmentName) throws EmergencyException {
        if (!departmentsMap.containsKey(departmentName)) throw new EmergencyException();
        return (int) departmentsMap.get(departmentName).getPatientDepartmentList().stream().map(patientsMap::get).filter(patient -> patient.getStatus() == PatientStatus.HOSPITALIZED).count();}

    /**
     * Returns the number of patients who have been discharged from the emergency system.
     *
     * @return The count of discharged patients.
     */
    public int getNumberOfPatientsDischarged() {
        return (int) patientsMap.values().stream().filter(patient -> patient.getStatus() == PatientStatus.DISCHARGED).count();
    }

    /**
     * Returns the number of discharged patients who were treated by professionals of a specific specialization.
     *
     * @param specialization The specialization of the professionals to filter by.
     * @return The count of discharged patients treated by professionals of the given specialization.
     */
    public int getNumberOfPatientsAssignedToProfessionalDischarged(String specialization) {
        return (int) patientProfessionalMap.values().stream().filter(patient -> patient.getStatus() == PatientStatus.DISCHARGED && professionalMap.get(patientProfessionalMap.get(patient.getFiscalCode())).getSpecialization().equals(specialization)).count();
    }
}
