
public class RedHeadDuck extends Duck{
public RedHeadDuck() {
	flyBehavior = new FlyWithWings();
	quackBehavior = new Quack();
}
	@Override
	void display() {
		System.out.println("Red Head Duck");
		
	}

}
