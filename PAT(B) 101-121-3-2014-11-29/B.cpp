/**
B. �ھ�������ļ�ǿ(20)
Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��
�����ڵ�1�и���������105��������N��������������
���N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ���1��ʼ������ţ�����������ɼ����ٷ��ƣ����м��Կո�ָ���

�����ʽ��
��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ���
��Ŀ��֤��Ψһ��û�в��С�

����������
6
3 65
2 80
1 100
2 70
3 40
3 0
���������
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
    hash_map<int,int> total;    // ÿ��ѧУ���ܷ�

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
