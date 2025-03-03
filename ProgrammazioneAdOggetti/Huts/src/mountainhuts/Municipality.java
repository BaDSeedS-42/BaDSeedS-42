package mountainhuts;

/**
 * Class representing a municipality that hosts a mountain hut.
 * It is a data class with getters for name, province, and altitude
 * 
 */
public class Municipality {
	
	protected String name;
	protected String province;
	protected int altitude;
	
	public Municipality(String name, String province, Integer altitude) {
		this.name = name;
		this.province = province;
		this.altitude = altitude;
	}

	public String getName() {
		return this.name;
	}

	public String getProvince() {
		return this.province;
	}

	public Integer getAltitude() {
		return this.altitude;
	}

}


//======================================================
//======================================================
//======================================================

// package mountainhuts;

// /**
//  * Class representing a municipality that hosts a mountain hut.
//  * It is a data class with getters for name, province, and altitude
//  * 
//  */
// public class Municipality {
// 	public Municipality(String name, String province, Integer altitude) {
// 	}

// 	public String getName() {
// 		return null;
// 	}

// 	public String getProvince() {
// 		return null;
// 	}

// 	public Integer getAltitude() {
// 		return null;
// 	}

// }
