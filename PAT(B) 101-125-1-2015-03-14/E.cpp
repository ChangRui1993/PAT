/**
E. 有几个PAT（25）
字符串APPAPT中包含了两个单词“PAT”，
其中第一个PAT是第2位(P),第4位(A),第6位(T)；
第二个PAT是第3位(P),第4位(A),第6位(T)。
现给定字符串，问一共可以形成多少个PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT

输出样例：
2

*/

/**
    已通过
    http://www.patest.cn/contests/pat-b-practise/1040
*/
#include <iostream>
#include <string>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

int main()
{

    hash_map<int,int> p_left;   // 位置key的左边有多少个P
    hash_map<int,int> t_right;  // 位置key的右边有多少个T
    vector<int> a_pos;          // 字符串中出现A的位置

    string s;
    while(cin>>s){

        int str_size = s.size();
        int p_count=0, t_count=0;
        int result=0;

        // 正序遍历一遍，记录P和A的信息
        for(int i=0;i<str_size;++i){
            if(s[i]=='A')
                a_pos.push_back(i);
            else if(s[i]=='P')
                p_count++;
            p_left[i] = p_count;
        }

        // 逆序遍历一边，记录T的信息
        for(int i=str_size-1;i>-1;--i){
            if(s[i]=='T')
                t_count++;
            t_right[i] = t_count;
        }

        int vec_size = a_pos.size();
        for(int i=0;i<vec_size;++i){
            int a = a_pos[i];
            result += p_left[a]*t_right[a];
            result %= 1000000007;
        }

        cout << result << endl;
    }

    return 0;
}
