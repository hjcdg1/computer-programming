#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	char order;
	int number;
	set<int> s;

	while(true){
		cin >> order;
		if(order == 'q')
			break;
		cin >> number;

		if(order == 'i')
			s.insert(number);
		
		else if(order == 'd')
			s.erase(number);
		
		else if(order == 'c'){
			set<int>::iterator f = s.find(number);
			if(f != s.end())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
	}
	return 0;
}
