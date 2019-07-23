
public class DuckPond {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
MallardDuck duck1 = new MallardDuck();
duck1.display();
duck1.performQuack();
duck1.setQuackBehavior(new ShoutQuack());
duck1.performQuack();
duck1.performFly();
System.out.println("");

LoudmouthDuck loud = new LoudmouthDuck();
loud.display();
loud.performQuack();
loud.performFly();

	}

}
