package social;

import java.util.*;
import static java.util.stream.Collectors.*;


public class Social {
	
	Map<String, Person> people;
	Map<String, Group> groups;
	
	public Social() {
		this.people = new HashMap<>();
		this.groups = new HashMap<>();
	}

	/**
	 * Creates a new account for a person
	 * 
	 * @param code	nickname of the account
	 * @param name	first name
	 * @param surname last name
	 * @throws PersonExistsException in case of duplicate code
	 */
	public void addPerson(String code, String name, String surname)
			throws PersonExistsException {
		if(this.people.containsKey(code))
			throw new PersonExistsException();
		this.people.put(code, new Person(code, name, surname));
	}

	/**
	 * Retrieves information about the person given their account code.
	 * The info consists in name and surname of the person, in order, separated by blanks.
	 * 
	 * @param code account code
	 * @return the information of the person
	 * @throws NoSuchCodeException
	 */
	public String getPerson(String code) throws NoSuchCodeException {
		if(!this.people.containsKey(code))
			throw new NoSuchCodeException();
		return code + " " + this.people.get(code).getName() + " " + this.people.get(code).getSurname();
	}

	/**
	 * Define a friendship relationship between to persons given their codes.
	 * 
	 * Friendship is bidirectional: if person A is friend of a person B, that means that person B is a friend of a person A.
	 * 
	 * @param codePerson1	first person code
	 * @param codePerson2	second person code
	 * @throws NoSuchCodeException in case either code does not exist
	 */
	public void addFriendship(String codePerson1, String codePerson2)
			throws NoSuchCodeException {
		if(!this.people.containsKey(codePerson1) || !this.people.containsKey(codePerson2))
			throw new NoSuchCodeException();
		this.people.get(codePerson1).getFriends().add(codePerson2);
		this.people.get(codePerson2).getFriends().add(codePerson1);
	}

	/**
	 * Retrieve the collection of their friends given the code of a person.
	 * 
	 * 
	 * @param codePerson code of the person
	 * @return the list of person codes
	 * @throws NoSuchCodeException in case the code does not exist
	 */
	public Collection<String> listOfFriends(String codePerson)
			throws NoSuchCodeException {
		if(!this.people.containsKey(codePerson))
			throw new NoSuchCodeException();
		return this.people.get(codePerson).getFriends();
	}

	/**
	 * Retrieves the collection of the code of the friends of the friends
	 * of the person whose code is given, i.e. friends of the second level.
	 * 
	 * 
	 * @param codePerson code of the person
	 * @return collections of codes of second level friends
	 * @throws NoSuchCodeException in case the code does not exist
	 */
	public Collection<String> friendsOfFriends(String codePerson)
			throws NoSuchCodeException {
		if(!this.people.containsKey(codePerson))
			throw new NoSuchCodeException();
		return this.people.get(codePerson).getFriends().stream()
															.map(codeFriends -> this.people.get(codeFriends).getFriends())
															.flatMap(listOfFriends -> listOfFriends.stream())
															.filter(code -> code != codePerson)
															.collect(toList());
	}

	/**
	 * Retrieves the collection of the code of the friends of the friends
	 * of the person whose code is given, i.e. friends of the second level.
	 * The result has no duplicates.
	 * 
	 * 
	 * @param codePerson code of the person
	 * @return collections of codes of second level friends
	 * @throws NoSuchCodeException in case the code does not exist
	 */
	public Collection<String> friendsOfFriendsNoRepetition(String codePerson)
			throws NoSuchCodeException {
		if(!this.people.containsKey(codePerson))
			throw new NoSuchCodeException();
		return this.people.get(codePerson).getFriends().stream()
															.map(codeFriends -> this.people.get(codeFriends).getFriends())
															.flatMap(listOfFriends -> listOfFriends.stream())
															.distinct()
															.filter(code -> code != codePerson)
															.collect(toList());
	}

	/**
	 * Creates a new group with the given name
	 * 
	 * @param groupName name of the group
	 */
	public void addGroup(String groupName) {
		if(!groupName.contains(" "))
			this.groups.put(groupName, new Group(groupName));
	}

	/**
	 * Retrieves the list of groups.
	 * 
	 * @return the collection of group names
	 */
	public Collection<String> listOfGroups() {
		return this.groups.keySet();
	}

	/**
	 * Add a person to a group
	 * 
	 * @param codePerson person code
	 * @param groupName  name of the group
	 * @throws NoSuchCodeException in case the code or group name do not exist
	 */
	public void addPersonToGroup(String codePerson, String groupName) throws NoSuchCodeException {
		if(!this.people.containsKey(codePerson) || !this.groups.containsKey(groupName))
			throw new NoSuchCodeException();
		this.groups.get(groupName).getPeople().add(codePerson);
	}

	/**
	 * Retrieves the list of people on a group
	 * 
	 * @param groupName name of the group
	 * @return collection of person codes
	 */
	public Collection<String> listOfPeopleInGroup(String groupName) {
		return this.groups.get(groupName).getPeople();
	}

	/**
	 * Retrieves the code of the person having the largest
	 * group of friends
	 * 
	 * @return the code of the person
	 */
	public String personWithLargestNumberOfFriends(){
		return this.people.values().stream()
											.map(person -> {
												try {
													return Map.entry(person.getCode(), this.listOfFriends(person.getCode()).size());
												} catch (NoSuchCodeException e) {
													// TODO Auto-generated catch block
													e.printStackTrace();
												}
												return null;
											})
											.max(Comparator.comparing(Map.Entry::getValue))
											.map(entry -> entry.getKey()).get();
	}

	/**
	 * Find the code of the person with largest number
	 * of second level friends
	 * 
	 * @return the code of the person
	 */
	public String personWithMostFriendsOfFriends() {
		return this.people.values().stream()
											.map(person -> {
												try {
													return Map.entry(person.getCode(), this.friendsOfFriends(person.getCode()).size());
												} catch (NoSuchCodeException e) {
													// TODO Auto-generated catch block
													e.printStackTrace();
												}
												return null;
											})
											.max(Comparator.comparing(Map.Entry::getValue))
											.map(entry -> entry.getKey()).get();
	}

	/**
	 * Find the name of group with the largest number of members
	 * 
	 * @return the name of the group
	 */
	public String largestGroup() {
		return this.groups.values().stream()
											.map(group -> Map.entry(group.getName(), this.listOfPeopleInGroup(group.getName()).size()))
											.max(Comparator.comparing(Map.Entry::getValue))
											.map(Map.Entry::getKey).get();
	}

	/**
	 * Find the code of the person that is member of
	 * the largest number of groups
	 * 
	 * @return the code of the person
	 */
	public String personInLargestNumberOfGroups() {
		return this.groups.values().stream()
											.map(group -> group.getPeople())
											.flatMap(list -> list.stream())
											.collect(groupingBy(code -> code, HashMap::new, counting()))
											.entrySet().stream()
											.max(Comparator.comparing(Map.Entry::getValue))
											.map(entry -> entry.getKey()).get();
	}
}

//============================================================
//============================================================
//============================================================

// package social;

// import java.util.*;
// import java.util.stream.Collectors;


// public class Social {

// 	TreeMap<String, Subscriber> subscriberMap = new TreeMap<>();
// 	TreeMap<String, Group> groupMap = new TreeMap<>();

// 	private String pid = "P" + "0";


// 	/**
// 	 * Creates a new account for a person
// 	 * 
// 	 * @param code	nickname of the account
// 	 * @param name	first name
// 	 * @param surname last name
// 	 * @throws PersonExistsException in case of duplicate code
// 	 */
// 	public void addPerson(String code, String name, String surname) throws PersonExistsException {
// 		if(subscriberMap.containsKey(code))
// 			throw new PersonExistsException();

// 		Subscriber s = new Subscriber(code, name, surname);
// 		subscriberMap.put(code, s);
// 	}

// 	/**
// 	 * Retrieves information about the person given their account code.
// 	 * The info consists in name and surname of the person, in order, separated by blanks.
// 	 * 
// 	 * @param code account code
// 	 * @return the information of the person
// 	 * @throws NoSuchCodeException
// 	 */
// 	public String getPerson(String code) throws NoSuchCodeException {
// 		if(!subscriberMap.containsKey(code))
// 			throw new NoSuchCodeException();

// 		return subscriberMap.get(code).getCode() + " " + subscriberMap.get(code).getName() + " " +
// 		 subscriberMap.get(code).getSurname();
// 	}

// 	/**
// 	 * Define a friendship relationship between to persons given their codes.
// 	 * 
// 	 * Friendship is bidirectional: if person A is friend of a person B, that means that person B is a friend of a person A.
// 	 * 
// 	 * @param codePerson1	first person code
// 	 * @param codePerson2	second person code
// 	 * @throws NoSuchCodeException in case either code does not exist
// 	 */
// 	public void addFriendship(String codePerson1, String codePerson2) throws NoSuchCodeException {
// 		if(!subscriberMap.containsKey(codePerson1) || !subscriberMap.containsKey(codePerson2))
// 			throw new NoSuchCodeException();
		
// 		subscriberMap.get(codePerson1).getFriendsList().add(subscriberMap.get(codePerson2)); //aggiungo alla lista di una
// 		//persona l'intero oggetto subscriber dell'altra persona con cui è amica, non solo il suo codice
// 		subscriberMap.get(codePerson1).getFriendsList().add(subscriberMap.get(codePerson2));

// 	}

// 	/**
// 	 * Retrieve the collection of their friends given the code of a person.
// 	 * 
// 	 * 
// 	 * @param codePerson code of the person
// 	 * @return the list of person codes
// 	 * @throws NoSuchCodeException in case the code does not exist
// 	 */
// 	public Collection<String> listOfFriends(String codePerson) throws NoSuchCodeException {
// 		if(!subscriberMap.containsKey(codePerson))
// 			throw new NoSuchCodeException();

// 		/*ArrayList<String> tmp = new ArrayList<>();

// 		for (Subscriber s : subscriberMap.get(codePerson).getFriendsList())
// 			tmp.add(s.getName());
	
// 		return tmp;*/
// 		//return subscriberMap.get(codePerson).getFriendsList().stream().map(x -> x.getCode()).toList();
// 		return subscriberMap.get(codePerson).getFriendsList().stream().map(x -> x.getCode()).collect(Collectors.toList());
// 	}

// 	/**
// 	 * Retrieves the collection of the code of the friends of the friends
// 	 * of the person whose code is given, i.e. friends of the second level.
// 	 * 
// 	 * 
// 	 * @param codePerson code of the person
// 	 * @return collections of codes of second level friends
// 	 * @throws NoSuchCodeException in case the code does not exist
// 	 */
// 	public Collection<String> friendsOfFriends(String codePerson) throws NoSuchCodeException {
// 		if(!subscriberMap.containsKey(codePerson))
// 			throw new NoSuchCodeException();

// 		return subscriberMap.get(codePerson).getFriendsList().stream()
// 					 .map(x->x.getFriendsList())
// 					 .flatMap(l -> l.stream())
// 					 .map(x -> x.getCode())
// 					 .filter(x -> !x.equals(codePerson))
// 					 .collect(Collectors.toList());
// 	}

// 	/**
// 	 * Retrieves the collection of the code of the friends of the friends
// 	 * of the person whose code is given, i.e. friends of the second level.
// 	 * The result has no duplicates.
// 	 * 
// 	 * 
// 	 * @param codePerson code of the person
// 	 * @return collections of codes of second level friends
// 	 * @throws NoSuchCodeException in case the code does not exist
// 	 */
// 	public Collection<String> friendsOfFriendsNoRepetition(String codePerson) throws NoSuchCodeException {
// 		if(!subscriberMap.containsKey(codePerson))
// 			throw new NoSuchCodeException();

// 		return subscriberMap.get(codePerson).getFriendsList().stream()
// 					.map(x->x.getFriendsList())
// 					.flatMap(l -> l.stream())
// 					.map(x -> x.getCode())
// 					.filter(x -> !x.equals(codePerson))
// 					.collect(Collectors.toSet());
// 	}

// 	/**
// 	 * Creates a new group with the given name
// 	 * 
// 	 * @param groupName name of the group
// 	 */
// 	public void addGroup(String groupName) {
// 		Group g = new Group(groupName);
// 		groupMap.put(groupName, g);
// 	}

// 	/**
// 	 * Retrieves the list of groups.
// 	 * 
// 	 * @return the collection of group names
// 	 */
// 	public Collection<String> listOfGroups() {
// 		return groupMap.keySet();
// 	}

// 	/**
// 	 * Add a person to a group
// 	 * 
// 	 * @param codePerson person code
// 	 * @param groupName  name of the group
// 	 * @throws NoSuchCodeException in case the code or group name do not exist
// 	 */
// 	public void addPersonToGroup(String codePerson, String groupName) throws NoSuchCodeException {
// 		if(!subscriberMap.containsKey(codePerson) || !groupMap.containsKey(groupName))
// 			throw new NoSuchCodeException();

// 		groupMap.get(groupName).getSubscriberList().add(subscriberMap.get(codePerson));
// 		subscriberMap.get(codePerson).getGroupList().add(groupMap.get(groupName));
// 	}

// 	/**
// 	 * Retrieves the list of people on a group
// 	 * 
// 	 * @param groupName name of the group
// 	 * @return collection of person codes
// 	 */
// 	public Collection<String> listOfPeopleInGroup(String groupName) {
// 		return groupMap.get(groupName).getSubscriberList().stream().map(x->x.getCode()).collect(Collectors.toList());
// 	}

// 	/**
// 	 * Retrieves the code of the person having the largest
// 	 * group of friends
// 	 * 
// 	 * @return the code of the person
// 	 */
// 	public String personWithLargestNumberOfFriends() {
// 		return subscriberMap.values().stream()
// 		//.groupingBy(Subscriber::getCode, TreeMap::new, x->x.getFriendsList().length())
// 		.max(Comparator.comparingInt(x->x.getFriendsList().size()))
// 		.map(x->x.getCode())
// 		.orElse(null);
// 	}

// 	/**
// 	 * Find the code of the person with largest number
// 	 * of second level friends
// 	 * 
// 	 * @return the code of the person
// 	 */
// 	public String personWithMostFriendsOfFriends() {
// 		return subscriberMap.values().stream()//streammo tutti i miei subscriber
// 			   .map(x->x.getFriendsList()) //prendo le friends list di ognuno
// 			   .flatMap(x->x.stream())//essendo che ho uno stream di liste, le streammo per "unwrapparle" dal container ArrayList
// 			   .max(Comparator.comparing(x->x.getFriendsList().size())) //sugli amici degli amici unwrappati considero solo l'elemento con la dimensione della sua lista di amici più grande
// 			   .map(x->x.getCode()) //dal max mi uscirà un solo subscriber e di quello considero il codice
// 			   .orElse(null); // nel caso non uscisse nessuo dal max ritorno null, è solo per completezza
// 	}

// 	/**
// 	 * Find the name of group with the largest number of members
// 	 * 
// 	 * @return the name of the group
// 	 */
// 	public String largestGroup() {
// 		return groupMap.values().stream()
// 			   //.map(Group::getSubscriberList) //è sbagliato perchè la subscriberList la considero già nel max
// 			   .max(Comparator.comparing(x->x.getSubscriberList().size()))
// 			   .map(x->x.getName())
// 			   .orElse(null);
// 	}

// 	/**
// 	 * Find the code of the person that is member of
// 	 * the largest number of groups
// 	 * 
// 	 * @return the code of the person
// 	 */
// 	public String personInLargestNumberOfGroups() {
// 		return subscriberMap.values().stream()
// 				.max(Comparator.comparing(subscriber -> subscriber.getGroupList().size()))
// 				.map(Subscriber::getCode)
// 				.orElse(null);
// 	}

// 	/**
// 	 * add a new post by a given account
// 	 * @param author the id of the post author
// 	 * @param text the content of the post
// 	 * @return a unique id of the post
// 	 */
//     public String post(String author, String text) {
// 		Post p = new Post(author, text,pid+=1);
// 		subscriberMap.get(author).getPostMap().put(pid, p);
// 		return pid;
//     }

// 	/**
// 	 * retrieves the content of the given post
// 	 * @param author	the author of the post
// 	 * @param pid		the id of the post
// 	 * @return the content of the post
// 	 */
//     public String getPostContent(String author, String pid) {
// 		return subscriberMap.get(author).getPostMap().get(pid).getText();
//     }

// 	/**
// 	 * retrieves the timestamp of the given post
// 	 * @param author	the author of the post
// 	 * @param pid		the id of the post
// 	 * @return the timestamp of the post
// 	 */
//     public long getTimestamp(String author, String pid) {
// 		return subscriberMap.get(author).getPostMap().get(pid).getTime();
//     }

// 	/**
// 	 * returns the list of post of a given author paginated 
// 	 * 
// 	 * @param author	author of the post
// 	 * @param pageNo	page number (starting at 1)
// 	 * @param pageLength page length
// 	 * @return the list of posts id
// 	 */
//     public List<String> getPaginatedUserPosts(String author, int pageNo, int pageLength) {
// 		return null;
//     }

// 	/**
// 	 * returns the paginated list of post of friends 
// 	 * 
// 	 * the returned list contains the author and the id of a post separated by ":"
// 	 * 
// 	 * @param author	author of the post
// 	 * @param pageNo	page number (starting at 1)
// 	 * @param pageLength page length
// 	 * @return the list of posts key elements
// 	 */
// 	public List<String> getPaginatedFriendPosts(String author, int pageNo, int pageLength) {
// 		return null;
// 	}
// }