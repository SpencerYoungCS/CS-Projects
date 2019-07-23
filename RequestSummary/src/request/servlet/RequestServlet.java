package request.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class RequestServlet
 */
@WebServlet("/RequestSummary")
public class RequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public RequestServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String timeStamp = new SimpleDateFormat("MM dd HH:mm:ss yyyy").format(Calendar.getInstance().getTime());
		
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
		out.println("    <title>Request Summary</title>");
		out.println("</head>");
		out.println("<div class=\"container\">");
        out.println("<div class=\"jumbotron\">");
        out.println("<h1>Request Parameters <small>Lab 2</small></h1>");
        out.print("<p>The following " + request.getMethod() + " request was submitted on "+ timeStamp +"</p>");
        out.println("       </div>");
		
		/* Page Body goes here */
		out.println("<body>");
		out.println("<div class=\"container\">");
		
		out.println("<div class=\"page-header\">");
		out.println("   <h3>Header Information</h3>");
		out.println("</div>");
		
		out.println("<table class=\"table table-bordered table-hover table-striped\">");
		out.println("	<tr>");
		out.println("		<th>Header Field</th>");
		out.println("		<th>Header Value</th>");
		out.println("	</tr>");
		
		Enumeration headerNames = request.getHeaderNames();
		while(headerNames.hasMoreElements()) {
		String headerName = (String)headerNames.nextElement();
		out.println("	<tr>");
		out.println("		<td>"+ headerName+ "</td>");
		out.println("		<td>" + request.getHeader(headerName) + "</td>");
		out.println("	</tr>");
		}

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
		
}
		

}
