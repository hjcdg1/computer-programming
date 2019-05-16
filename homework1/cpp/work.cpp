#include <iostream>
#include <string>
#include "person.h"		/* Person 클래스의 정의문을 가져옴 */
#include "work.h"		/* Work 클래스의 정의문을 가져옴 */
#include <cstdio>

Work :: Work(string& fn, string& ln, int& pn, string& t) : Person(fn, ln, pn)	//  Work 생성자
{
    setTeam(t);
}

void Work :: setTeam(string& t)
{
    team = t;
}

string Work :: getTeam(void)
{
    return team;
}

void Work :: print(void)
{
	int first = getPhoneNumber()/100000000;
   	int second = (getPhoneNumber() - (first)*100000000)/10000;
   	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);

	cout << getFirstName() << " " << getLastName() << "_";
	printf("0%d-%04d-%04d_", first, second, third);
	cout << getTeam() << endl;
}
