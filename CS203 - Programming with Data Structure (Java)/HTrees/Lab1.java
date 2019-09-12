
public class Lab1 {

	public static void main(String[] args) {

		//tests
		System.out.println("reverse: 2345");
		reverseDisplay("2345");

		System.out.println((2^2));

		System.out.println("\nreverse: Watermelon ");
		reverseDisplay("Watermelon");

		System.out.println("\nsum Digits: 1234");
		System.out.println(sumDigits(1234));

		System.out.println("\ncount: hello, l");
		System.out.println(count("Hello", 'l'));

		double[] text = new double[4];
		text[0] = 5;
		text[1] = 2;
		text[2] = 3;
		text[3] = 1;

		System.out.println("\nsort this list");
		for(int i = 0; i < 4; i++){
			System.out.print("[" +text[i] + "] ");
		}

		sort(text);

		System.out.println("\nSorted: ");

		for(int i = 0; i < 4; i++){
			System.out.print("[" +text[i] + "] ");
		}


		int[] text2 = new int[5];
		text2[0] = 1;
		text2[1] = 2;
		text2[2] = 3;
		text2[3] = 4;
		text2[4] = 5;

		System.out.println("\n\nSearching this list:");
		for(int i = 0; i < 5; i++){
			System.out.print("[" +text2[i] + "] ");
		}

		System.out.println("\n\nRecursive Binary search for 2:");
		System.out.println(recursiveBinarySearch(text2,2));



	}

	//#1
	public static void reverseDisplay(int value){
		//implement body

		//			reverseDisplay(String.valueOf(value));
		//if were on to the last number....
		if (value < 10) {
			System.out.println(value);
		}
		else {
			//so here basically im using modulus 10 by plucking out the last number
			//then ill divide by the value by 10
			System.out.println(value%10);
			reverseDisplay(value/10);
		}
	}
	//#2
	public static void reverseDisplay(String value){
		//implement body

		//ill have it print the first letter but let it recurse through the word first
		//therefore when it comes back up, it will print;

		//if its at the end stop.
		if(value.length() == 1){
			System.out.print(value);
		}
		else{
			reverseDisplay(value.substring(1));
			System.out.print(value.charAt(0));
		}
	}
	//extra credit
	public static int sumDigits(int value){

		if(value == 0){
			return value;
		}
		else{
			//recurse diving by 10 until it it cant anymore. once it reaches last
			//digit then as it traverses up, it add the modulus (last number each time)
			return sumDigits((value/10)) + value%10;
		}
	}
	//extra credit
	public static int count(String S, char a){

		if(S.charAt(1) == a){
			return 1;
		}
		else{
			//here i just return 1 whenever it the first letter of the string returned
			//is the char im looking for. otherwise same thing as above
			return count(S.substring(1), a) + 1;
		}
	}
	//#3
	public static void sort(double[] list){
		int maxIndex = list.length;
		int currentIndex = 0;
		int walker = 0;
		double temp = 0;

		while(currentIndex != maxIndex){
			walker = currentIndex + 1; //stay in front of current index
			while(walker != maxIndex ){
				if(list[currentIndex] > list[walker]){
					temp = list[currentIndex]; //make a copy of current index item
					list[currentIndex] = list[walker];
					list[walker] = temp; //should have swapped
				}
				else{
					walker++; //go further down the walker

				}
			}
			currentIndex++; //go down the current index
		}
	}


	//#4
	public static int recursiveBinarySearch(int[] list, int key) {
		int low = 0;
		int high = list.length - 1;


		while(low <= high){
			int mid = (low + high) / 2;
			if(key == list[mid]){
				return mid;
			}
			else if(list[mid] < key){
				//if lower end... make the low the current mid
				low = mid + 1;
			}
			else{
				//if higher than mid... make the high the current mid
				high = mid -1;
			}
		}

		return -1; //not found
	}
}
