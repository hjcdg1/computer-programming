#ifndef FAMILY_H		/*  헤더파일 중복 삽입 문제 방지 */
#define FAMILY_H

using namespace std;	//	std에 정의된 cout, endl, string을 편하게 쓰기 위해

class Family : public Person {
    public:
        Family(string&, string&, int&, string&);
        void setBirthday(string&);
        string getBirthday(void);
        int dDay(void);
        void print(void);

    private:
        string birthday;
        string birthday_month;	// 입력받은 YYMMDD 문자열에서 MM 부분
        string birthday_day;	// 입력받은 YYMMDD 문자열에서 DD 부분
};

#endif
