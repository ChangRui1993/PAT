/**
A. ����A+B (15)

������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA��
���磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��
������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��
��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0

*/


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{

    char da,db;
    string a,b;

    while(cin>>a>>da>>b>>db){

        string pa="",pb="";

        string::iterator it;
        for(it=a.begin();it!=a.end();it++){
            if((*it)==da){
                pa+=da;
            }
        }
        for(it=b.begin();it!=b.end();it++){
            if((*it)==db){
                pb+=db;
            }
        }

        int pa_ = atoi(pa.c_str());
        int pb_ = atoi(pb.c_str());

        cout << pa_ + pb_ << endl;

    }

    return 0;
}
