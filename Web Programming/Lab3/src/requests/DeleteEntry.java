package requests;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import models.GuestBookEntry;
/**
 * Servlet implementation class DeleteEntry
 */

@WebServlet("/requests/DeleteEntry")
public class DeleteEntry extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
  
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		// Get the element to be deleted
		int id = Integer.parseInt( request.getParameter("id"));
		
		// Get a reference to the entries array list
		ArrayList<GuestBookEntry> entries
			= (ArrayList<GuestBookEntry>) getServletContext().getAttribute("entries");
		
		// Let's remove the element
		for (GuestBookEntry entry : entries) {
			if (entry.getId() == id) {
				entries.remove(entry);
				break;				
			}
		}
		
		// Send the browser back to the main page
		response.sendRedirect("GuestBook");
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
