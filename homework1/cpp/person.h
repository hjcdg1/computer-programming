#ifndef PERSON_H		/*  헤더파일 중복 삽입 문제 방지 */
#define PERSON_H

using namespace std;	//	std에 정의된 cout, endl, string을 편하게 쓰기 위해

class Person {
    public:
        Person(string&, string&, int&);
        void setFirstName(string&);
        string getFirstName(void);
        void setLastName(string&);
        string getLastName(void);
        void setPhoneNumber(int&);
        int getPhoneNumber(void);
        virtual void print(void);	//	상위클래스의 포인터가 하위클래스 객체를 가리킬 때, 상위클래스의 print가 하위클래스의 print를 가리지 않도록 한다.

    private:
        string firstName;
        string lastName;
        int phoneNumber;
};

#endif
