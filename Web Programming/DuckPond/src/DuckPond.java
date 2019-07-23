
public class DuckPond {

	public static void main(String[] args) {
		
		//Mallard Duck Regular quack
		System.out.println("Mallard Duck:");
		Duck mallard = new MallardDuck();
		mallard.performQuack();
		
		//loudmouth Duck quacking
		System.out.println("Loudmouth Duck:");
		Duck loudmouth = new LoudmouthDuck();
		loudmouth.performQuack();

		//Same mallard Duck changing quack at runtime
		System.out.println("Mallard Duck:");
		QuackBehavior shouting = new ShoutingQuack();
		mallard.setQuackBehavior(shouting);
		mallard.performQuack();
		
	}
}
