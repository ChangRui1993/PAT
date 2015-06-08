/**
E. 有几个PAT（25）
字符串APPAPT中包含了两个单词“PAT”，
其中第一个PAT是第2位(P),第4位(A),第6位(T)；
第二个PAT是第3位(P),第4位(A),第6位(T)。
现给定字符串，问一共可以形成多少个PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT

输出样例：
2
*/

/**
	通过 2/5，分数15/25
*/


#include <iostream>
#include <string>

using namespace std;

int find_pat(string s);
int find_at(string s);
int find_t(string s);

int main()
{

    string s;

    while(cin>>s)
    {
        int result = find_pat(s);
        cout << result << endl;
    }

    return 0;
}

int find_pat(string s)
{
    int result = 0;
    int pos = 0;
    while((pos=s.find('P'))!=-1)
    {
        s = s.substr(pos+1,s.size()-1);
        result += find_at(s);
        result %= 1000000007;
    }
    return result;
}

int find_at(string s)
{
    int result = 0;
    int pos = 0;
    while((pos=s.find('A'))!=-1)
    {
        s = s.substr(pos+1,s.size()-1);
        result += find_t(s);
        result %= 1000000007;
    }
    return result;
}

int find_t(string s)
{
    int result = 0;
    int pos = 0;
    while((pos=s.find('T'))!=-1)
    {
        s = s.substr(pos+1,s.size()-1);
        result++;
        result %= 1000000007;
    }
    return result;
}
