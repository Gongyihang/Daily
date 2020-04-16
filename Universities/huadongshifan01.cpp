#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int num1,num2;
    char ch;
    while (scanf("%d%c%d", &num1, &ch, &num2) != EOF)
    {
        switch (ch)
        {
        case '+':
            cout << num1 + num2<<endl;
            break;
        case '-':
            cout << num1 - num2<<endl;
            break;
        case '*':
            cout << num1 * num2<<endl;
            break;
        case '/':
            printf("%.1f\n",(double)num1/(double)num2);
            break;
        }
    }
    system("pause");
    return 0;
}