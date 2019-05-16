#include <iostream>
#include <vector>
using namespace std;

class Member {
    private:
        string name;
        int age;
        string department;
    public:
        Member(string name, int age, string department){
            this->name = name;
            this->age = age;
            this->department = department;
        }
        ~Member();
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        string getDept(){
            return department;
        }
        void print(){
            cout << name << " " << age << " " << department << endl;
        }
};


int main(void)
{
    int i;
    string input_name;
    int input_age;
    string input_department;
    Member* temp;

    vector<Member*> v;

    while(true){

    cin >> input_name >> input_age >> input_department;
    if(input_name == "QUIT"  ||  input_age == 0 || input_department == "QUIT")
        break;    
    temp = new Member(input_name, input_age, input_department);
    v.push_back(temp);
    temp->print();
    }
    /*
    for(i=0; i<v.size(); i++){
        v[i]->print();
    }*/

    for(i=0; i<v.size(); i++){
        cout << v[i]->getName() << " : " << v[i]->getDept() << ", " << v[i]->getAge() << " years old." << endl;
    }
    /*
    for(i=0; i<v.size(); i++){
        v.erase(v.begin()+i);
    }*/
}
