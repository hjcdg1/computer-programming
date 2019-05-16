class Person {
    public Person(String fn, String ln, int pn)
    {
        setFirstName(fn);
        setLastName(ln);
        setPhoneNumber(pn);
    }


    /* set & get */
    public void setFirstName(String fn)
    {
        firstName = fn;
    }
    public String getFirstName()
    {
        return firstName;
    }

    public void setLastName(String ln)
    {
        lastName = ln;
    }
    public String getLastName()
    {
        return lastName;
    }
    public void setPhoneNumber(int pn)
    {
        phoneNumber = pn;
    }
    public int getPhoneNumber()
    {
        return phoneNumber;
    }


    /* print */
    public void print()
    {
    	int first = getPhoneNumber()/100000000;									//	010으로 시작하면 10,  02로 시작하면 2
    	int second = (getPhoneNumber() - (first)*100000000)/10000;				//	XXXX에 해당하는 정수 (02/010-XXXX-YYYY)
    	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);	//	YYYY에 해당하는 정수 (02/010-XXXX-YYYY)
    	
        System.out.print(getFirstName() + " " + getLastName() + "_");
        System.out.printf("0%d-%04d-%04d\n", first, second, third);				//	%04d : 반드시 4자리로 출력.   ex) 정수 49 -> 0049로 출력
    }


    /* data */
    private String firstName;
    private String lastName;
    private int phoneNumber;
}









