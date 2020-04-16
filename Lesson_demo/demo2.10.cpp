/*
给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。

示例 1：
输入：nums = [12,345,2,6,7896]
输出：2
解释：
12 是 2 位数字（位数为偶数） 
345 是 3 位数字（位数为奇数）  
2 是 1 位数字（位数为奇数） 
6 是 1 位数字 位数为奇数） 
7896 是 4 位数字（位数为偶数）  
因此只有 12 和 7896 是位数为偶数的数字

示例 2：
输入：nums = [555,901,482,1771]
输出：1 
解释： 
只有 1771 是位数为偶数的数字。
 

提示：
1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0, count_evev = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != 0)
            {
                nums[i] /= 10;
                count++;
            }
            if (count % 2 == 0)
            {
                count_evev++;
            }
            count = 0;//重置count
        }
        return count_evev;
    }
};

int main()
{
    Solution s;

    vector<int> num = {437,315,322,431,686,264,442};

    int count_even = s.findNumbers(num);
    printf("%d\n", count_even);
    system("pause");
    return 0;
}
