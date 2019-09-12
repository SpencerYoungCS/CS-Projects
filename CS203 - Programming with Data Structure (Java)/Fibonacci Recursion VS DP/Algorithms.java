import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Algorithms {

	//#Lab 4 #1--------------------------------
	public static void main(String[] args) {
		System.out.println("Recursive Fibonacci Time 10: " + getRecursiveFibonacciTime(10));
		System.out.println("Recursive Fibonacci Time 20: " + getRecursiveFibonacciTime(20));
		System.out.println("Recursive Fibonacci Time 40: " + getRecursiveFibonacciTime(40));
		System.out.println("Dynamic Fibonacci Time 10: " + getDynamicFibonacciTime(10));
		System.out.println("Dynamic Fibonacci Time 20: " + getDynamicFibonacciTime(20));
		System.out.println("Dynamic Fibonacci Time 40: " + getDynamicFibonacciTime(40));

		System.out.println("Now Executing Lab 1 Program....");
		System.out.println("\n\n\n\n");

		//------------- #1 program-----------

		ArrayList<TwoElementNode> userList = new ArrayList<TwoElementNode>();
		Scanner scanner = new Scanner(System.in);
		boolean restart = false;
		do{
			boolean duplicate = false;
			System.out.println("Please enter an Integer");
			int userInput = scanner.nextInt();
			for(int i = 0; i != userList.size(); i++){
				if(userList.get(i).getNumber().equals(userInput)){
					userList.get(i).setOccurances(userList.get(i).getOccurances() + 1);
					duplicate = true;
				}
			}
			if(!duplicate){
					TwoElementNode temp = new TwoElementNode();
					temp.setNumber(userInput);
					temp.setOccurances(1);
					userList.add(temp);
			}
			//If user enters 0, it ends the program
			if(userInput == 0){
				restart = false;
			}
			else{
				restart = true;
			}
		}while(restart);
		int largestInt = 0;
		//finding most occurances
		for(int i = 0; i != userList.size(); i++){
			if(userList.get(i).getOccurances() >= largestInt){
				largestInt = userList.get(i).getOccurances();
			}
		}

		//finding all with the same occurances
		System.out.println("These number/s have the most occurances");
		for(int i = 0; i != userList.size(); i++){
			if(userList.get(i).getOccurances().equals(largestInt)){
				System.out.println(userList.get(i).getOccurances() + ":" + userList.get(i).getNumber());
			}
		}
	}


	//#2-----------------------------------


	public static int fibonacci(int n){
	    if(n == 0)
	        return 0;
	    else if(n == 1)
	      return 1;
	   else{
//		   System.out.println(n);
	      return fibonacci(n - 1) + fibonacci(n - 2);
	   }
	}


	public static long dyanmicFibonacci(long n){
		long f0 = 0;
		long f1 = 1;
		long f2 = 1;

		if(n == 0)
			return f0;
		else if(n == 1)
			return f1;
		else if (n == 2)
			return f2;

		for(int i = 3; i <= n; i++){
			f0 = f1;
			f1 = f2;
			f2 = f0 + f1;
		}

		return f2;
	}



public static long getDynamicFibonacciTime(int n){
		long startTime = System.currentTimeMillis();
		dyanmicFibonacci(n);
		return (System.currentTimeMillis()-startTime);
}

public static long getRecursiveFibonacciTime(int n){
		long startTime = System.currentTimeMillis();
		fibonacci(n);
		return (System.currentTimeMillis()-startTime);
}


	public static class TwoElementNode{
		private Integer occurances;
		private Integer number;
		public TwoElementNode(){
			occurances = new Integer(1);
			number = new Integer(0);
		}
		public TwoElementNode(Integer Occurances, Integer Number){
			occurances = Occurances;
			number = Number;
		}
		public void setOccurances(Integer newOccurances){
			occurances = newOccurances;
		}
		public void setNumber(Integer newNumber){
			number = newNumber;
		}
		public Integer getOccurances(){
			return occurances;
		}
		public Integer getNumber(){
			return number;
		}

	}


}
