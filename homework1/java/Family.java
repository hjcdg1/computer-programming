class Family extends Person {
    public Family(String fn, String ln, int pn, String b)
    {
        super(fn, ln, pn);
        setBirthday(b);
    }


    /* set & get */
    public void setBirthday(String b)   //  YYMMDD
    {
        birthday = b;
    }
    public String getBirthday()
    {
        return birthday;
    }


    /* 생일까지 남은 날짜 계산 */
    public int dDay()
    {
        int dDay = 0;
        int birthday_m, birthday_d, tempm, tempd;
        birthday_month = birthday.substring(2,4);			//	YYMMDD에서 MM을 분리
        birthday_day = birthday.substring(4,6);				//	YYMMDD에서 DD를 분리
        birthday_m = Integer.parseInt(birthday_month);		//	MM을 Integer로 변환
        birthday_d = Integer.parseInt(birthday_day);		//	DD를 Integer로 변환


        tempm = Console.current_m;		//  현재 MONTH
        tempd = Console.current_d;     	//  현재 DAY

        
        /* 올해 생일이 아직 지나지 않았을 때 (그 중 이번 달이 생일이 아닌 경우) */
        if(birthday_m > tempm){
            while(birthday_m > tempm){		//	생일이 있는 달(月)에 도달할 때까지 tempm을 1씩 증가시키는 루프
                switch(tempm){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        dDay += 31-tempd;
                        tempd = 0;
                        break;

                    case 2:
                        dDay += 28-tempd;
                        tempd = 0;
                        break;

                    case 4: case 6: case 9: case 11:
                        dDay += 30-tempd;
                        tempd = 0;
                        break;
                }
                tempm++;
            }
            dDay += birthday_d;				//	생일이 있는 달(月)에 도달
            return dDay;
        }

        /* 올해 생일이 아직 지나지 않았을 때 (그 중 이번 달이 생일인 경우) */
        else if(birthday_m == tempm  &&  birthday_d > tempd){
            dDay = (birthday_d-tempd);
            return dDay;
        }

        /* 올해 생일이 지났을 때 */
        else{
            while(true){					//	해(年)가 바뀌고 생일이 있는 달(月)에 도달할 때까지 tempm을 1씩 증가시키는 루프
                switch(tempm){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        dDay += 31-tempd;
                        tempd = 0;
                        break;
                    case 2:
                        dDay += 28-tempd;
                        tempd = 0;
                        break;
                    case 4: case 6: case 9: case 11:
                        dDay += 30-tempd;
                        tempd = 0;
                        break;
                    case 13:
                    	tempm = 0;
                        break;
                }
                tempm++;
                if(tempm == birthday_m){	//	해(年)가 바뀌고 생일이 있는 달(月)에 도달
                    dDay += birthday_d;
                    break;
                }
            }
            return dDay;
        }
    }


	/* print */
    public void print()
    {
    	int first = getPhoneNumber()/100000000;
    	int second = (getPhoneNumber() - (first)*100000000)/10000;
    	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);
    	
        System.out.print(getFirstName() + " " + getLastName() + "_");
        System.out.printf("0%d-%04d-%04d_", first, second, third);
        System.out.println(getBirthday() + "_" + dDay());
    }


    /* data */
    private String birthday;
    private String birthday_month;
    private String birthday_day;
}
