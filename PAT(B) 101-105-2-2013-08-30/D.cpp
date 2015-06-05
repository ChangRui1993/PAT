/**
D. 福尔摩斯的约会 (20)
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；
第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

输出样例：
THU 14:04
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <cstdio>

using namespace std;

bool isNumber(char c);
bool isUpper(char c);
bool isLower(char c);


int find_week(string a, string b);
int find_hour(string a, string b);
int find_minute(string a, string b);

string week[8] = {"","MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    /**
        0 - 9    A - Z     a - z
       48 - 57  65 - 90   97 - 122
    */

    //freopen("D:\input.txt", "r", stdin);

    string a,b,c,d;

    while(cin>>a>>b>>c>>d)
    {

        /** 1.星期 */
        int w = find_week(a,b);
        cout << week[w] << " ";

        /** 2.小时 */
        int hour = find_hour(a,b);
        if(hour<10 && hour>=0)
        {
            cout << "0" << hour;
        }
        else if(hour>=10 && hour <=23)
        {
            cout << hour;
        }
        else
        {
            cout << "Hour: Error" << endl;
        }

        cout << ":";

        /** 3.分钟 */
        int minute = find_minute(c,d);
        if(minute<10 && minute>=0)
        {
            cout << "0" << minute;
        }
        else if(minute>=10 && minute <60)
        {
            cout << minute;
        }
        else
        {
            cout << "Minute: Error" <<endl;
        }

        cout << endl;
    }
    return 0;
}

/**
 *  找到第一个相同的大写字母，对应的大写字母次序
 */
int find_week(string a, string b)
{
    char c = 0;

    for(int i=0; i<a.size()&&i<b.size(); ++i)
    {
        if(a[i]==b[i] && isUpper(a[i]))
        {
            c = a[i];
            break;
        }
    }

    return (int)c - 64;
}

/**
 *  找到第二对相同的字符，转换为小时
 */
int find_hour(string a, string b)
{
    bool find_first = false;
    char c,cc;

    for(int i=0; i<a.size()&&i<b.size(); ++i)
    {
        if(a[i]==b[i])
        {
            c = a[i];
            if(isNumber(c) || isUpper(c))
            {
                // 第一个必须是大写字母
                if(!find_first)
                {
                    if(isUpper(c))
                        find_first = true;
                }
                else
                {
                    cc = c;     // cc即为所需的char
                }
            }
        }
    }

    if(isNumber(cc))
        return (int)(cc-'0');
    else if(isUpper(cc))
        return (int)(cc-'A'+10);
    else
        return -1;
}

int find_minute(string a,string b)
{
    char c;
    for(int i=0; i<a.size()&&i<b.size(); ++i)
    {
        if(a[i]==b[i])
            c=a[i];
        if(isUpper(c) || isLower(c))
        {
            return i;
        }
    }
    return -1;
}

bool isNumber(char c)
{
    if(c>='0' && c<='9')
        return true;
    else
        return false;
}

bool isUpper(char c)
{
    if(c>='A' && c<='Z')
        return true;
    else
        return false;
}

bool isLower(char c)
{
    if(c>='a' && c<='z')
        return true;
    else
        return false;
}




