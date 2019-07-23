package requests;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/requests/SimpleAdderServlet")
public class SimpleAdderServlet extends HttpServlet {
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
		out.println("    <title>Simple Adder Servlet</title>");
		out.println("</head>");
		
		/* Page Body goes here */
		out.println("<body>");
		out.println("<div class=\"container\">");
		
		out.println("<div class=\"page-header\">");
		out.println("    <h1>Simple Adder Servlet <small>HttpServletRequest</small></h1>");
		out.println("</div>");
		
		try {
			int num1 = Integer.parseInt( request.getParameter("num1") );
			int num2 = Integer.parseInt( request.getParameter("num2") );
			out.println("<p class=\"lead\">");
			out.println("The sum of " + num1 + " and " + num2 + " = " + (num1 + num2));
			out.println("</p>");
		}
		catch(Exception e) {
			response.sendRedirect("SimpleAdder.html");
			return;			
			//out.println("<p class=\"lead text-danger\">Invalid inputs! You must enter whole numbers</p>");
		}
		
		
		
		out.println("</div>");
		out.println("</body>");
		
		out.println("</html>");
		

	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
