public class MallardDuck extends Duck{
public MallardDuck() {
	quackBehavior = new Quack();
	quackBehavior1 = new ShoutQuack();
	flyBehavior = new FlyWithWings();
	
}
	@Override
	void display() {
		System.out.println("Mallard Duck");
		
		
	}

}
