
public class MallardDuck extends Duck{

	public MallardDuck() {
		quackBehavior = new Quack();
	}
	
	public void performQuack() {
		quackBehavior.quack();
	}
	
}
