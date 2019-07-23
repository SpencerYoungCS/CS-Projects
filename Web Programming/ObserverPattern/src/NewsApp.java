import java.util.*;

public class NewsApp {
	public static void main(String[] args) {
		
		//this is the news grabber
		NewsData newsData = new NewsData();
		
		NewsObserver client1 = new NewsObserver(newsData);
		NewsObserver client2 = new NewsObserver(newsData);
		NewsObserver client3 = new NewsObserver(newsData);
		
		newsData.setLocalNews("local cat gets pet");
		newsData.setWorldNews("csula TA gives student spencer young "
				+ "a perfect score for absolutely no reason");
		
	}
}

