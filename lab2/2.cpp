#include <iostream>

using namespace std;

int main(void)
{
    char alphabet;
    char temp;
    bool out = false;
    
    while(true){
        cout << "Enter Capital or Small letter<0 for exit>:";
        cin >> alphabet;
        temp = alphabet;
        
        if(alphabet == '0'){
            cout << "Exiting..." << endl;
            out = true;
            break;
        }
        
        if(alphabet >= 97){
            alphabet -= 32;
            cout << "input: " << temp << " output: " << alphabet << endl;
        }
        else if(alphabet >= 65){
            alphabet += 32;
            cout << "input: " << temp << " output: " << alphabet << endl;
        }
        else{
            cout << "Enter character" << endl;
        }
    }

    return 0;
}
