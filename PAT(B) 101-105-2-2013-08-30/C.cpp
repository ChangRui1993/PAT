/**
C. ������ (20)
��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������

�����ʽ��
������һ���и���M��N������Կո�ָ���

�����ʽ��
�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�

����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>

using namespace std;

bool is_prime(int n){
    // cout << n << " ";
    int sq = (int) sqrt(n) +1;
    for(int i=2;i<sq;i++){
        if(n%i==0){
            // cout << "false" <<endl;
            return false;
        }
    }
    // cout << "true" <<endl;
    return true;
}

int main()
{

    int m,n;

    while(cin>>m>>n)
    {

        /** ���n������ */
        vector<int> primes;
        int i=2;
        while(primes.size()<n){
            if(is_prime(i))
                primes.push_back(i);
            i++;
        }

        /** ������ */
        int cnt = 0;
        for(int j=m-1;j<=n-1;j++){
            if(cnt==10){
                cout << endl;
                cnt = 0;
            }else if(cnt!=0){
                cout << " ";
            }
            cout << primes[j];
            cnt ++;
        }
        cout << endl;

    }

    return 0;

}
