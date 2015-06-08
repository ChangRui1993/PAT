/**
D. ��������20��
http://www.patest.cn/contests/pat-b-101-125-1-2015-03-14/D
С������Щ������һ���Լ�ϲ�����鴮��
�����ӵ�̯���кܶമ������ɫ���鴮�����ǲ��ϰ��κ�һ����ɢ������
����С��Ҫ���æ�ж�һ�£�ĳ���������Ƿ������ȫ���Լ���Ҫ�����ӣ�
����ǣ���ô�������ж��ٶ�������ӣ�
������ǣ���ô������ȱ�˶������ӡ�
Ϊ���������������[0-9]��[a-z]��[A-Z]��Χ�ڵ��ַ�����ʾ��ɫ��

�����ʽ��
ÿ���������1������������ÿ�����������ֱ���2�����Ⱥ����̯�����鴮��С���������鴮��������������1000�����ӡ�

�����ʽ��
�������������һ���������Yes���Լ��ж��ٶ�������ӣ����������������һ���������No���Լ�ȱ�˶������ӡ������1���ո�ָ���

��������1��
ppRYYGrrYBR2258
YrR8RrY
�������1��
Yes 8
��������2��
ppRYYGrrYB225
YrR8RrY
�������2��
No 2

*/

/**
    ����ͨ��
    http://www.patest.cn/contests/pat-b-practise/1039
*/


#include <iostream>
#include <vector>
#include <map>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

int main()
{

    string str_want;
    string str_provided;

    hash_map<char,int>  want;       // ��Ҫ��<��ɫ,����>
    hash_map<char,int>  provided;   // �ṩ��<��ɫ,����>

    while(cin>>str_provided>>str_want)
    {

        bool buy = true;
        int remainder = 0;  // �����
        int lack = 0;       // ȱ�ٵ�

        for(unsigned int i=0; i<str_provided.size(); i++)
        {
            provided[str_provided[i]]++;
            remainder++;
        }
        for(unsigned int i=0; i<str_want.size(); i++)
        {
            want[str_want[i]]++;
            remainder--;
        }

        // ���μ��Want��ߵ�Ԫ���Ƿ������Provided���������㹻
        hash_map<char,int>::iterator it;
        for(it=want.begin(); it!=want.end(); it++)
        {
            char color = it->first;
            int num = it->second;

            if(provided[color]<num)
            {
                buy = false;
                lack += num - provided[color];
            }
        }

        if(buy)
            cout << "Yes " << remainder << endl;
        else
            cout << "No " << lack << endl;

    }
    return 0;
}
