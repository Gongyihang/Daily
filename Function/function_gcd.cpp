#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <cstdlib>
#include <cstring>
#include<set>
using namespace std;
//辗转相除法 求两个数的最大公约数
 int gcd(int a, int b) {
 return b == 0 ? a : gcd(b, a % b);
 }
 /*
int gcd(int a,int b){
	int temp;
	while(b > 0){
        temp = a % b;
        a = b;
        b = temp;
   }
	return a;
}
//辗转相减法
int measure(int a,int b)
{		
	while(a != b)
	{
		if(a>b)
		{
			a = a - b;
		}
		else 
		{
			b = b - a;
		}
	}
	return a;
}*/
 int measure(int a,int b)
{		
	while(a != b)
	{
		if(a>b)
		{
			a = a - b;
		}
		else 
		{
			b = b - a;
		}
	}
	return a;
}

int main(){
	int n;
    while(cin>>n){
		if(n==0){
			break;
		}
		int t=1;
		if(n%2!=0){
			for(int i=2;i<=n/2;i++){
				if(gcd(n,i)==1){
					t++;
				}
			}	
		}else{
			for(int i=2;i<n/2;i++){
				if(gcd(n,i)==1){
					t++;
				}
			}
		}
		if(n==1||n==2){
			cout<<1<<endl;
		}else{
			cout<<2*t<<endl;
		}
    }
	return 0;
}
//欧拉函数是求小于n中与n互质的数的个数

// int main() {
// 	long long int n;
// 	while (~scanf("%lld",&n)&&n) {
// 		long long int ans=n;
// 		for (long long int i = 2; i <= sqrt(n); i++)
// 		{
// 			if (n % i == 0)
// 			{
// 				ans = ans / i * (i - 1); //欧拉函数
// 			}
// 			while (n % i == 0)//筛选素数
// 			{
// 				n /= i;
// 			}
// 		}
// 		if (n > 1)
// 			ans = ans / n * (n - 1);
// 		printf("%lld\n",ans);
// 	}
// 	return 0;
// }

//欧拉函数是求小于n中与n互质的数的个数

// int main() {
// 	long long int n;
// 	while (~scanf("%lld",&n)&&n) {
// 		long long int ans=n;
// 		for (long long int i = 2; i <= sqrt(n); i++)
// 		{
// 			if (n % i == 0)
// 			{
// 				ans = ans / i * (i - 1); //欧拉函数
// 			}
// 			while (n % i == 0)//筛选素数
// 			{
// 				n /= i;
// 			}
// 		}
// 		if (n > 1)
// 			ans = ans / n * (n - 1);
// 		printf("%lld\n",ans);
// 	}
// 	return 0;
// }