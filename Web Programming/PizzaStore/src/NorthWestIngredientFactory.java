public class NorthWestIngredientFactory implements PizzaIngredientFactory {

	@Override
	public Dough createDough() {
		return new ThinCrustDough();
	}

	@Override
	public Sauce createSauce() {
		return new HawaiianStyleAlfredo();
	}

	@Override
	public Cheese createCheese() {
		return new Gouda();
	}

	@Override
	public Veggies[] createVeggies() {
		return null;
	}

	@Override
	public Pepperoni createPepperoni() {
		return null;
	}
	
	@Override
	public Seafood createSeafood() {
		return new MahiMahi();
	}

}
