问题
给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）。例如：给定一个长度为6的数组A{5， 6， 7， 1， 2， 8}，则其最长的单调递增子序列为{5，6，7，8}，长度为4.
解法1：最长公共子序列法
解法2：动态规划法（时间复杂度O(N^2))
#include <iostream>
using namespace std;
#define len(a) (sizeof(a) / sizeof(a[0])) //数组长度
int lis(int arr[], int len)
{
    int longest[len];
    for (int i=0; i<len; i++)
        longest[i] = 1;
    
    for (int j=1; j<len; j++) {
        for (int i=0; i<j; i++) {
            if (arr[j]>arr[i] && longest[j]<longest[i]+1){ //注意longest[j]<longest[i]+1这个条件，不能省略。
                longest[j] = longest[i] + 1; //计算以arr[j]结尾的序列的最长递增子序列长度
            }
        }
    }
    
    int max = 0;
    for (int j=0; j<len; j++) {
        cout << "longest[" << j << "]=" << longest[j] << endl;
        if (longest[j] > max) max = longest[j];  //从longest[j]中找出最大值
    }
    return max;
}

int main()
{
    int arr[] = {1, 4, 5, 6, 2, 3, 8}; //测试数组
    int ret = lis(arr, len(arr));
    cout << "max increment substring len=" << ret << endl;
    return 0;
}

解法3：O(NlgN）算法
      假设存在一个序列d[1..9] ={ 2，1 ，5 ，3 ，6，4， 8 ，9， 7}，可以看出来它的LIS长度为5。
      下面一步一步试着找出它。
      我们定义一个序列B，然后令 i = 1 to 9 逐个考察这个序列。
      此外，我们用一个变量Len来记录现在最长算到多少了
      
      首先，把d[1]有序地放到B里，令B[1] = 2，就是说当只有1一个数字2的时候，长度为1的LIS的最小末尾是2。这时Len=1
      
      然后，把d[2]有序地放到B里，令B[1] = 1，就是说长度为1的LIS的最小末尾是1，d[1]=2已经没用了，很容易理解吧。这时Len=1
      
      接着，d[3] = 5，d[3]>B[1]，所以令B[1+1]=B[2]=d[3]=5，就是说长度为2的LIS的最小末尾是5，很容易理解吧。这时候B[1..2] = 1, 5，Len＝2
      
      再来，d[4] = 3，它正好加在1,5之间，放在1的位置显然不合适，因为1小于3，长度为1的LIS最小末尾应该是1，这样很容易推知，长度为2的LIS最小末尾是3，于是可以把5淘汰掉，这时候B[1..2] = 1, 3，Len = 2
      
      继续，d[5] = 6，它在3后面，因为B[2] = 3, 而6在3后面，于是很容易可以推知B[3] = 6, 这时B[1..3] = 1, 3, 6，还是很容易理解吧？ Len = 3 了噢。
      
      第6个, d[6] = 4，你看它在3和6之间，于是我们就可以把6替换掉，得到B[3] = 4。B[1..3] = 1, 3, 4， Len继续等于3
      
      第7个, d[7] = 8，它很大，比4大，嗯。于是B[4] = 8。Len变成4了
      
      第8个, d[8] = 9，得到B[5] = 9，嗯。Len继续增大，到5了。
      
      最后一个, d[9] = 7，它在B[3] = 4和B[4] = 8之间，所以我们知道，最新的B[4] =7，B[1..5] = 1, 3, 4, 7, 9，Len = 5。
      
      于是我们知道了LIS的长度为5。
      
      注意，这个1,3,4,7,9不是LIS，它只是存储的对应长度LIS的最小末尾。有了这个末尾，我们就可以一个一个地插入数据。虽然最后一个d[9] = 7更新进去对于这组数据没有什么意义，但是如果后面再出现两个数字 8 和 9，那么就可以把8更新到d[5], 9更新到d[6]，得出LIS的长度为6。
      
      然后应该发现一件事情了：在B中插入数据是有序的，而且是进行替换而不需要挪动——也就是说，我们可以使用二分查找，将每一个数字的插入时间优化到O(logN)~~~~~于是算法的时间复杂度就降低到了O(NlogN)～！
      代码如下（代码中的数组B从位置0开始存数据）：




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
      
#define N 9 //数组元素个数
      int array[N] = {2, 1, 6, 3, 5, 4, 8, 7, 9}; //原数组
      int B[N]; //在动态规划中使用的数组,用于记录中间结果,其含义三言两语说不清,请参见博文的解释
      int len; //用于标示B数组中的元素个数
      
      int LIS(int *array, int n); //计算最长递增子序列的长度,计算B数组的元素,array[]循环完一遍后,B的长度len即为所求
      int BiSearch(int *b, int len, int w); //做了修改的二分搜索算法
      
      int main()
{
    printf("LIS: %d\n", LIS(array, N));
    
    int i;
    for(i=0; i<len; ++i)
    {
        printf("B[%d]=%d\n", i, B[i]);
    }
    
    return 0;
}
      
      int LIS(int *array, int n)
{
    len = 1;
    B[0] = array[0];
    int i, pos = 0;
    
    for(i=1; i<n; ++i)
    {
        if(array[i] > B[len-1]) //如果大于B中最大的元素，则直接插入到B数组末尾
        {
            B[len] = array[i];
            ++len;
        }
        else
        {
            pos = BiSearch(B, len, array[i]); //二分查找需要插入的位置
            B[pos] = array[i];
        }
    }
    
    return len;
}
      
 //修改的二分查找算法，返回数组元素需要插入的位置。
      int BiSearch(int *b, int len, int w)
{
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right-left)/2;
        if (b[mid] > w)
            right = mid - 1;
        else if (b[mid] < w)
            left = mid + 1;
        else    //找到了该元素，则直接返回
            return mid;
    }
    return left;//数组b中不存在该元素，则返回该元素应该插入的位置
}


