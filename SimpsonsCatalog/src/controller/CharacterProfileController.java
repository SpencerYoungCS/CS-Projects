package controller;

import java.io.IOException;
import java.text.DecimalFormat;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Random;


import model.SimpsonsCharacter;

@WebServlet("/CharacterProfile")
public class CharacterProfileController extends HttpServlet {

    private static final long serialVersionUID = 1L;

    public CharacterProfileController()
    {
        super();
    }

    /**
     * Given an id, retrieve the SimpsonsCharacter.
     */
    @SuppressWarnings("unchecked")
    private SimpsonsCharacter getEntry( Integer id )
    {
        List<SimpsonsCharacter> entries = (List<SimpsonsCharacter>) getServletContext().getAttribute(
            "entries" );

        for( SimpsonsCharacter entry : entries )
            if( entry.getId().equals( id ) ) return entry;

        return null;
    }

    protected void doGet( HttpServletRequest request,
        HttpServletResponse response ) throws ServletException, IOException
    {
        // get the entry to be edited
        Integer id = Integer.valueOf( request.getParameter( "id" ) );
        SimpsonsCharacter entry = getEntry( id );
        Random rand = new Random();
        Integer randomNum = rand.nextInt(entry.getNumOfPictures())+0;
//        String randomNumString = randomNum.toString();

        DecimalFormat decimalFormat = new DecimalFormat("0000");
        String randomNum2 = decimalFormat.format(randomNum);

        // pass the entry to jsp using request scope
        request.setAttribute( "entry", entry );
        request.setAttribute("randomNum2", randomNum2);
        request.getRequestDispatcher( "/WEB-INF/CharacterProfile.jsp" ).forward(
            request, response );
    }

    protected void doPost( HttpServletRequest request,
        HttpServletResponse response ) throws ServletException, IOException
    {
        // get the entry to be edited
        Integer id = Integer.valueOf( request.getParameter( "id" ) );
        SimpsonsCharacter entry = getEntry( id );

        // change the entry based on user input
        entry.setName( request.getParameter( "name" ) );
        entry.setNumOfPictures(Integer.parseInt(request.getParameter( "numOfPictures" ) ));

//         send the user back to the guest book page
        response.sendRedirect( "CharacterCatalog" );
    }

}
