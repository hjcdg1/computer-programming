#include <iostream>
using namespace std;

int main(void)
{
	int x = 1;

	/* int는 32bit이므로 양수 범위 내에서는 [2^1 ~ 2^(30)] 까지만 정상 출력됨 */
	/* 2^(31)의 경우 MSB가 1이고 나머지 비트가 모두 0이므로 -2^(31) 이 출력됨 */
	/* 2^n (for n>31) 의 경우 32bit 이상으로 Overflow가 일어나서 32bit는 모두 0이므로, 0이 출력됨 */
	while(true){
		x *= 2;
		cout << x << endl;
	}

	return 0;
}
