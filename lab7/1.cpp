#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
	int i = 0, line_number = 0, index, count;
	int start, end, number;
	string input_line, key;
	ifstream in_file(argv[1]);

	vector<int> v;
	set<int> s;
	map<string, int> m;
	vector<int>::iterator vi;
	set<int>::iterator si;
	map<string, int>::iterator mi;


	if(in_file.is_open()){

		while(getline(in_file, input_line)){	//	이 while문의 반복 횟수 = line 개수

			line_number ++;
			index = 0;
			i = 0;

			start = i;	//	숫자의 시작 부분

			while(true){
				if(i >= input_line.size()){
					end = i-1;

					number = atoi(input_line.substr(start, end-start+1).c_str());	index ++;
					key = "[" + to_string((long long)line_number) + ":" + to_string((long long)index) + "]";

					v.push_back(number);
					s.insert(number);
					m.insert(pair<string, int>(key, number));

					break;
				}
				else{
					if((input_line.at(i) >= '0'  &&  input_line.at(i) <= '9')  ||  input_line.at(i) == '-')	i++;
					else if(input_line.at(i) == ','){
						end = i-1;

						number = atoi(input_line.substr(start, end-start+1).c_str());	index ++;
						key = "[" + to_string((long long)line_number) + ":" + to_string((long long)index) + "]";

						v.push_back(number);
						s.insert(number);
						m.insert(pair<string, int>(key, number));
							
						i++;
						if(i < input_line.size())	start = i;
					}
				}
			}
			
			cout << "[line " << line_number << "]" << endl;

			/* vector 출력 부분 */
			cout << "vector_container : ";
			for(vi = v.begin(); vi != v.end()-1; ++vi)
				cout << *vi << ",";
			cout << *vi << endl;

			/* set 출력 부분 */
			count = 0;
			cout << "set_container : ";
			for(si = s.begin(); si != s.end(); si++){
				cout << *si << ",";
				count++;
				if(count == s.size()-1){
					si++;
					break;
				}
			}
			cout << *si << endl;

			/* map 출력 부분 */
			count = 0;
			cout << "map_container : ";
			for(mi = m.begin(); mi != m.end(); mi++){
				cout << (*mi).first << "==" << (*mi).second << ",";
				count++;
				if(count == m.size()-1){
					mi++;
					break;
				}
			}
			cout << (*mi).first << "==" << (*mi).second << endl;

			v.clear();
			s.clear();
			m.clear();
		}
	}

	in_file.close();
	return 0;
}
