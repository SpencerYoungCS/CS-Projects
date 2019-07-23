package requests;


import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import models.GuestBookEntry;


@WebServlet("/requests/GuestBook")
public class GuestBook extends HttpServlet {
	private static final long serialVersionUID = 1L;
 
	public void init(ServletConfig config) throws ServletException {
		super.init(config);
		
		ArrayList<GuestBookEntry> entries = new ArrayList<GuestBookEntry>();
		entries.add(new GuestBookEntry("John", "Science"));
		entries.add(new GuestBookEntry("Mary", "Math!"));
		entries.add(new GuestBookEntry("Joe", "English"));
		
		ServletContext context = this.getServletContext();
		context.setAttribute("entries", entries);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		// Set the content type
		response.setContentType("text/html");
		
		// Get a reference to the PrintWriter that lets us talk to the client
		PrintWriter out = response.getWriter();
		
		// Generate the HTML
		out.println("<!DOCTYPE html>");
		out.println("<html lang=\"en\">");
		out.println("<head>");
		out.println("    <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\">");
		out.println("    <meta charset=\"UTF-8\">");
		
		/* Page Title goes here */
		out.println("    <title>Guest Book</title>");
		out.println("</head>");
		
		/* Page Body goes here */
		out.println("<body>");
		out.println("<div class=\"container\">");
		
		out.println("<div class=\"page-header\">");
		out.println("    <h1>Guest Book<small>HttpServletRequest</small></h1>");
		out.println("</div>");
		
		
		out.println("<form class=\"form-inline\" action=\"GuestBook\" method=\"get\">");
		out.println("	<div class=\"form-group\">");
		out.println("		<input class=\"form-control\" type=\"text\" name=\"query\" placeholder=\"Enter your search term(s)\">");
		out.println("		<input class=\"form-control btn btn-primary\" type=\"submit\" value=\"Search\">");
		out.println("	</div>");
		out.println("</form>");
		
		out.println("<hr>");

		
		out.println("<table class=\"table table-bordered table-striped table-hover\">");
		out.println("<tr>");
		out.println("  <th>Name</th><th>Message</th><th>Date</th><th>Actions</th>");
		out.println("</tr>");
		
	
		ArrayList<GuestBookEntry> entries 
			= (ArrayList<GuestBookEntry>) getServletContext().getAttribute("entries");

		
		for (GuestBookEntry entry : entries) {
			
			
				out.println("<tr>");
				out.println("  <td>" + entry.getName() + "</td>");
				out.println("  <td>" + entry.getMessage() + "</td>");
				out.println("  <td>" + entry.getCreated() + "</td>");
				
				// Implement the actions
				out.println("  <td>");
				out.println("		<a href=\"EditEntry?id=" + entry.getId() + "\">Edit</a>");
				out.println("		<a href=\"DeleteEntry?id=" + entry.getId() + "\">Delete</a>");
				out.println("  </td>");
				out.println("</tr>");
			
		}
		

		
		out.println("</table>");
		
		out.println("<a class=\"btn btn-primary\" href=\"AddEntry\">Add a New Entry</a>");
		
//		try {
//			String query = request.getParameter("query") );
//			out.println("<p class=\"lead\">");
//			out.println(query);
//			out.println("</p>");
//		}
//		catch(Exception e) {
//			response.sendRedirect("GuestBook");
//			return;			
//			out.println("<p class=\"lead text-danger\">Invalid inputs! You must enter whole numbers</p>");
//		}

		out.println("</div>");
		out.println("</body>");
		
		out.println("</html>");
		
		
		

	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
