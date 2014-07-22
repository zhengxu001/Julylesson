//编辑距离，又称Levenshtein距离，是指两个字串之间，由一个转成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。

/*计算替换操作的代价，如果两个字符相同，则替换操作代价为0，否则为1
if str1[i]== str2[j] then cost := 0
else cost := 1
//d[i,j]的Levenshtein距离，可以有
d[i, j] := minimum(
d[i-1, j] + 1, //在str1上i位置删除字符（或者在str2上j-1位置插入字符）
d[i, j-1] + 1, //在str1上i-1位置插入字符（或者在str2上j位置删除字符）
d[i-1, j-1] + cost // 替换操作
)
*/
#include <iostream>
#include <string>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int edit(string str1, string str2)
{
    int max1 = str1.size();
    int max2 = str2.size();
    
    int **ptr = new int*[max1 + 1];
    for(int i = 0; i < max1 + 1 ;i++)
    {
        ptr[i] = new int[max2 + 1];
    }
    
    for(int i = 0 ;i < max1 + 1 ;i++)
    {
        ptr[i][0] = i;
    }
    
    for(int i = 0 ;i < max2 + 1;i++)
    {
        ptr[0][i] = i;
    }
    
    for(int i = 1 ;i < max1 + 1 ;i++)
    {
        for(int j = 1 ;j< max2 + 1; j++)
        {
            int d;
            int temp = min(ptr[i-1][j] + 1, ptr[i][j-1] + 1);
            if(str1[i-1] == str2[j-1])
            {
                d = 0 ;
            }
            else
            {
                d = 1 ;
            }
            ptr[i][j] = min(temp, ptr[i-1][j-1] + d);
        }
    }
    
    cout << "**************************" << endl;
    for(int i = 0 ;i < max1 + 1 ;i++)
    {
        for(int j = 0; j< max2 + 1; j++)
        {
            cout << ptr[i][j] << " " ;
        }
        cout << endl;
    }
    cout << "**************************" << endl;
    int dis = ptr[max1][max2];
    
    for(int i = 0; i < max1 + 1; i++)
    {
        delete[] ptr[i];
        ptr[i] = NULL;
    }
    
    delete[] ptr;
    ptr = NULL;
    
    return dis;
}

int main(void)
{
    string str1 = "sailn";
    string str2 = "failing";
    
    int r = edit(str1, str2);
    cout << "the dis is : " << r << endl;
    
    return 0;
}


