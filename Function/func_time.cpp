// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <math.h>
// #include <windows.h>
// using namespace std;

// int main()
// {
//     DWORD start, end;
//     start = GetTickCount();
//     long long k = 1, t1 = 1;
    
//     for(long long i = 2000000000;i<20000000000;i++){
//         k = t1 + i;
//     }
//     end = GetTickCount() - start;
//     cout<<end<<endl;
//     system("pause");
//     return 0;
// }

#include <iostream>
#include <limits>
// #include <windows.h>
using namespace std;

int main()
{
    // DWORD start, end;
    // start = GetTickCount();
    long long k, s = 0, x, y;

    while (scanf("%lld",&k)!=EOF)
    {
        x = k / 4, y = k % 4;
        // t2 = 2 * x - 1;
        // t3 = 2 * x + 1;
        if (y == 0)
        {
            s = 4 * x * x;
        }
        else if (y == 1)
        {
            s =  4 * x * x + 2 * x - 1;
        }
        else if (y == 2)
        {
            // s = t1 + t2 + t3;
            s= 4 * x * x + 4 * x;
        }
        else if (y == 3)
        {
            // s = t1 + t2 + t3 + t3;
            s = 4 * x * x + 6 * x + 1;
        }
        printf("%lld\n",s);
        if (s & 1)                     //判断最后一位是否为1
            printf("%lld.5\n", s / 2); //取商，拼".5" 如商为2,实际打印结果为 2.5
        else
            printf("%lld.0\n", s / 2); //最后一位为0，拼".0"
                                       // double s1=s*0.5;
                                       //  printf("%.1f\n",s1);
        //cout<<numeric_limits<double>::max()<<endl;
        // cout<<numeric_limits<double>::min()<<endl;
        // end = GetTickCount() - start;
        // cout << end << endl;
    }
    return 0;
}