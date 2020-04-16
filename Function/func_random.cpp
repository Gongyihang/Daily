#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

int main(){
    double t;
    srand((int)time(0));
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            t = rand()%100;
            printf("%f ",t);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}