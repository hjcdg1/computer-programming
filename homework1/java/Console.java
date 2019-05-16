import java.util.ArrayList;		/* ArrayList 클래스 */
import java.util.Calendar;		/* Calendar 클래스 */
import java.util.Scanner;		/* Scanner 클래스 */

class Console {
	
	/* 현재 시각 관련 static 변수 */
    static Calendar cal = Calendar.getInstance();		//	Calendar getInstance () : Returns a Calendar object
    													//	whose calendar fields are initialized with the current date
    static int current_y = cal.get(Calendar.YEAR);		//	get the current year
    static int current_m = cal.get(Calendar.MONTH)+1;	//	get the current month
    static int current_d = cal.get(Calendar.DATE);		//	get the current date

    public static void main(String[] args)
    {
        ArrayList<Person> phoneBook = new ArrayList<Person>();		//	Person형 자료를 관리하는 ArrayList 선언
        Scanner scan = new Scanner(System.in);						//	키보드 입력을 받기 위한 Scanner 객체 생성

        int input, type, index;
        int tAge;
        int phoneSplit1, phoneSplit2, phoneSplit3, phoneCombin;
        String tName, tFirstName, tLastName, tPhoneNumber, tTeam, tBirthday;
        String[] nameSplit;
        String[] phoneSplit;
        String exit;

        while(true){
            System.out.print("CP-2016-10399>");
            
            exit = scan.nextLine();			//	한 줄 입력 받음
            if(exit.equals("exit")){		//	"exit"이면 프로그램 종료
                scan.close();
            	return;
            }
            
            if(exit.equals("1") || exit.equals("2") || exit.equals("3"))
            	input = Integer.parseInt(exit);
            else{
            	while(true){
		            System.out.println("Phone Book");
		            System.out.println("1. Add person");
		            System.out.println("2. Remove person");
		            System.out.println("3. Print phone book");
		            System.out.print("CP-2016-10399>");
		            
		            exit = scan.nextLine();			//	한 줄 입력 받음
		            if(exit.equals("exit")){		//	"exit"이면 프로그램 종료
		            	scan.close();
		                return;
		            }
		            if(exit.equals("1") || exit.equals("2") || exit.equals("3")){
		            	input = Integer.parseInt(exit);
		            	break;
		            }
		            else
		            	continue;
            	}
            }
            
            switch(input){

                case 1:	/* Add person */
                    System.out.println("Select Type");
                    System.out.println("1. Person");
                    System.out.println("2. Work");
                    System.out.println("3. Family");
                    System.out.println("4. Friend");
                    System.out.print("CP-2106-10399>");

                    type = scan.nextInt();
                    scan.nextLine();	//	nextInt 호출 뒤 버퍼에 남은 개행문자를 제거
                    switch(type){
                    
                        case 1:	/* Person 선택 */
                            System.out.print("Name: ");
                            tName = scan.nextLine(); nameSplit = tName.split(" ");	//	이름, 성까지 한 번에 입력받고, " "를 구분자로 삼아 자르기
                            tFirstName = nameSplit[0]; tLastName = nameSplit[1];	//	이름과 성 분리
                            System.out.print("Phone_number: "); tPhoneNumber = scan.nextLine();		//	전화번호 입력

                            /* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
                            	phoneSplit = tPhoneNumber.split("-");				//	010or02-XXXX-YYYY	// "-"를 구분자로 삼아 문자열 자르기
	                        	phoneSplit1 = Integer.parseInt(phoneSplit[0]);		//	010or02 정수 변환
	                        	phoneSplit2 = Integer.parseInt(phoneSplit[1]); 		//	XXXX 정수 변환
	                        	phoneSplit3 = Integer.parseInt(phoneSplit[2]);		//	YYYY 정수 변환
	                            phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;		//	나눈 정수들을 자릿수에 맞게 다시 합치기
                            
	                        phoneBook.add(new Person(tFirstName, tLastName, phoneCombin));					//	add
                            System.out.println("Successfully added new person.");
                            break;

                        case 2:	/* Work 선택 */
                            System.out.print("Name: ");
                            tName = scan.nextLine(); nameSplit = tName.split(" ");
                            tFirstName = nameSplit[0]; tLastName = nameSplit[1];
                            System.out.print("Phone_number: "); tPhoneNumber = scan.nextLine();
                            
                            /* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
	                        	phoneSplit = tPhoneNumber.split("-");
	                        	phoneSplit1 = Integer.parseInt(phoneSplit[0]);
	                        	phoneSplit2 = Integer.parseInt(phoneSplit[1]);
	                        	phoneSplit3 = Integer.parseInt(phoneSplit[2]);
	                            phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;
                            
                            System.out.print("Team: "); tTeam = scan.nextLine();	//	팀 이름 입력
                            phoneBook.add(new Work(tFirstName, tLastName, phoneCombin, tTeam));
                            System.out.println("Successfully added new person.");
                            break;

                        case 3:	/* Family 선택 */
                            System.out.print("Name: ");
                            tName = scan.nextLine(); nameSplit = tName.split(" ");
                            tFirstName = nameSplit[0]; tLastName = nameSplit[1];
                            System.out.print("Phone_number: "); tPhoneNumber = scan.nextLine();
                            
                            /* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
	                        	phoneSplit = tPhoneNumber.split("-");
	                        	phoneSplit1 = Integer.parseInt(phoneSplit[0]);
	                        	phoneSplit2 = Integer.parseInt(phoneSplit[1]);
	                        	phoneSplit3 = Integer.parseInt(phoneSplit[2]);
	                            phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;
                          
                            System.out.print("Birthday: "); tBirthday = scan.nextLine();	//	생일 입력
                            phoneBook.add(new Family(tFirstName, tLastName, phoneCombin, tBirthday));
                            System.out.println("Successfully added new person.");
                            break;

                        case 4:	/* Friend 선택 */
                            System.out.print("Name: ");
                            tName = scan.nextLine(); nameSplit = tName.split(" ");
                            tFirstName = nameSplit[0]; tLastName = nameSplit[1];
                            System.out.print("Phone_number: "); tPhoneNumber = scan.nextLine();
                            
                            /* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
	                        	phoneSplit = tPhoneNumber.split("-");
	                        	phoneSplit1 = Integer.parseInt(phoneSplit[0]);
	                        	phoneSplit2 = Integer.parseInt(phoneSplit[1]);
	                        	phoneSplit3 = Integer.parseInt(phoneSplit[2]);
	                            phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;
                          
                            System.out.print("Age: "); tAge = scan.nextInt(); scan.nextLine();		//	나이 입력 + 버퍼에 남은 개행문자 제거
                            phoneBook.add(new Friend(tFirstName, tLastName, phoneCombin, tAge));
                            System.out.println("Successfully added new person.");
                            break;             	
                    }
                    break;		//	"CP-2016-10399> "를 띄우는 부분으로 돌아감

                    
                case 2:	/* Remove person */
                    System.out.print("Enter Index of person: "); index = scan.nextInt(); scan.nextLine();		//	제거할 person의 index 입력
                    																							//	그리고 버퍼에 남은 개행문자 제거
                    if(index-1 >= phoneBook.size() || index <= 0)		//	존재하지 않는 person의 index
                        System.out.println("Person does not exist!");
                    else{
                        phoneBook.remove(index-1);		//	index-th 객체 삭제
                        System.out.println("A person is successfully deleted from the Phone Book!");
                    }
                    break;		//	"CP-2016-10399> "를 띄우는 부분으로 돌아감

                    
                case 3:	/* Print phone book */
                    System.out.println("Phone Book Print");
                    for(int i=0; i<phoneBook.size(); i++){
                    	System.out.print((i+1) + ". ");
                        phoneBook.get(i).print();
                    }
                    break;		//	"CP-2016-10399> "를 띄우는 부분으로 돌아감
            }
        }
    }
}
