/**
D. 到底买不买（20）
http://www.patest.cn/contests/pat-b-101-125-1-2015-03-14/D
小红想买些珠子做一串自己喜欢的珠串。
卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。
于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？
如果是，那么告诉她有多少多余的珠子；
如果不是，那么告诉她缺了多少珠子。
为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。

输入格式：
每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：
如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2

*/

/**
    在线通过
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

    hash_map<char,int>  want;       // 想要的<颜色,数量>
    hash_map<char,int>  provided;   // 提供的<颜色,数量>

    while(cin>>str_provided>>str_want)
    {

        bool buy = true;
        int remainder = 0;  // 多余的
        int lack = 0;       // 缺少的

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

        // 依次检查Want里边的元素是否存在于Provided，且数量足够
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
