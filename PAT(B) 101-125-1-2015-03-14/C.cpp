/**
C. 统计同成绩学生(20)
本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：
输入在第1行给出不超过105的正整数N，即学生总人数。
随后1行给出N名学生的百分制整数成绩，中间以空格分隔。
最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
*/

/**
    在线通过
    http://www.patest.cn/contests/pat-b-practise/1038
*/

#include <iostream>
#include <vector>
#include <map>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

int main()
{

    int n;
    //map<int,int> marks;  // 成绩
    hash_map<int,int> marks;
    int k;
    vector<int> keys;   // 要查询的分数

    while(cin>>n){
        marks.clear();
        keys.clear();

        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            marks[temp] = marks[temp]+1;
            // cout << "Marks:" <<temp<<",Count:"<<marks[temp]<<endl;
        }

        cin>>k;
        for(int i=0;i<k;i++){
            int temp;
            cin>>temp;
            keys.push_back(temp);
        }

        int siz = keys.size();
        for(int i=0;i<siz;i++){
            cout << marks[keys[i]];
            if(i!=siz-1)
                cout << ' ';
            else
                cout << endl;
        }

    }
    return 0;
}
