#include <iostream>
#include <string>
#include "person.h"		/* Person 클래스의 정의문을 가져옴 */
#include <cstdio>

Person :: Person(string& fn, string& ln, int& pn)	//  Person 생성자
{
    setFirstName(fn);
    setLastName(ln);
    setPhoneNumber(pn);
}

void Person :: setFirstName(string& fn)
{
    firstName = fn;
}

string Person :: getFirstName(void)
{
    return firstName;
}

void Person :: setLastName(string& ln)
{
    lastName = ln;
}

string Person :: getLastName(void)
{
    return lastName;
}

void Person :: setPhoneNumber(int& pn)
{
    phoneNumber = pn;
}

int Person :: getPhoneNumber(void)
{
    return phoneNumber;
}

void Person :: print(void)
{
   	int first = getPhoneNumber()/100000000;									//	010으로 시작하면 10,  02로 시작하면 2
   	int second = (getPhoneNumber() - (first)*100000000)/10000;				//	XXXX에 해당하는 정수 (02/010-XXXX-YYYY)
   	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);	//	YYYY에 해당하는 정수 (02/010-XXXX-YYYY)
	
	cout << getFirstName() << " " << getLastName() << "_";
	printf("0%d-%04d-%04d\n", first, second, third);						//	%04d : 반드시 4자리로 출력.   ex) 정수 49 -> 0049로 출력
}

