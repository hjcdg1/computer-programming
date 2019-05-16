#include <iostream>

using namespace std;

int main(void)
{
    int n, i;
    int result = 0 ;
    cin >> n;
    for(i=1; i<=n; i++){
        result += i;
    }
    cout << result << endl;
    return 0;
}
