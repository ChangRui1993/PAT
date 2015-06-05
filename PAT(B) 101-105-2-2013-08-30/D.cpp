/**
D. ����Ħ˹��Լ�� (20)
����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04����
��Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ�
��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ�
�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��
������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��
��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

���������
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

        /** 1.���� */
        int w = find_week(a,b);
        cout << week[w] << " ";

        /** 2.Сʱ */
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

        /** 3.���� */
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
 *  �ҵ���һ����ͬ�Ĵ�д��ĸ����Ӧ�Ĵ�д��ĸ����
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
 *  �ҵ��ڶ�����ͬ���ַ���ת��ΪСʱ
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
                // ��һ�������Ǵ�д��ĸ
                if(!find_first)
                {
                    if(isUpper(c))
                        find_first = true;
                }
                else
                {
                    cc = c;     // cc��Ϊ�����char
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




