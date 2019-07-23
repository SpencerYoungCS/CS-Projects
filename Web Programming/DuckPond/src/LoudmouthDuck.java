
public class LoudmouthDuck extends Duck{

	public LoudmouthDuck() {
		quackBehavior = new ShoutingQuack();
	}

	public void performQuack() {
		quackBehavior.quack();
	}

}
