
public abstract class Duck {
	
	protected QuackBehavior quackBehavior;
	
	public Duck() {}
	
	public abstract void performQuack();
	
	public QuackBehavior getQuackBehavior() {
		return quackBehavior;
	}

	public void setQuackBehavior(QuackBehavior quackBehavior) {
		this.quackBehavior = quackBehavior;
	}
	
}
