
public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BST<Integer> test = new BST<Integer>();

		test.insert(3);
		test.insert(2);
		test.insert(4);
		test.insert(5);
		test.insert(1);
		test.insert(6);

		AVLTree<Integer> test2 = new AVLTree<Integer>();
		test2.insert(2);
		test2.insert(4);
		test2.insert(5);
		test2.insert(1);
		test2.insert(6);


//		System.out.println(test.getRoot().element);

		System.out.println(test2.getNumberOfLeaves(test.getRoot()));
		System.out.println(test2.getNumberOfNonLeaves(test.getRoot()));
		test.breadthFirstTraversal(test2.getRoot());
		System.out.println("\n");

		System.out.println("Sample code: find 5");
		System.out.println(test2.find(5,test2.getRoot()));



	}

}
