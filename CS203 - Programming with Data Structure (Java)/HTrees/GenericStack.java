import java.util.ArrayList;

public class GenericStack<E> extends ArrayList<E> {

	public static void main(String[] args) {

		GenericStack<String> a = new GenericStack<String>();
//		System.out.print(a.isEmpty());

		ArrayList<String> b = new ArrayList<String>();
		ArrayList<Integer> c = new ArrayList<Integer>();

		String[] test = new String[5];
		test[0] = "wat";
		test[1] = "k";
		b.add("wat");
		b.add("k");
		b.add("r");
		b.add("k");
		b.add("b");

		c.add(1);
		c.add(3);
		c.add(2);
		c.add(6);
		c.add(4);

		Integer[] test2 = new Integer[5];
		test2[0] = 5;
		test2[1] = 2;
		test2[2] = 3;
		test2[3] = 1;
		test2[4] = 4;

		Integer[][] test3 = new Integer[2][3];
		test3[0][0] = 2;
		test3[0][1] = 4;
		test3[0][2] = 1;
		test3[1][0] = 9;
		test3[1][1] = 8;
		test3[1][2] = 7;



		System.out.println(a.linearSearch(test, "k"));

		a.selectionSort(test2);

		for(int i = 0; i != test2.length; i++){
			System.out.print("[" + test2[i] + "] ");
		}

		a.removeDuplicates(b);
		System.out.println("\n \n");

		for(int i = 0; i != b.size(); i++){
			System.out.print("[" + b.get(i) + "] ");
		}

		System.out.println("\n" + a.max(test3));

		a.sort(c);
		for(int i = 0; i != c.size(); i++){
			System.out.print("[" + c.get(i) + "] ");
		}
	}

	//#1
	public void push(E value) {
		add(value);
	}

	public E pop() {
		E temp = null;
		temp = get(size());
		remove((size()));
		return temp;
	}

	public E peek() {
		return get(size());
	}

	public boolean isEmpty() {
		return super.isEmpty();

	}

	public int getSize() {
		return size();
	}

	//#2
	public static <E extends Comparable<E>> int linearSearch(E[] list, E key){
		int i = 0;
		while(i <= list.length){
			if(list[i] == key){
				return i;
			}
			i++;
		}
		return -1;
	}

	//#3
	public static <E extends Comparable<E>> int binarySearch(E[] list, E key){
		int low = 0;
		int high = list.length - 1;


		while(low <= high){
			int mid = (low + high) / 2;
			E midList = list[mid];

			if(key == list[mid]){
				return mid;
			}
			else if(key.compareTo(midList) < 0){
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

	//#4
	public static<E extends Comparable<E>> void selectionSort(E[] list){
		int maxIndex = list.length;
		int currentIndex = 0;
		int walker = 0;
		E temp;

		while(currentIndex != maxIndex){
			walker = currentIndex + 1; //stay in front of current index
			while(walker != maxIndex ){
				if(list[currentIndex].compareTo(list[walker]) > 0){
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

	//#5 Extra credit 1
	public static <E> ArrayList<E> removeDuplicates(ArrayList<E> list){
	    int currentIndex = list.size() -1;
	    int walker = list.size() -2;
	    //i will start from the end and delete as i go if duplicates are found
	    while(currentIndex > -1)
	    {

	        while(walker > -1)
	        {
	            if(list.get(currentIndex).equals(list.get(walker)))
	            {
//	                list.get(currentIndex)= list.get(walker + 1);
	            	list.remove(walker);
	                currentIndex = list.size() -1;
	                walker = list.size() - 2;
	            }
	            else
	                walker--;
	        }
	        currentIndex--;
	        walker = currentIndex - 1;
	    }
		return list;

	}

	//#6 Extra Credit 2
	public static <E extends Comparable<E>> E max(E[][] list){
		E largest = list[0][0];
		for(int i = 0; i != list.length; i++){
			for(int j = 0; j != list[i].length;j++){
				if(list[i][j].compareTo(largest) > 0){
					largest = list[i][j];
				}
			}
		}
		return largest;
	}

	//#7 Extra Credit 3
	public static <E extends Comparable<E>> void sort(ArrayList<E> list){
		int maxIndex = list.size();
		int currentIndex = 0;
		int walker = 0;
		E temp;

		while(currentIndex != maxIndex){
			walker = currentIndex + 1; //stay in front of current index
			while(walker != maxIndex ){
				if(list.get(currentIndex).compareTo(list.get(walker)) > 0){
					temp = list.get(currentIndex); //make a copy of current index item
					list.set(currentIndex, list.get(walker));
					list.set(walker,temp); //should have swapped
				}
				else{
					walker++; //go further down the walker

				}
			}
			currentIndex++; //go down the current index
		}

	}
}
