import java.util.ArrayList;

public class NewsData implements Subject {
	
	private ArrayList<Client> clients;
	private String localNews;
	private String worldNews;
	
	public NewsData() {
		clients = new ArrayList<Client>();
	}
	
	public void registerClient(Client newClient) {
		clients.add(newClient);
	}
	
	public void removeClient(Client remove) {
		int i = clients.indexOf(remove);
		if (i >= 0) {
			clients.remove(i);
		}
	}
	
	public int numberOfClients() {
		return clients.size();
	}
	
	public void notifyClients() {
		for (Client client : clients) {
			client.update(localNews,worldNews);
		}
	}
	
	public void newsChanged() {
		notifyClients();
	}
	
	public void setLocalNews(String news) {
		this.localNews = news;
		newsChanged();
	}

	public void setWorldNews(String news) {
		this.worldNews = news;
		newsChanged();
	}

	public String getLocalNews() {
		return localNews;
	}


}
