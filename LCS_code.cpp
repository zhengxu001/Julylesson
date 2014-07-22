注意：LCS是最长公共子序列并非最长公共子串
 1.暴力法事件复杂度是O(2^m*2^n);
 2.动态规划


void print_lcs(int path**,int A[],int n,int m)
{
    if(i==0||j==0)
	return ;
    if(path[a][b]==1)
	print_lcs(path,s,a-1,b);
    else if(path[a][b]==2)
    {
	print_lcs(path,s,a-1,b);
	print("%c",s[a-1]);
    }
    else
    {
	print_lcs(path,s,a,b-1);
    }
}


void LCS_LENGH(int A*,int n,int B*,int m)
{
    int path[][];
    int lcs[][];
    for(int i=0;<n;i++)
    {
	if(A[i]==B[0])
	    lcs[i][0]=1;
	else
	    lcs[i][0]=0;
    }
    for (int i=0;i<m;i++)
    {	
	if(B[i]=A[0])
	    lcs[0][i]=1;
	else
	    lcs[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
	for(int j=1;j<m;j++)
	{
	    if(A[i]==B[j])
	    {
		lcs[i][j] = lcs[i-1][j-1] +1;
		path[i][j]=2;
	    }
	    else if(lcs[i-1][j]>=lcs[i][j-1])
	    {
	        lcs[i][j] =lcs[i-1][j];
	        path[i][j] = 1;
            }
	    else 
	    {
		lcs[i][j] =lcs[i][j-1];
		path[i][j] = 3;
	    }
	}
    }
    print_lcs(path,s,lens,lent)
    printf("length=%d",lcs[n-1][m-1]);
}

int main()
{
    char s[M],t[];
    scanf("%s%s",s,t);
    dp(s,t);
    return 0;
}





