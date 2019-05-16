#include <iostream>

using namespace std;

void swap(int *a, int *b);
void swap(char *a, char *b);

int main(void)
{
    int a, b;
    char c, d;
    cout << "Put two numbers for swapping" << endl;
    cin >> a >> b;
    cout << "Put two characters for swapping" << endl;
    cin >> c >> d;
    swap(&a, &b);
    swap(&c, &d);
    cout << "Results" << endl;
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
