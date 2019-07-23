public interface Subject {
	public void registerClient(Client newClient);
	public void removeClient(Client remove);
	public void notifyClients();
	
}
