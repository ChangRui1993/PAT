/**
B. 在霍格沃茨找零钱（20）
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1

*/

/**
    在线通过
    http://www.patest.cn/contests/pat-b-practise/1037
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int get_g(string s);
int get_s(string s);
int get_k(string s);

int main()
{

    string p,a;
    while(cin>>p>>a)
    {
        int pg,ps,pk,psum;   // 价钱
        int ag,as,ak,asum;   // 实付
        int cg,cs,ck,csum;   // 找零

        pg = get_g(p);
        ps = get_s(p);
        pk = get_k(p);

        ag = get_g(a);
        as = get_s(a);
        ak = get_k(a);

        psum = 29*17*pg + 29*ps + pk;
        asum = 29*17*ag + 29*as + ak;

        csum = asum - psum;
        cg = csum / (29*17);
        cs = (csum % (29*17))/29;
        ck = (csum % (29*17))%29;

        if(cs<0) cs = -cs;
        if(ck<0) ck = -ck;

        cout << cg << '.' << cs << '.' << ck << endl;

    }
    return 0;
}

int get_g(string s)
{
    int pos;
    pos = s.find('.');
    return atoi(s.substr(0,pos).c_str());
}

int get_s(string s)
{
    int pos;
    pos = s.find('.');
    s = s.substr(pos+1,s.size()-pos-1);
    pos = s.find('.');
    return atoi(s.substr(0,pos).c_str());
}
int get_k(string s)
{
    int pos;
    pos = s.find('.');
    s = s.substr(pos+1,s.size()-pos-1);
    pos = s.find('.');
    s = s.substr(pos+1,s.size()-pos-1);
    pos = s.find('.');
    return atoi(s.substr(0,pos).c_str());
}
