#include <iostream>

using namespace std;

class Vending {
    private:
        int price;
        int count;
    public:
        void setPrice(int price){
            this->price = price;
        }
        void setCount(int count){
            this->count = count;
        }
        int coffee(int money){
            int number = money/(this->price);
        
            if(number >= count) return count;
            else{
                count -= number;
                return number;
            }
        }
    
};

int main(void)
{
    int p, c, n;
    Vending v;
    int result;
    
    cin >> p;
    cin >> c;
    cin >> n;
    
    v.setPrice(p);
    v.setCount(c);

    result = v.coffee(n);
    cout << result << endl;

    return 0;
}
