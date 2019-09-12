public class Sorting {

	public static void main(String[] args) {
		Integer[] test = new Integer[4];
		test[0] = 2;
		test[1] = 1;
		test[2] = 4;
		test[3] = 3;

		heapSort(test);
		for(int i = 0; i != test.length; i++)
			System.out.println(test[i]);


	}
	public static <E extends Comparable<E>> void insertionSort(E[] test){
		int maxIndex = test.length;
		int currentIndex = 0;
		int walker = 0;
		E temp;

		while(currentIndex != maxIndex){
			walker = currentIndex + 1; //stay in front of current index
			while(walker != maxIndex){
				if((int)test[currentIndex] > (int)test[walker]){
					temp = (E)test[currentIndex]; //make a copy of current index item
					test[currentIndex] = test[walker];
					test[walker] = temp; //should have swapped
				}
				else{
					walker++; //go further down the walker
				}
			}
			currentIndex++; //go down the current index
		}
	}

	public static <E extends Comparable<E>> void bubbleSort(E[] list){
		int j;
		boolean flag = true;   // set flag to true to begin first pass
		E temp;   //holding variable

		while ( flag )
		{
			flag= false;    //set flag to false awaiting a possible swap
			for( j=0;  j < list.length -1;  j++ )
			{
				if ( list[ j ].compareTo(list[j+1]) > 0)   // change to > for ascending sort
				{
					temp =  list[ j ];                //swap elements
					list[ j ] = list[ j+1 ];
					list[ j+1 ] = temp;
					flag = true;              //shows a swap occurred
				}
			}
		}
	}

	public static <E extends Comparable<E>> void mergeSort(Object[] list){
		if (list.length > 1) {
			E[] temp;
			Object[] firstHalf = new Object[list.length/2];
			System.arraycopy(list, 0, list, 0, list.length/2);
			mergeSort(firstHalf);

			int secondHalfLength = list.length - list.length / 2;
			Object[] secondHalf = new Object[secondHalfLength];
			System.arraycopy(list, list.length/2, secondHalf, 0, secondHalfLength);
			mergeSort(secondHalf);

			merge(firstHalf,secondHalf, list);
		}
	}

	public static <E extends Comparable<E>> void merge(E[] list1, E[] list2, Object[] temp){
		int current1 = 0;
		int current2 = 0;
		int current3 = 0;
		while(current1 < list1.length && current2 < list2.length){
		if(list1[current1].compareTo(list2[current2]) < 0){
			temp[current3++] = list1[current1++];
		}
		else{
			temp[current3++] = list2[current2++];
		}
		}

		while(current1 < list1.length)
			temp[current3++] = list1[current1++];
		while(current2 < list2.length)
			temp[current3++] = list2[current2++];
	}

	public static <E extends Comparable<E>> void heapSort(E[] list){
		Heap<E> heap = new Heap<>();

		for(int i = 0; i < list.length; i++){
			heap.add(list[i]);
		}
		for(int i = list.length - 1; i >= 0; i--){
			list[i] = heap.remove();
		}
	}
}
