#include <iostream>
#include <string>
#include <cstdlib>		/* atoi 함수 */
#include <cstdio>		/* printf, getchar 함수 */
#include "person.h"		/* Person 클래스의 정의문을 가져옴 */
#include "family.h"		/* Family 클래스의 정의문을 가져옴 */

extern void getdate(int*, int*, int*);	//	getdate의 정의문이 다른 소스 코드에 있음

Family :: Family(string& fn, string& ln, int& pn, string& b) : Person(fn, ln, pn)	//  Family 생성자
{
    setBirthday(b);
}

void Family :: setBirthday(string& b)   //  YYMMDD
{
    birthday = b;
}

string Family :: getBirthday(void)
{
    return birthday;
}

int Family :: dDay(void)		/* 생일까지 남은 날짜 계산 */
{
    int tempy, tempm, tempd;
	int birthday_m, birthday_d;
	int dDay = 0;

    getdate(&tempy, &tempm, &tempd);			//	tempy: 현재 YEAR,  tempm : 현재 MONTH,  tempd : 현재 DAY
    birthday_month = birthday.substr(2,2);		//	YYMMDD에서 MM을 분리
    birthday_day = birthday.substr(4,2);		//	YYMMDD에서 DD를 분리
    birthday_m = atoi(birthday_month.c_str());	//	MM을 Integer로 변환
    birthday_d = atoi(birthday_day.c_str());	//	DD를 Integer로 변환

	/* 오늘이 생일인 경우 */
	if(birthday_m == tempm && birthday_d == tempd)	return 0;
	
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
    else if( birthday_m == tempm  &&  birthday_d > tempd){
        dDay = (birthday_d-tempd);
        return dDay;
    }

	/* 올해 생일이 지났을 때 */
    else{
		while(true){						//	해(年)가 바뀌고 생일이 있는 달(月)에 도달할 때까지 tempm을 1씩 증가시키는 루프
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

void Family :: print(void)
{
   	int first = getPhoneNumber()/100000000;
   	int second = (getPhoneNumber() - (first)*100000000)/10000;
   	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);

	cout << getFirstName() << " " << getLastName() << "_";
	printf("0%d-%04d-%04d_", first, second, third);
	cout << getBirthday() << "_" << dDay() << endl;
}

