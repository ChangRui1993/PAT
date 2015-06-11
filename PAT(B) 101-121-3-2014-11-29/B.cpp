/**
B. 挖掘机技术哪家强(20)
为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：
输入在第1行给出不超过105的正整数N，即参赛人数。
随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：
在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。
题目保证答案唯一，没有并列。

输入样例：
6
3 65
2 80
1 100
2 70
3 40
3 0
输出样例：
2 150
*/

/**
    Accepted
    http://www.patest.cn/contests/pat-b-practise/1032
*/

#include <iostream>
#include <string>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

int main()
{
    int n;
    hash_map<int,int> total;    // 每个学校的总分

    while(cin>>n){
        total.empty();

        for(int i=0;i<n;i++){
            int school, mark;
            cin >> school >> mark;
            total[school] += mark;
        }
        int best_school=-1, best_mark=-1;
        hash_map<int,int>::iterator it;
        for(it=total.begin();it!=total.end();it++){
            if((it->second)>best_mark){
                best_mark = it->second;
                best_school = it->first;
            }
        }

        cout << best_school << " " << best_mark << endl;
    }

    return 0;
}
