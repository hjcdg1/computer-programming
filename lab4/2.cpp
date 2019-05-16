#include <iostream>
#include <vector>

using namespace std;

class Person {
    private:
        string name;
        int age;
        string gender;

    public:
        Person(string name, int age, string gender){
            this->name = name;
            this->age = age;
            this->gender = gender;
        }
        ~Person(){};
        
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        string getGender(){
            return gender;
        }
        virtual void introduce(){
            cout << name << " is " << age << " years old, and is " << gender << endl;
        }
};

class Student : public Person {
    private:
        string school;
    public:
        Student(string n, int a, string g, string s) : Person(n, a, g) {
            school = s;
        }
        void introduce(){
            cout << getName() << " is " << getAge() << " years old, and is " << getGender() << endl;
            cout << getName() << " is studying in " << school << endl;
        }
};



int main(void)
{
    int n, i, m, j;
    string input_name, input_gender, input_school;
    int input_age;
    string temp_gender;
    int temp_age;

    vector<Person*> v;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> input_name >> input_age >> input_gender;
        v.push_back(new Person(input_name, input_age, input_gender));
    }

    cin >> m;
    for(i=0; i<m; i++){
        cin >> input_name >> input_school;
        for(j=0; j<n; j++){
            if(input_name == v[j]->getName()){
                temp_age = v[j]->getAge();
                temp_gender = v[j]->getGender();
                v[j] = new Student(input_name, temp_age, temp_gender, input_school);
            }
        }
    }

    for(i=0; i<v.size(); i++){
        v[i]->introduce();
    }
}
