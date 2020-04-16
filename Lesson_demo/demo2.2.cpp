#include <iostream>
using namespace std;
/*
输入：cin、scanf、getchar、getline
输出：cout、printf
*/

int main()
{

    // int i = 10;
    char ch = 'h';
    // std::cout << "hello,world" << std::endl << i << ch << std::endl;

    // int j = 16;
    // printf("%d\n",j);
    // printf("%x\n",j);
    // printf("%#x\n",j);
    // printf("%4d\n",j);
    // printf("%04d\n",j);

    // printf("%f\n",10.0);
    // printf("%.1f\n",10.0);
    // printf("%6.1f\n",10.0);

    // printf("%c",ch);
    // printf("%s\n","huihui");

    // std::cin >> i >> j;
    // std::cout << i << j << std::endl;

    // scanf("%d %d",&i,&j);
    // std::cout << i << j << std::endl;

    // scanf("%d,%d",&i,&j);
    // std::cout << i << j << std::endl;
    // int i;
    // cin >> i;
    // getchar();
    // ch = getchar();
    // cout << ch << endl;
    // getchar();
    string s;
    getline(cin, s);
    cout << s << endl;
    char ch1;
    ch1 = getchar();
    cout << ch1 << endl;
    return 0;
}