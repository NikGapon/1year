

#include <iostream>

using namespace std;
int tw = 0;
int fi = 0;
int te = 0;
int coin = 0;

int two(int t) {
    
    while ((t - 2) >= 0) {
        t = t - 2;
        coin = coin + 1;
        
    }
    return t;
}
int five(int t) {
    while ((t - 5) >= 0) {
        t = t - 5;
        coin = coin + 1;
        
    }
    return t;
}
int ten(int t) {
    while ((t - 10) >= 0) {
        t = t - 10;
        coin = coin + 1;
        
    }
    return t;
}
int main()
{
    
    int summ;
    cin >> summ;
    /*for (int i = 0; i <= sum / 2; i++) {
        sum = ten(sum);

    }*/
    summ = ten(summ);
    summ = five(summ);
    summ = two(summ);
    ///cout << summ;
    cout << coin;
}
