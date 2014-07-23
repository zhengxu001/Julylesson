//http://blog.csdn.net/morewindows/article/details/7370155/

//没有去重复的全排列：
//leetcode的地址https://oj.leetcode.com/problems/permutations/
void permutation(vector<int> &num,int from,int to,vector<vector<int>> &ret)
{
    if(from==to)
    {
        vector<int> one;
        for(int i=0;i<num.size();i++)
        {
            one.push_back(num[i]);
        }
        ret.push_back(one);
        return;
    }
    for(int i=from;i<=to;i++)
    {
        swap(num[i],num[to]);
        permutation(num,from,to-1,ret);
        swap(num[i],num[to]);
    }
}
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int>> ret;
        int n = num.size();
        permutation(num,0,n-1,ret);
        return ret;
    }
};


//可以去重复的全排列
//https://oj.leetcode.com/problems/permutations-ii/
bool IsSwap(vector<int> &num,int from ,int to)
{
    bool ret=false;
    for(int i=from;i<to;i++)
    {
        if(num[i]==num[to])
            ret=true;
    }
    return ret;
}
void permutation(vector<int> &num,int from,int to,vector<vector<int>> &ret)
{
    if(from==to)
    {
        vector<int> one;
        for(int i=0;i<num.size();i++)
        {
            one.push_back(num[i]);
        }
        ret.push_back(one);
        return;
    }
    for(int i=from;i<=to;i++)
    {
        if(IsSwap(num,from,i))
            continue;
        swap(num[i],num[from]);
        permutation(num,from+1,to,ret);
        swap(num[i],num[from]);
    }
}
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        
        vector<vector<int> > ret;
        permutation(num,0,num.size()-1,ret);
        return ret;
    }
};


/*三．全排列的非递归实现
要考虑全排列的非递归实现，先来考虑如何计算字符串的下一个排列。如"1234"的下一个排列就是"1243"。只要对字符串反复求出下一个排列，全排列的也就迎刃而解了。
如何计算字符串的下一个排列了？来考虑"926520"这个字符串，我们从后向前找第一双相邻的递增数字，"20"、"52"都是非递增的，"26 "即满足要求，称前一个数字2为替换数，替换数的下标称为替换点，再从后面找一个比替换数大的最小数（这个数必然存在），0、2都不行，5可以，将5和2交换得到"956220"，然后再将替换点后的字符串"6220"颠倒即得到"950226"。
对于像"4321"这种已经是最“大”的排列，采用STL中的处理方法，将字符串整个颠倒得到最“小”的排列"1234"并返回false。
这样，只要一个循环再加上计算字符串下一个排列的函数就可以轻松的实现非递归的全排列算法。按上面思路并参考STL中的实现源码，不难写成一份质量较高的代码。值得注意的是在循环前要对字符串排序下，可以自己写快速排序的代码.
*/

//全排列的非递归实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
//反转区间
void Reverse(char *a, char *b)
{
    while (a < b)
        Swap(a++, b--);
}
//下一个排列
bool Next_permutation(char a[])
{
    char *pEnd = a + strlen(a);
    if (a == pEnd)
        return false;
    char *p, *q, *pFind;
    pEnd--;
    p = pEnd;
    while (p != a)
    {
        q = p;
        --p;
        if (*p < *q) //找降序的相邻2数,前一个数即替换数
        {
            //从后向前找比替换点大的第一个数
            pFind = pEnd;
            while (*pFind <= *p)
                --pFind;
            //替换
            Swap(pFind, p);
            //替换点后的数全部反转
            Reverse(q, pEnd);
            return true;
        }
    }
    Reverse(p, pEnd);//如果没有下一个排列,全部反转后返回true
    return false;
}
int QsortCmp(const void *pa, const void *pb)
{
    return *(char*)pa - *(char*)pb;
}
int main()
{
    printf("         全排列的非递归实现\n");
    printf("  --by MoreWindows( http://blog.csdn.net/MoreWindows )--\n\n");
    char szTextStr[] = "abc";
    printf("%s的全排列如下:\n", szTextStr);
    //加上排序
    qsort(szTextStr, strlen(szTextStr), sizeof(szTextStr[0]), QsortCmp);
    int i = 1;
    do{
        printf("第%3d个排列\t%s\n", i++, szTextStr);
    }while (Next_permutation(szTextStr));
    return 0;
}








	    

