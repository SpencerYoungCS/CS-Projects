public class LoudmouthDuck extends Duck{
	public LoudmouthDuck() {
	flyBehavior = new FlyWithWings();
	quackBehavior = new ShoutQuack();
	}
	@Override
	void display() {
		System.out.println("Loudmouth Duck");
		
	}

}
