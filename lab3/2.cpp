#include <iostream>

using namespace std;

class Book {
    public:
        string name;
        int price;
};

int main(void)
{
    int n, i;

    cin >> n;
    Book books[n];

    for(i=0; i<n; i++){
        cin >> books[i].name;
        cin >> books[i].price;
    }

    for(i=0; i<n; i++){
        cout << books[i].name << endl;
    }

    for(i=0; i<n; i++){
        cout << books[i].price << endl;
    }

    return 0;
}
