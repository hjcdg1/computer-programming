#ifndef FRIEND_H		/*  헤더파일 중복 삽입 문제 방지 */
#define FRIEND_H

using namespace std;	//	std에 정의된 cout, endl, string을 편하게 쓰기 위해

class Friend : public Person {
    public:
        Friend(string&, string&, int&, int&);
        void setAge(int);
        int getAge(void);
        void print(void);

    private:
        int age;
};

#endif
