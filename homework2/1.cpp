#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	char input;

	input = getchar();		//	버퍼에 있는 문자를 하나 읽어옴
    
	while(input != '\n'){
        if(input != ' ')
            cout << static_cast<int>(input) << " "; 	//	그 문자에 해당하는 integer값 출력
        input = getchar();  //  버퍼에 있는 문자를 하나 읽어옴
    }

	return 0;
}
