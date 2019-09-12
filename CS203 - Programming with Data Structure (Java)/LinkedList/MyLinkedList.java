import java.util.LinkedList;



public class MyLinkedList<E> extends LinkedList<E> {


	public boolean add(E e){
		return super.add(e);
	}

	public void clear(){
		super.clear();
	}

	public boolean Contains(E e){
		return super.contains(e);
	}

	public E get(int index){
		return super.get(index);
	}

	public int IndexOf(E e){
		return super.indexOf(e);
	}
	 

	public E set(int index, E e){
		return super.set(index, e);
	}

	public boolean isEmpty(){
		return super.isEmpty();
	}

	public int size(){
		return super.size();
	}

}



