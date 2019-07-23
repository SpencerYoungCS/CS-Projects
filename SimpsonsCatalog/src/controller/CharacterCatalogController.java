package controller;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.SimpsonsCharacter;

@WebServlet("/CharacterCatalog")
public class CharacterCatalogController extends HttpServlet {

    private static final long serialVersionUID = 1L;

    public CharacterCatalogController()
    {
        super();
    }

    public void init( ServletConfig config ) throws ServletException
    {
        super.init( config );

        // create some test data for display
        List<SimpsonsCharacter> entries = new ArrayList<SimpsonsCharacter>();
        entries.add(new SimpsonsCharacter(0,"Homer Simpson",2246, "homer_simpson"));
        entries.add(new SimpsonsCharacter(1,"Ned Flanders",1454, "ned_flanders"));
        entries.add(new SimpsonsCharacter(2,"Moe Szyslak",1452, "moe_szyslak"));
        entries.add(new SimpsonsCharacter(3,"Lisa Simpson",1354, "lisa_simpson"));
        entries.add(new SimpsonsCharacter(4,"Bart Simpson",1342, "bart_simpson"));
        entries.add(new SimpsonsCharacter(5,"Marge Simpson",1291, "marge_simpson"));
        entries.add(new SimpsonsCharacter(6,"Krusty The Clown",1206, "krusty_the_clown") );
        entries.add(new SimpsonsCharacter(7,"Principal Skinner",1194, "principal_skinner") );
        entries.add(new SimpsonsCharacter(8,"Charles Montgomery Burns",1193, "charles_montgomery_burns") );
        entries.add(new SimpsonsCharacter(9,"Milhouse Van Houten",1079, "milhouse_van_houten") );
        entries.add(new SimpsonsCharacter(10,"Chief Wiggum",986, "chief_wiggum") );
        entries.add(new SimpsonsCharacter(11,"Abraham Grampa Simpson",913, "abraham_grampa_simpson") );
        entries.add(new SimpsonsCharacter(12,"Sideshow Bob",877, "sideshow_bob") );
        entries.add(new SimpsonsCharacter(13,"Apu Nahasapeemapetilon",623, "apu_nahasapeemapetilon") );
        entries.add(new SimpsonsCharacter(14,"Kent Brockman",498, "kent_brockman") );
        entries.add(new SimpsonsCharacter(15,"Comic Book Guy",469, "comic_book_guy") );
        entries.add(new SimpsonsCharacter(16,"Edna Krabappel",457, "edna_krabappel") );
        entries.add(new SimpsonsCharacter(17,"Nelson Muntz",358, "nelson_muntz") );
        entries.add(new SimpsonsCharacter(18,"Lenny Leonard",310, "lenny_leonard") );
        entries.add(new SimpsonsCharacter(19,"Mayor Quimby",246, "mayor_quimby") );
        entries.add(new SimpsonsCharacter(20,"Waylon Smithers",181,"waylon_smithers") );
        entries.add(new SimpsonsCharacter(21,"Maggie Simpson",128, "maggie_simpson") );
        entries.add(new SimpsonsCharacter(22,"Groundskeeper Willie",121, "groundskeeper_willie") );
        entries.add(new SimpsonsCharacter(23,"Barney Gumble",106, "barney_gumble") );
        entries.add(new SimpsonsCharacter(24,"Selma Bouvier",103, "selma_bouvier") );
        entries.add(new SimpsonsCharacter(25,"Carl Carlson",98, "carl_carlson") );
        entries.add(new SimpsonsCharacter(26,"Ralph Wiggum",89,"ralph_wiggum") );
        entries.add(new SimpsonsCharacter(27,"Patty Bouvier",72,"patty_bouvier") );
        entries.add(new SimpsonsCharacter(28,"Martin Prince",71, "martin_prince") );
        entries.add(new SimpsonsCharacter(29,"Professor John Frink",65, "professor_john_frink") );
        entries.add(new SimpsonsCharacter(30,"Snake Jailbird",55, "snake_jailbird") );
        entries.add(new SimpsonsCharacter(31,"Cletus Spuckler",47,"cletus_spuckler") );
        entries.add(new SimpsonsCharacter(32,"Rainier Wolfcastle",45, "rainier_wolfcastle") );
        entries.add(new SimpsonsCharacter(33,"Agnes Skinner",42, "agnes_skinner") );
        entries.add(new SimpsonsCharacter(34,"Sideshow Mel",40, "sideshow_mel") );
        entries.add(new SimpsonsCharacter(35,"Otto Mann",32, "otto_mann") );
        entries.add(new SimpsonsCharacter(36,"Fat Tony",27, "fat_tony") );
        entries.add(new SimpsonsCharacter(37,"Gil",27, "gil") );
        entries.add(new SimpsonsCharacter(38,"Miss Hoover",17, "miss_hoover") );
        entries.add(new SimpsonsCharacter(39,"Disco Stu",8, "disco_stu") );
        entries.add(new SimpsonsCharacter(40,"Troy Mcclure",8, "troy_mcclure") );
        entries.add(new SimpsonsCharacter(41,"Lionel Hutz",3,"lionel_hutz") );
        entries.add(new SimpsonsCharacter(42,"Jimbo Jones",0,"jimbo_jones") );
        entries.add(new SimpsonsCharacter(43,"Bumblebee Man",0,"bumblebee_man") );
        entries.add(new SimpsonsCharacter(44,"Hans Moleman",0,"hans_moleman") );
        entries.add(new SimpsonsCharacter(45,"Helen Lovejoy",0, "helen_lovejoy") );
        entries.add(new SimpsonsCharacter(46,"Jasper Beardly",0, "jasper_beardly") );
        

        // stored the data somewhere that can be accessed by this servlet
        // and other servlets.
        getServletContext().setAttribute( "entries", entries );
    }

    protected void doGet( HttpServletRequest request,
        HttpServletResponse response ) throws ServletException, IOException
    {
    	
    	
        request.getRequestDispatcher( "/WEB-INF/CharacterCatalog.jsp" ).forward(
            request, response );
    }

    protected void doPost( HttpServletRequest request,
        HttpServletResponse response ) throws ServletException, IOException
    {
        doGet( request, response );
    }

}
