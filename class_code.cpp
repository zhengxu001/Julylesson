##1.�������������
��������:
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

2.�ֶ��δ���
//��������м�ֿ�����ô���������Ҫô��ȫ���������飬Ҫô��ȫ���Ұ�����飬Ҫô�����ڷֽ���ϡ�
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

3.(������)�ռ任ʱ�䣬�������Ż����ݿ��ʱ���ù����У�
//��¼ǰ׺��P[i].i��j֮������ֵ
//����i��0��i ��n-1������p[0��i]����Сֵm
p[i]-m��Ϊ��A[i]��β������������������
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
    //M[i]�м�¼����i��β�����ֵ
     return ret;
}

4.��̬�滮
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
    






