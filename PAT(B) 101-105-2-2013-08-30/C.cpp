/**
C. 数素数 (20)
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。

输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
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

        /** 求出n个素数 */
        vector<int> primes;
        int i=2;
        while(primes.size()<n){
            if(is_prime(i))
                primes.push_back(i);
            i++;
        }

        /** 输出结果 */
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
