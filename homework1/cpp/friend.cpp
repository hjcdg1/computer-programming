#include <iostream>
#include <string>
#include "person.h"		/* Person 클래스의 정의문을 가져옴 */
#include "friend.h"		/* Friend 클래스의 정의문을 가져옴 */
#include <cstdio>

Friend :: Friend(string& fn, string& ln, int& pn, int& a) : Person(fn, ln, pn)	//  Friend 생성자
{
    setAge(a);
}

void Friend :: setAge(int a)
{
    age = a;
}

int Friend :: getAge(void)
{
    return age;
}

void Friend :: print(void)
{
   	int first = getPhoneNumber()/100000000;
   	int second = (getPhoneNumber() - (first)*100000000)/10000;
   	int third = (getPhoneNumber() - (first)*100000000 - (second)*10000);

	cout << getFirstName() << " " << getLastName() << "_";
	printf("0%d-%04d-%04d_", first, second, third);
	cout << getAge() << endl;
}

