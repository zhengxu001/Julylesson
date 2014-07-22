##1.最大连续子数组
暴力代码:
int MaxSuubArray(int *A,int n)
{
    int maxSum= A[0];
    int currSum=0;
    for(int i=0;i<n;i++)
    {
	for(int j=i;j<n;j++)
	{
	    for(int k=i;k<=j;k++)
	    {
		currSum+=A[k];
	    }
	    if(currSum>maxSum)
	        maxSum=currSum;
	    currSum = 0;
	}
    }
    return maxSum;
}

2.分而治代码
//将数组从中间分开，那么最大子数组要么完全在左半边数组，要么完全在右半边数组，要么跨立在分界点上。
int MaxAddSum(int A*,int from,int to)
{
    if(to==from)
    return A[from]

    int middle = (from+to)/2;
    int m1 = MaxAddSub(from,middle);
    int m2 = MaxAddSub(middle+1,to);

    int left = A[middle];
    int now = A[middle];

    for(int i=middle-1;i>=left;--i)
    {
	now += A[i];
	left = max{left,now};
    }
    
    int right = A[middle+1];
    now = A[middle+1];
    
    for(int i= middle+2;i<=to;++i)
    {
	now += A[i];
	right = max(now,right);
    }

    int  m3 = left+right;
    return max(m1,m2,m3);
}

3.(分析法)空间换时间，当年我优化数据库的时候用过这招；
//记录前缀和P[i].i，j之间的最大值
//遍历i：0≤i ≤n-1，计算p[0…i]中最小值m
p[i]-m即为以A[i]结尾的数组中最大的子数组
int MaxAddSum(int A*,int n)
{
    int ret;
    int P[n];
    P[0] = A[0];
    for (int i=1;i<n;++i)
    {
	P[i]=A[i]+P[i-1];
    }
    int M[i];
    int befor_min
    for(int i=0;i<n;i++)
    {
	befor_min=min{p[i],befor_min};
	M[i]=p[i]-min;
	if(M[i]>ret)
	ret=M[i];
    }
    //M[i]中记录了以i结尾的最大值
     return ret;
}

4.动态规划
int MaxAddSum(int A*,int n)
{
    int ret=A[0];
    sum = A[0];

    for(int i=0;i<n;i++)
    {
	if(sum<0)
	    sum=0;
	sum+=a[i];
	
	if(sum>result)
	    result=sum;
    }

    return result;
}
    






