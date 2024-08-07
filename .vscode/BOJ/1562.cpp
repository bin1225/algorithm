#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX 1000000000
using namespace std;

int N;
long long DP[101][11][1024];
void Solve() {
    cin>>N;

    for(int i=1; i<10; i++){
        DP[1][i][(1<<i)] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                int mask = k | (1<<j);
                if(j>0) DP[i][j][mask] += (DP[i-1][j-1][k]%MAX); 
                if(j<9) DP[i][j][mask] += (DP[i-1][j+1][k]%MAX);
                DP[i][j][mask] %= MAX;
            } 
        }
    }

    long long ans = 0;
    for(int i=0; i<10; i++){
        ans+= (DP[N][i][1023]%MAX);
    }

    cout<<ans%MAX;


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}