//�༭���룬�ֳ�Levenshtein���룬��ָ�����ִ�֮�䣬��һ��ת����һ����������ٱ༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ���

/*�����滻�����Ĵ��ۣ���������ַ���ͬ�����滻��������Ϊ0������Ϊ1
if str1[i]== str2[j] then cost := 0
else cost := 1
//d[i,j]��Levenshtein���룬������
d[i, j] := minimum(
d[i-1, j] + 1, //��str1��iλ��ɾ���ַ���������str2��j-1λ�ò����ַ���
d[i, j-1] + 1, //��str1��i-1λ�ò����ַ���������str2��jλ��ɾ���ַ���
d[i-1, j-1] + cost // �滻����
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


