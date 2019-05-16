#ifndef WORK_H			/*  헤더파일 중복 삽입 문제 방지 */
#define WORK_H

using namespace std;	//	std에 정의된 cout, endl, string을 편하게 쓰기 위해

class Work : public Person {
    public:
        Work(string&, string&, int&, string&);
        void setTeam(string&);
        string getTeam(void);
        void print(void);

    private:
        string team;
};

#endif
