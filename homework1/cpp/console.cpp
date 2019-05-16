#include <iostream>		/* cin, cout, endl */
#include <vector>		/* vector 클래스 */
#include <ctime>		/* time_t, tm 구조체와 time, localtime 함수 */
#include <string>		/* string 클래스 */
#include <cstdlib>		/* atoi 함수 */
#include <cstdio>		/* getchar 함수 */

/* Person, Work, Family, Friend 클래스를 사용하기 위해 그 클래스의 정의문들을 가져옴 */
#include "person.h"
#include "work.h"
#include "family.h"
#include "friend.h"	

#pragma warning (disable: 4996)
using namespace std;	//	std에 정의된 cin, cout, endl, string을 편하게 쓰기 위해

int main(void)
{
        vector<Person*> phoneBook;		//	Person*형 자료를 관리하는 vector 선언

        int input, type, index, phonebook_size;
        int i, j=0; 
		int tAge;
        int phoneSplit1, phoneSplit2, phoneSplit3, phoneCombin;
        string tFirstName, tLastName, tPhoneNumber, tTeam, tBirthday;
        char enter;

        while(true){

            cout << "CP-2016-10399>";

			/* Enter와 "exit" 식별 */
            while(true){
                enter = getchar();
                if(enter == '\n' || enter == '1' || enter == '2' || enter == '3')	//	Enter or 1~3을 입력하면 while문 탈출
                    break;
                if(enter == 'e' && j == 0)			j++;			//	처음에 e가 입력되면 j → 1
                else if(enter == 'x' && j == 1)		j++;			//	e 다음에 x가 입력되면 j → 2
                else if(enter == 'i' && j == 2)		j++;			//	ex 다음에 i가 입력되면 j → 3
                else if(enter == 't' && j == 3)		return 0;		//	exi 다음에 t가 입력되면 프로그램 종료
				else{												//	exit가 아닌 단어의 경우, Enter만 입력한 경우와 같게 처리
					while(getchar() != '\n');						//	뒤에 나오는 "cin >> input;"에서 입력버퍼에 남은 문자를 읽으면 안되므로
																	//	그 전에 입력버퍼를 완전히 비워준다.
					break;
				}
            }

			if(enter == '1' || enter == '2' || enter == '3')	//	1~3중 하나를 입력했다면, 바로 그 메뉴로 들어간다.
				input = enter-48;
			else{												//	Enter나 다른 단어를 입력했다면, 메뉴 선택 창을 띄운다.
				while(true){
					cout << "Phone Book" << endl;
					cout << "1. Add person" << endl;
					cout << "2. Remove person" << endl;
					cout << "3. Print phone book" << endl;
					cout << "CP-2016-10399>";

					while(true){
						enter = getchar();
						if(enter == '\n' || enter == '1' || enter == '2' || enter == '3')	//	Enter or 1~3을 입력하면 while문 탈출
							break;
						if(enter == 'e' && j == 0)			j++;			//	처음에 e가 입력되면 j → 1
						else if(enter == 'x' && j == 1)		j++;			//	e 다음에 x가 입력되면 j → 2
						else if(enter == 'i' && j == 2)		j++;			//	ex 다음에 i가 입력되면 j → 3
						else if(enter == 't' && j == 3)		return 0;		//	exi 다음에 t가 입력되면 프로그램 종료
						else{												//	exit가 아닌 단어의 경우, Enter만 입력한 경우와 같게 처리
							while(getchar() != '\n');						//	뒤에 나오는 "cin >> input;"에서 입력버퍼에 남은 문자를 읽으면 안되므로
																			//	그 전에 입력버퍼를 완전히 비워준다.
							break;
						}
					}
					if(enter == '1' || enter == '2' || enter == '3'){
						input = enter-48;
						break;
					}
					else
						continue;
				}
			}

            switch(input){

                case 1:	/* Add person */
                    cout << "Select Type" << endl;
                    cout << "1. Person" << endl;
                    cout << "2. Work" << endl;
                    cout << "3. Family" << endl;
                    cout << "4. Friend" << endl;
                    cout << "CP-2106-10399>";

                    cin >> type;
                    switch(type){
                        case 1:	/* Person 선택 */
                            cout << "Name: "; cin >> tFirstName >> tLastName;		//	이름, 성 입력
                            cout << "Phone_number: "; cin >> tPhoneNumber;			//	전화번호 입력
							getchar();	//	버퍼에 남은 개행문자 제거
								
								/* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
								if(tPhoneNumber.substr(0, 2) == "01"){						// 010-XXXX-YYYY
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 3).c_str());	// 010 정수 변환		//	c_str() : string 형을 char* 형으로 변환
									phoneSplit2= atoi(tPhoneNumber.substr(4, 4).c_str());	// XXXX 정수 변환
									phoneSplit3 = atoi(tPhoneNumber.substr(9, 4).c_str());	// YYYY 정수 변환
								}
								else if(tPhoneNumber.substr(0, 2) == "02"){					// 02-XXXX-YYYY
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 2).c_str());	// 02 정수 변환
									phoneSplit2= atoi(tPhoneNumber.substr(3, 4).c_str());	// XXXX 정수 변환
									phoneSplit3 = atoi(tPhoneNumber.substr(8, 4).c_str());	// YYYY 정수 변환
								}
								phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;		//	나눈 정수들을 자릿수에 맞게 다시 합치기
                           
							phoneBook.push_back(new Person(tFirstName, tLastName, phoneCombin));			//	push_back
                            cout << "Successfully added new person." << endl;
                            break;

                        case 2:	/* Work 선택 */
                            cout << "Name: "; cin >> tFirstName >> tLastName; 
                            cout << "Phone_number: "; cin >> tPhoneNumber;
								/* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
								if(tPhoneNumber.substr(0, 2) == "01"){
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 3).c_str());
									phoneSplit2= atoi(tPhoneNumber.substr(4, 4).c_str());
									phoneSplit3 = atoi(tPhoneNumber.substr(9, 4).c_str());
								}
								else if(tPhoneNumber.substr(0, 2) == "02"){
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 2).c_str());
									phoneSplit2= atoi(tPhoneNumber.substr(3, 4).c_str());
									phoneSplit3 = atoi(tPhoneNumber.substr(8, 4).c_str());
								}
								phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;

                            cout << "Team: "; getchar(); getline(cin, tTeam);		//	버퍼에 남은 개행문자 제거 후, 팀 이름 입력
                            phoneBook.push_back(new Work(tFirstName, tLastName, phoneCombin, tTeam));
                            cout << "Successfully added new person." << endl;
                            break;

                        case 3:	/* Family 선택 */
                            cout << "Name: "; cin >> tFirstName >> tLastName;
                            cout << "Phone_number: "; cin >> tPhoneNumber;
								
								/* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
								if(tPhoneNumber.substr(0, 2) == "01"){
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 3).c_str());
									phoneSplit2= atoi(tPhoneNumber.substr(4, 4).c_str());
									phoneSplit3 = atoi(tPhoneNumber.substr(9, 4).c_str());
								}
								else if(tPhoneNumber.substr(0, 2) == "02"){
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 2).c_str());
									phoneSplit2= atoi(tPhoneNumber.substr(3, 4).c_str());
									phoneSplit3 = atoi(tPhoneNumber.substr(8, 4).c_str());
								}
								phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;		

                            cout << "Birthday: "; cin >> tBirthday; getchar();		//	생일 입력 후, 버퍼에 남은 개행문자 제거
                            phoneBook.push_back(new Family(tFirstName, tLastName, phoneCombin, tBirthday));
                            cout << "Successfully added new person." << endl;
                            break;

                        case 4:	/* Friend 선택 */
                            cout << "Name: "; cin >> tFirstName >> tLastName;
                            cout << "Phone_number: "; cin >> tPhoneNumber;

								/* 문자열 자르기 + 정수로 변환 + 다시 합치기 */
								if(tPhoneNumber.substr(0, 2) == "01"){
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 3).c_str());
									phoneSplit2= atoi(tPhoneNumber.substr(4, 4).c_str());
									phoneSplit3 = atoi(tPhoneNumber.substr(9, 4).c_str());
								}
								else if(tPhoneNumber.substr(0, 2) == "02"){
									phoneSplit1 = atoi(tPhoneNumber.substr(0, 2).c_str());
									phoneSplit2= atoi(tPhoneNumber.substr(3, 4).c_str());
									phoneSplit3 = atoi(tPhoneNumber.substr(8, 4).c_str());
								}
								phoneCombin = 100000000*phoneSplit1 + 10000*phoneSplit2 + phoneSplit3;

                            cout << "Age: "; cin >> tAge; getchar();			//	나이 입력 후, 버퍼에 남은 개행문자 제거
                            phoneBook.push_back(new Friend(tFirstName, tLastName, phoneCombin, tAge));
                            cout << "Successfully added new person." << endl;
							break;
                    }
                    break;		//	"CP-2016-10399> "를 띄우는 부분으로 돌아감


                case 2:	/* Remove person */
                    cout << "Enter Index of person: "; cin >> index;	//	제거할 person의 index 입력
					phonebook_size = phoneBook.size();
                    if(index-1 >= phonebook_size || index <= 0)
                        cout << "Person does not exist!" << endl;		//	존재하지 않는 person의 index
                    else{
                        cout << "A person is successfully deleted from the Phone Book!" << endl;
                        phoneBook.erase(phoneBook.begin()+index-1);		//	index-th 객체(의 포인터) 삭제
                    }
                    getchar();	//	cin 호출 뒤 버퍼에 남은 개행문자 제거
                    break;		//	"CP-2016-10399> "를 띄우는 부분으로 돌아감


                case 3:	/* Print phone book */
                    cout << "Phone Book Print" << endl;
					phonebook_size = phoneBook.size();
                    for(i=0; i<phonebook_size; i++){
						cout << (i+1) << ". ";
                        phoneBook[i]->print();
                    }
                    getchar();	//	cin 호출 뒤 버퍼에 남은 개행문자 제거
                    break;		//	"CP-2016-10399> "를 띄우는 부분으로 돌아감
            }
        }
    return 0;
}

void getdate(int* y, int* m, int* d)	//	현재 시각(연, 월, 일)을 계산
{
	/*	time_t time (time_t* timer) */
    time_t t;
	time(&t);	//	&t가 가리키는 tim_t형 변수(즉 t)의 값을 구한 time_t형의 현재 시각으로 바꾼다.

	/* tm* localtime (time_t* timer) */
    tm* timePtr = localtime(&t);	//	time_t형의 값을 이용하여 지역 시간을 기준으로 tm 구조체를 초기화하고 그 포인터를 반환한다.

    *y = timePtr->tm_year + 1900;	//	tm_year = Year - 1900
    *m = timePtr->tm_mon + 1;		//	tm_mon = Month [0-11]
    *d = timePtr->tm_mday;			//	tm_mday = Day [1-31]
}
