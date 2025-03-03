package it.polito.ski;

import java.io.*;
import java.util.*;

public class SkiArea {
	
	private String name;
	//private List<Lift> liftList = new ArrayList<>();
	private TreeMap<String, LiftType> liftTypeMap = new TreeMap<>();
	private TreeMap<String, String> nameTypeList = new TreeMap<>();
	private TreeMap<String, Slope> slopeMap = new TreeMap<>();
	private TreeMap<String, Parking> parkingMap = new TreeMap<>();
	private TreeMap<String, String> liftParkingMap = new TreeMap<>();
	
	/**
	 * Creates a new ski area
	 * @param name name of the new ski area
	 */
	public SkiArea(String name) {
		this.name = name;
    }

	/**
	 * Retrieves the name of the ski area
	 * @return name
	 */
	public String getName() { return name; }

    /**
     * define a new lift type providing the code, the category (Cable Cabin, Chair, Ski-lift)
     * and the capacity (number of skiers carried) of a single unit
     * 
     * @param code		name of the new type
     * @param category	category of the lift
     * @param capacity	number of skiers per unit
     * @throws InvalidLiftException in case of duplicate code or if the capacity is <= 0
     */
    public void liftType(String code, String category, int capacity) throws InvalidLiftException {
    	/*for(Lift l : liftList) {
    		if(l.getCode().equals(code) || capacity == 0)
    			throw new InvalidLiftException();
    	}
    	Lift l = new Lift(code, category, capacity);
    	liftList.add(l);*/
    	
		if(liftTypeMap.keySet().contains(code))
			throw new InvalidLiftException();
    	
    	LiftType l = new LiftType(code, category, capacity);
    	liftTypeMap.put(code, l);
    }
    
    /**
     * retrieves the category of a given lift type code
     * @param typeCode lift type code
     * @return the category of the type
     * @throws InvalidLiftException if the code has not been defined
     */
    public String getCategory(String typeCode) throws InvalidLiftException {
    	/*Boolean trovato = false;
    	for(Lift l : liftList) {
    		if(l.getCode().equals(typeCode)) {
    			trovato = true;
    			return l.getCategory();    		}
    	}
    	
    	if(trovato == false)
    		throw new InvalidLiftException();
    	
		return null;*/
    	
		if(!liftTypeMap.keySet().contains(typeCode))
    		throw new InvalidLiftException();
    	
		return liftTypeMap.get(typeCode).getCategory();
    }

    /**
     * retrieves the capacity of a given lift type code
     * @param typeCode lift type code
     * @return the capacity of the type
     * @throws InvalidLiftException if the code has not been defined
     */
    public int getCapacity(String typeCode) throws InvalidLiftException {
    	/*Boolean trovato = false;
    	for(Lift l : liftList) {
    		if(l.getCode().equals(typeCode)) {
    			trovato = true;
    			return l.getSeats();    		
    		}
    	}
    	
    	if(trovato == false)
    		throw new InvalidLiftException();
    	
		return -1;*/
		
		if(!liftTypeMap.keySet().contains(typeCode))
    		throw new InvalidLiftException();
    	
		return liftTypeMap.get(typeCode).getSeats();
    }


    /**
     * retrieves the list of lift types
     * @return the list of codes
     */
	public Collection<String> types() {
		return liftTypeMap.keySet();
	}
	
	/**
	 * Creates new lift with given name and type
	 * 
	 * @param name		name of the new lift
	 * @param typeCode	type of the lift
	 * @throws InvalidLiftException in case the lift type is not defined
	 */
    public void createLift(String name, String typeCode) throws InvalidLiftException{
    	if(!liftTypeMap.keySet().contains(typeCode))
    		throw new InvalidLiftException();
    	
    	liftTypeMap.get(typeCode).setLiftSet(name);
    	nameTypeList.put(name, typeCode);
    }
    
	/**
	 * Retrieves the type of the given lift
	 * @param lift 	name of the lift
	 * @return type of the lift
	 */
	public String getType(String lift) {
		return nameTypeList.get(lift);
	}

	/**
	 * retrieves the list of lifts defined in the ski area
	 * @return the list of names sorted alphabetically
	 */
	public List<String> getLifts(){
		return nameTypeList.keySet().stream().toList();
    }

	/**
	 * create a new slope with a given name, difficulty and a starting lift
	 * @param name			name of the slope
	 * @param difficulty	difficulty
	 * @param lift			the starting lift for the slope
	 * @throws InvalidLiftException in case the lift has not been defined
	 */
	public void createSlope(String name, String difficulty, String lift) throws InvalidLiftException {
		if (!nameTypeList.keySet().contains(lift))
			throw new InvalidLiftException();
		slopeMap.put(name, new Slope(name, difficulty, lift));
	}
    
    /**
     * retrieves the name of the slope
     * @param slopeName name of the slope
     * @return difficulty
     */
	public String getDifficulty(String slopeName) {
		return slopeMap.get(slopeName).getDifficulty();
	}

	/**
	 * retrieves the start lift
	 * @param slopeName name of the slope
	 * @return starting lift
	 */
	public String getStartLift(String slopeName) {
		return slopeMap.get(slopeName).getLiftName();
	}

	/**
	 * retrieves the list of defined slopes
	 * 
	 * @return list of slopes
	 */
    public Collection<String> getSlopes(){
		return slopeMap.keySet();
    }

    /**
     * Retrieves the list of slopes starting from a given lift
     * 
     * @param lift the starting lift
     * @return the list of slopes
     */
    public Collection<String> getSlopesFrom(String lift){
    	return slopeMap.values().stream().filter(s -> s.getLiftName().equals(lift)).map(Slope::getName).toList();
    }

    /**
     * Create a new parking with a given number of slots
     * @param name 	new parking name
     * @param slots	slots available in the parking
     */
    public void createParking(String name, int slots){
    	parkingMap.put(name,new Parking(name, slots));
    }

    /**
     * Retrieves the number of parking slots available in a given parking
     * @param parking	parking name
     * @return number of slots
     */
	public int getParkingSlots(String parking) {
		return parkingMap.get(parking).slots;
	}

	/**
	 * Define a lift as served by a given parking
	 * @param lift		lift name
	 * @param parking	parking name
	 */
	public void liftServedByParking(String lift, String parking) {
		liftParkingMap.put(lift, parking);
	}

	
	/**
	 * Retrieves the list of lifts served by a parking.
	 * @param parking	parking name
	 * @return the list of lifts
	 */
	public Collection<String> servedLifts(String parking) {
		return liftParkingMap.keySet().stream().filter(x -> liftParkingMap.get(x).equals(parking)).toList();
	}

	/**
	 * Checks whether the parking is proportional to the capacity of the lift it is serving.
	 * A parking is considered proportionate if its size divided by the sum of the capacity of the lifts 
	 * served by the parking is less than 30.
	 * 
	 * @param parkingName name of the parking to check
	 * @return true if the parking is proportionate
	 */
	public boolean isParkingProportionate(String parkingName) {
		Integer seats = 0;
		for(String s : servedLifts(parkingName)){
			for(LiftType f : liftTypeMap.values()) {
				for(Lift l : f.getLiftSet()) {
					if(l.getName().equals(s))
						seats+=f.getSeats();
				}
			}
		}
		if((parkingMap.get(parkingName).slots/seats)<30)
			return true;
		return false;
	}

	/**
	 * reads the description of lift types and lift descriptions from a text file. 
	 * The contains a description per line. 
	 * Each line starts with a letter indicating the kind of information: "T" stands for Lift Type, 
	 * while "L" stands for Lift.
	 * A lift type is described by code, category and seat number. 
	 * A lift is described by the name and the lift type.
	 * Different data on a line are separated by ";" and possible spaces surrounding the separator are ignored.
	 * If a line contains the wrong number of information it should be skipped and
	 * the method should continue reading the following lines. 
	 * 
	 * @param path 	the path of the file
	 * @throws IOException	in case IO error
	 * @throws InvalidLiftException in case of duplicate type or non-existent lift type
	 */
    public void readLifts(String path) throws IOException, InvalidLiftException {
		BufferedReader r = new BufferedReader(new FileReader(path));
			String tmp= null;
		    while((tmp=r.readLine())!=null) {
				if(tmp.split("\s*;\s*")[0].equals("T") && tmp.split("\s*;\s*").length==4)
						liftType(tmp.split("\s*;\s*")[1], tmp.split("\s*;\s*")[2], Integer.parseInt(tmp.split("\s*;\s*")[3]));
				else if(tmp.split("\s*;\s*").length==3)
					 createLift(tmp.split("\s*;\s*")[1], tmp.split("\s*;\s*")[2]);
					}	
				}
			}