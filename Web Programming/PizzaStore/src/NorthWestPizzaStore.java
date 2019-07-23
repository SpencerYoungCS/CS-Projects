public class NorthWestPizzaStore extends PizzaStore{
	@Override
	protected Pizza createPizza(String item) {
		Pizza pizza = null;
		PizzaIngredientFactory ingredientFactory =
				new NorthWestIngredientFactory();
		pizza = new NorthWestPizza(ingredientFactory);
		
		pizza.setName("NorthWest Style Pizza");

		return pizza;
	}

}
