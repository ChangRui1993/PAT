/**
B. �ڻ����ִ�����Ǯ��20��
������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ ���� ���纣����߹����ģ���ʮ�߸�������(Sickle)��һ����¡(Galleon)����ʮ�Ÿ�����(Knut)��һ�����ɣ������ס������ڣ���������Ӧ���ļ�ǮP����ʵ����ǮA�����������дһ��������������Ӧ�ñ��ҵ���Ǯ��

�����ʽ��
������1���зֱ����P��A����ʽΪ��Galleon.Sickle.Knut���������1���ո�ָ�������Galleon��[0, 107]�����ڵ�������Sickle��[0, 17)�����ڵ�������Knut��[0, 29)�����ڵ�������

�����ʽ��
��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ�������û����Ǯ����ô�����Ӧ���Ǹ�����

��������1��
10.16.27 14.1.28
�������1��
3.2.1
��������2��
14.1.28 10.16.27
�������2��
-3.2.1

*/

/**
    ����ͨ��
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
        int pg,ps,pk,psum;   // ��Ǯ
        int ag,as,ak,asum;   // ʵ��
        int cg,cs,ck,csum;   // ����

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
