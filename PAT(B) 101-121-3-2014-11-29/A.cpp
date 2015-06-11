/**
A. 查验身份证(15)
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；
然后将计算的和对11取模得到值Z；
最后按照以下关系对应Z值与校验码M的值：
Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2

现在给定一些身份证号码，请你验证校验码的有效性，
并输出有问题的号码。

输入格式：

输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。
随后N行，每行给出1个18位身份证号码。

输出格式：

按照输入的顺序每行输出1个有问题的身份证号码。
这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。
如果所有号码都正常，则输出“All passed”。

输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
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

        // 输入数据
        for(int i=0; i<n; i++)
        {
            string temp;
            cin >> temp;
            inputs.push_back(temp);
        }
        // 1. 依次检查格式合法，前n-1位为数字，若false则输出
        // 2. 依次检查校验结果有效性，若false则输出
        // 3. 若all passed，则输出
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
