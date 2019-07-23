

public class NorthWestPizza extends Pizza{
	PizzaIngredientFactory ingredientFactory;

	public NorthWestPizza(PizzaIngredientFactory ingredientFactory) {
		this.ingredientFactory = ingredientFactory;
	}
	
	void prepare() {
		
		System.out.println("Preparing " + name);
		dough = ingredientFactory.createDough();
		System.out.println("Adding Dough: " + dough);
		sauce = ingredientFactory.createSauce();
		System.out.println("Adding Sauce: " + sauce);
		cheese = ingredientFactory.createCheese();
		System.out.println("Adding Cheese: " + cheese);

	}
	void cut() {
		System.out.println("Cutting into squares");
	}
}
