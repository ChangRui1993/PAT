/**
C. ͳ��ͬ�ɼ�ѧ��(20)
����Ҫ�����N��ѧ���ĳɼ��������ĳһ����������ѧ�����������

�����ʽ��
�����ڵ�1�и���������105��������N����ѧ����������
���1�и���N��ѧ���İٷ��������ɼ����м��Կո�ָ���
���1�и���Ҫ��ѯ�ķ�������K��������N�����������������K���������м��Կո�ָ���

�����ʽ��
��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�

����������
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
���������
3 2 0
*/

/**
    ����ͨ��
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
    //map<int,int> marks;  // �ɼ�
    hash_map<int,int> marks;
    int k;
    vector<int> keys;   // Ҫ��ѯ�ķ���

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
