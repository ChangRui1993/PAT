/**
A. �������֤(15)
һ���Ϸ������֤������17λ���������ڱ�ź�˳���ż�1λУ������ɡ�У����ļ���������£�

���ȶ�ǰ17λ���ּ�Ȩ��ͣ�Ȩ�ط���Ϊ��{7��9��10��5��8��4��2��1��6��3��7��9��10��5��8��4��2}��
Ȼ�󽫼���ĺͶ�11ȡģ�õ�ֵZ��
��������¹�ϵ��ӦZֵ��У����M��ֵ��
Z��0 1 2 3 4 5 6 7 8 9 10
M��1 0 X 9 8 7 6 5 4 3 2

���ڸ���һЩ���֤���룬������֤У�������Ч�ԣ�
�����������ĺ��롣

�����ʽ��

�����һ�и���������N��<= 100������������֤����ĸ�����
���N�У�ÿ�и���1��18λ���֤���롣

�����ʽ��

���������˳��ÿ�����1������������֤���롣
���ﲢ������ǰ17λ�Ƿ����ֻ���ǰ17λ�Ƿ�ȫΪ���������1λУ�������׼ȷ��
������к��붼�������������All passed����

��������1��
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
�������1��
12010X198901011234
110108196711301866
37070419881216001X
��������2��
2
320124198808240056
110108196711301862
�������2��
All passed
*/

/**
    Accepted
    http://www.patest.cn/contests/pat-b-practise/1031
*/

#include <iostream>
#include <string>
#include <hash_map>
//#include <cstdio>
//#include <cstdlib>

using namespace std;
using namespace __gnu_cxx;

int weight[]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[]= {'1','0','X','9','8','7','6','5','4','3','2'};

bool check_legal(string input);
char get_verify_code(string s);
char get_last(string s);

int main()
{

    //freopen("D:\input.txt","r",stdin);

    int n;
    vector<string> inputs;

    while(cin>>n)
    {
        inputs.clear();
        bool all_passed = true;

        // ��������
        for(int i=0; i<n; i++)
        {
            string temp;
            cin >> temp;
            inputs.push_back(temp);
        }
        // 1. ���μ���ʽ�Ϸ���ǰn-1λΪ���֣���false�����
        // 2. ���μ��У������Ч�ԣ���false�����
        // 3. ��all passed�������
        for(unsigned int i=0; i<inputs.size(); i++)
        {
            if(!check_legal(inputs[i]))
            {
                cout << inputs[i] << endl;
                continue;
            }

            char verify = get_verify_code(inputs[i]);
            char last = get_last(inputs[i]);

            if(verify!=last)
            {
                cout << inputs[i] << endl;
                all_passed = false;
            }
        }

        if(all_passed)
            cout << "All passed" << endl;

    }

    return 0;
}

bool check_legal(string input)
{
    for(unsigned int i=0; i<input.size()-1;i++)
    {
        if(input[i]<'0' || input[i]>'9')
            return false;
    }
    return true;
}

char get_verify_code(string input)
{
    string s = input.substr(0,input.size()-1);
    int sum = 0;
    for(unsigned int i=0; i<s.size(); i++)
    {
        sum += weight[i] * (s[i]-'0');
    }
    sum %= 11;
    return m[sum];
}

char get_last(string input)
{
    int pos = input.size()-1;
    return input[pos];
}
