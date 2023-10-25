// Linked-List operations simulating airport ground traffic
// carson Gedeus

public class GroundTraffic
{
	public AirCraft head;

	public class AirCraft 
	{
		String airLine;
		Integer flightNumber;
		AirCraft nextAircraft;
		
		AirCraft(String airLn, Integer flightNum) {
			airLine = airLn;
			flightNumber = flightNum;
		};
	}
	
	public GroundTraffic insertToTraffic(GroundTraffic groundTrafficLLinkedList, 
			String airline, Integer flightnumber)
	{
		AirCraft airVehicle = new AirCraft(airline, flightnumber);
		
		if (groundTrafficLLinkedList.head == null)
		{
			groundTrafficLLinkedList.head = airVehicle;
		}
		else
		{
			AirCraft movingNode = groundTrafficLLinkedList.head;
			
			while (movingNode.nextAircraft != null)
			{
				movingNode = movingNode.nextAircraft;
			}
			movingNode.nextAircraft = airVehicle;
		}
		return groundTrafficLLinkedList;
	}
	
	
	public static void printList(GroundTraffic groundTraffic)
	{
		while (groundTraffic.head != null)
		{
			System.out.print(groundTraffic.head.airLine + " ");
			System.out.println(groundTraffic.head.flightNumber);
			
			groundTraffic.head = groundTraffic.head.nextAircraft;
		}
	}
	
	
	public static void main(String[] args)
	{
		GroundTraffic groundTraffic = new GroundTraffic();
		groundTraffic.insertToTraffic(groundTraffic, "American Airlines", 1232);
		groundTraffic.insertToTraffic(groundTraffic, "Delta", 889);
		groundTraffic.insertToTraffic(groundTraffic, "Jet Blue", 568);
		groundTraffic.insertToTraffic(groundTraffic, "Jet Blue", 1010);
		groundTraffic.insertToTraffic(groundTraffic, "Spirit", 4344);
		
		printList(groundTraffic);
	}
}