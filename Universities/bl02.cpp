#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef struct
{
    KeyType key;
} ElemType;

typedef struct
{
    ElemType *R;
    int length;
} SSTable;

void Create(SSTable &T)
{
    int i;
    T.R = new ElemType[MAXSIZE + 1];
    cin >> T.length;
    for (i = 1; i <= T.length; i++) //注意这里下标从1开始，到length
        cin >> T.R[i].key;
}

int Search_Bin(SSTable T, KeyType k); //声明在定义之前

int main()
{
    SSTable T;
    KeyType k;
    Create(T);
    cin >> k;
    int pos = Search_Bin(T, k);
    if (pos == 0)
        cout << "NOT FOUND" << endl;
    else
        cout << pos << endl;
    return 0;
}

int Search_Bin(SSTable T, KeyType k)
{
    int left = 1, right = T.length; //注意下标从1开始,下面while循环不带等号。
    while (left < right)
    {
        int mid = (left + right) / 2; //注意

        if (T.R[mid].key < k)
        {
            left = mid + 1;     
        }
        else if (T.R[mid].key > k)
        {
            right = mid - 1;
        }
        else if (T.R[mid].key == k)
        {
            return mid;
        }
    }
    return 0;
}

// #include <iostream>
// using namespace std;

// #define MAXSIZE 50
// typedef int KeyType;

// typedef struct
// {
//     KeyType key;
// } ElemType;

// typedef struct
// {
//     ElemType *R;
//     int length;
// } SSTable;

// void Create(SSTable &T)
// {
//     int i;
//     T.R = new ElemType[MAXSIZE + 1];
//     cin >> T.length;
//     for (i = 1; i <= T.length; i++)
//         cin >> T.R[i].key;
// }

// int Search_Bin(SSTable T, KeyType k);

// int main()
// {
//     SSTable T;
//     KeyType k;
//     Create(T);
//     cin >> k;
//     int pos = Search_Bin(T, k);
//     if (pos == 0)
//         cout << "NOT FOUND" << endl;
//     else
//         cout << pos << endl;
//     return 0;
// }

// /* 请在这里填写答案 */