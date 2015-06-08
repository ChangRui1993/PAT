/**
E. �м���PAT��25��
�ַ���APPAPT�а������������ʡ�PAT����
���е�һ��PAT�ǵ�2λ(P),��4λ(A),��6λ(T)��
�ڶ���PAT�ǵ�3λ(P),��4λ(A),��6λ(T)��
�ָ����ַ�������һ�������γɶ��ٸ�PAT��

�����ʽ��
����ֻ��һ�У�����һ���ַ��������Ȳ�����105��ֻ����P��A��T������ĸ��

�����ʽ��
��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����

����������
APPAPT

���������
2

*/

/**
    ��ͨ��
    http://www.patest.cn/contests/pat-b-practise/1040
*/
#include <iostream>
#include <string>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

int main()
{

    hash_map<int,int> p_left;   // λ��key������ж��ٸ�P
    hash_map<int,int> t_right;  // λ��key���ұ��ж��ٸ�T
    vector<int> a_pos;          // �ַ����г���A��λ��

    string s;
    while(cin>>s){

        int str_size = s.size();
        int p_count=0, t_count=0;
        int result=0;

        // �������һ�飬��¼P��A����Ϣ
        for(int i=0;i<str_size;++i){
            if(s[i]=='A')
                a_pos.push_back(i);
            else if(s[i]=='P')
                p_count++;
            p_left[i] = p_count;
        }

        // �������һ�ߣ���¼T����Ϣ
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
