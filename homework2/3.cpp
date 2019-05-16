#include <iostream>
#include <string>
using namespace std;

class Employee
{
	public:
		Employee(string fn, string ln, int s){
			set_first_name(fn);
			set_last_name(ln);
			set_monthly_salary(s);
		}

		string get_first_name(void){		//	return first name
			return first_name;
		}
		string get_last_name(void){			//	return last name
			return last_name;
		}
		int get_monthly_salary(void){		//	return monthly salary
			return monthly_salary;
		}

		void set_first_name(string fn){		//	set first name
			first_name = fn;
		}
		void set_last_name(string ln){		//	set last name
			last_name = ln;
		}
		void set_monthly_salary(int s){		//	set monthly_salary
			if(s<=0)	monthly_salary = 0;	//	if it is not postive, set it to 0
			else		monthly_salary = s;
		}


	private:
		string first_name;
		string last_name;
		int monthly_salary;
};

int main(void)
{
	int line_number, i, input_s;
	string input_fn, input_ln;
	Employee** memory;

	cin >> line_number;						//	몇 명의 Employee를 생성할지, 사용자로부터 입력받음
	memory = new Employee*[line_number];	//	그만큼의 Empolyee 객체 주소를 담을 배열을 동적 할당

	/* line_number 만큼 반복 : 입력받은 이름, 성, 급여를 바탕으로 매번 새 Employee 객체를 생성하고 저장 */
	for(i=0; i<line_number; i++){
		cin >> input_fn >> input_ln >> input_s;
		memory[i] = new Employee(input_fn, input_ln, input_s);
	}

	/* 객체의 주소가 저장된 배열에 접근하여 모든 Empolyee 객체들의 정보를 출력 1 */
	for(i=0; i<line_number; i++){
		cout << "Employee[" << memory[i]->get_first_name() << " " << memory[i]->get_last_name() 
			 << "]_Salary : $" << 12*memory[i]->get_monthly_salary() << endl; 
	}

	/* 객체의 주소가 저장된 배열에 접근하여 모든 Empolyee 객체들의 정보를 출력 2 */
	for(i=0; i<line_number; i++){
		cout << "Employee[" << memory[i]->get_first_name() << " " << memory[i]->get_last_name() 
			 << "]_Salary : $" << (11*12*memory[i]->get_monthly_salary())/10 << endl; 
	}

	return 0;
}
