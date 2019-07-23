
public abstract class Duck {
	FlyBehavior flyBehavior;
	QuackBehavior quackBehavior;
	QuackBehavior quackBehavior1;
 
	public Duck() {
	}
 
	public void setFlyBehavior (FlyBehavior fb) {
		flyBehavior = fb;
	}
 
	public void setQuackBehavior(QuackBehavior qb) {
		quackBehavior = qb;
	}
 
	abstract void display();
 
	public void performFly() {
		flyBehavior.fly();
	}
 
	public void performQuack() {
		quackBehavior.quack();
		//quackBehavior1.quack();
	}
 
	public static void swim() {
		System.out.println("All ducks float, even decoys!");
	}
}
