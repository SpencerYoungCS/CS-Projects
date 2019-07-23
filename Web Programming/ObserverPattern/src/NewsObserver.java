public class NewsObserver implements Client{
	
	private String localNews;
	private String worldNews;
	
	private static int observerIDTracker = 0;
	
	private int observerID;
	
	private Subject newsData;
	
	public NewsObserver(Subject newsData) {
		this.newsData = newsData;
		this.observerID = ++observerIDTracker;
		System.out.println("New Client: " + this.observerID);
		newsData.registerClient(this);
	}

	@Override
	public void update(String localNews, String worldNews) {
		this.localNews =  localNews;
		this.worldNews = worldNews;
		
			Display();
	}
	
	public void Display() {
		//System.out.println("Client: " + newsData);
		System.out.println("Client #" + observerID + ":");
		System.out.println("Local News: " + localNews);
		System.out.println("World News: " + worldNews);
	}

}
