class Friend extends Person {
    public Friend(String fn, String ln, int pn, int a)
    {
        super(fn, ln, pn);
        setAge(a);
    }


    /* set & get */
    public void setAge(int a)
    {
        age = a;
    }
    public int getAge()
    {
        return age;
    }


    /* print */
    public void print()
    {
    	int first = getPhoneNumber()/100000000;
    	int second = (getPhoneNumber() - (first)*100000000)/10000;
    	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);
    	
        System.out.print(getFirstName() + " " + getLastName() + "_");
        System.out.printf("0%d-%04d-%04d_", first, second, third);
        System.out.println(getAge());
    }


    /* data */
    private int age;
}
