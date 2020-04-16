#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int sum = 0,val = 1;
    while(val <= 10){
        sum += val;
        val++;
    }
    cout << sum << endl;

    system("pause");
    return 0;
}