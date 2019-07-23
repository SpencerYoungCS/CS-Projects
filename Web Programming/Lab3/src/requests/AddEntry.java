package requests;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import models.GuestBookEntry;

/**
 * Servlet implementation class AddEntry
 */
@WebServlet("/requests/AddEntry")
public class AddEntry extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
 
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
		out.println("    <title>Add Tutor</title>");
		out.println("</head>");
		
		/* Page Body goes here */
		out.println("<body>");
		out.println("<div class=\"container\">");
		
		out.println("<div class=\"page-header\">");
		out.println("    <h1>Add Entry <small>CSULA Tutor Directory</small></h1>");
		out.println("</div>");
		
		out.println("<form action=\"Add Tutor\" method=\"post\">");
		out.println("Name: <input type=\"text\" name=\"name\"><br>");
//		out.println("Message:");
		out.println("Email: <input type=\"text\" email=\"email\"><br>");
		out.println("Courses: <input type=\"text\" courses=\"courses\"><br>");
//		out.println("<textarea name=\"message\" rows=\"5\" cols=\"20\"></textarea><br>");
		out.println("<input type=\"submit\" name=\"addEntry\" value=\"Add Entry\">");
		out.println("</form>");
		
		out.println("</div>");
		out.println("</body>");
		
		out.println("</html>");
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String name = request.getParameter("name");
		String message = request.getParameter("message");
		
		// Validate the input
		if (name != null && name.trim().length() > 0 
				&& message != null && message.trim().length() > 0) {
			
			// Create a new entry
			GuestBookEntry entry = new GuestBookEntry(name, message);
			
			ArrayList<GuestBookEntry> entries 
				= (ArrayList<GuestBookEntry>) getServletContext().getAttribute("entries");
			
			// Add the new entry to our array list of entries
			entries.add(entry);
			
			response.sendRedirect("GuestBook");
			return;
		}
		
				
		doGet(request, response);
	}

}
