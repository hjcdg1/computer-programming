#include <iostream>
using namespace std;

int main(void)
{
	int input;

	cin >> input;
	
	cout << input/10000 << " "							//	만의 자리수 출력
		 << (input%10000)/1000 << " "					//	천의 자리수 출력
		 << ((input%10000)%1000)/100 << " "				//	백의 자리수 출력
		 << (((input%10000)%1000)%100)/10 << " "		//	십의 자리수 출력
		 << ((((input%10000)%1000)%100)%10)				//	일의 자리수 출력
		 << endl;

	return 0;
}
