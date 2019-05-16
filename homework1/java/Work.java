class Work extends Person {
    public Work(String fn, String ln, int pn, String t)
    {
        super(fn, ln, pn);
        setTeam(t);
    }


    /* set & get */
    public void setTeam(String t)
    {
        team = t;
    }
    public String getTeam()
    {
        return team;
    }


    /* print */
    public void print()
    {
    	int first = getPhoneNumber()/100000000;
    	int second = (getPhoneNumber() - (first)*100000000)/10000;
    	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);
       	
        System.out.print(getFirstName() + " " + getLastName() + "_");
        System.out.printf("0%d-%04d-%04d_", first, second, third);
        System.out.println(getTeam());
    }


    /* data */
    private String team;
}
