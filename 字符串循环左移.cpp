/*暴力移位法
每次循环左移1位，调用k次即可
时间复杂度O(kN)，空间复杂度O(1)
三次拷贝
S[0…k] → T[0…k]
S[k+1…N-1] → S[0…N-k-1]
T[0…k] →S[N-k…N-1]
时间复杂度O(N)，空间复杂度O(k)

优雅一点的算法
时间复杂度O(N)，空间复杂度O(1)
*/
void ReverseString(char *s, int from, int to)
{
    while(from<to)
    {
	char t = s[from];
	s[from++] = s[to];
	s[to--] = t;
    }
}

void LeftRotateSting(char *s,int n,int m)
{
    m%=n;
    ReverseString(s,0,m-1);
    ReverseString(s,m,n-1);
    Reversestring(s,0,n-1);
}








