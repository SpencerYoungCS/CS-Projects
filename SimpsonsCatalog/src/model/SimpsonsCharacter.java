package model;

public class SimpsonsCharacter {

    String name;
    Integer numOfPictures;
    Integer id;
    String noSpaceName;

    public SimpsonsCharacter(Integer id,String name, Integer numOfPictures, String noSpaceName)
    {
    	this.id = id;
        this.name = name;
        this.numOfPictures = numOfPictures;
        this.noSpaceName = noSpaceName;
    }
    public String getNoSpaceName() {
    	return noSpaceName;
    }
    
    public void setNoSpaceName(String noSpaceName) {
        this.noSpaceName = noSpaceName;
    }
    
    public Integer getId() {
    	return id;
    }
    
    public void setId(Integer id) {
    	this.id = id;
    }

    public String getName()
    {
        return name;
    }

    public void setName( String name )
    {
        this.name = name;
    }

    public Integer getNumOfPictures()
    {
        return numOfPictures;
    }

    public void setNumOfPictures( Integer num )
    {
        this.numOfPictures = num;
    }

}
