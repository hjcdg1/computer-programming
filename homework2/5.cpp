#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void)
{
	double value, total_value = 0;
	int product_num, quantity;
	string input;

	while(true){

		/*	첫 번째 입력 부분	  */
		cin >> input;
		if(input == "Closed")	break;		//	"Closed"를 입력했다면 while문을 빠져나감으로써 프로그램 종료
		product_num = atoi(input.c_str());	//	Product Number에 해당하는 숫자를 입력했다면 이를 정수로 변환하여 product_num에 대입


		/*	두 번째 입력 부분	  */
		cin >> quantity;					//	quantity를 사용자로부터 입력받음


		/*	product_num에 해당하는 Product의 가격을 value에 대입  */
		switch(product_num){
			case 1: value = 2.98; break;
			case 2: value = 4.50; break;
			case 3: value = 9.98; break;
			case 4: value = 4.49; break;
			case 5: value = 6.87; break;
		}
	
		total_value += value*quantity;		//	total_value에 quantity개 제품의 가격을 더해줌
	}

	cout << "Total retail value : " << total_value << endl;		//	total_value 출력

	return 0;
}
