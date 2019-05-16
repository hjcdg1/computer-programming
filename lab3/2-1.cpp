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

    Book* arr = new Book[n];
    for(i=0; i<n; i++){
        cin >> arr[i].name;
        cin >> arr[i].price;
    }

    for(i=0; i<n; i++){
        cout << arr[i].name << endl;
    }

    for(i=0; i<n; i++){
        cout << arr[i].price << endl;
    }

    delete [] arr;

    return 0;
}
