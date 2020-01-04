#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> num;

int op[4];
int M = -99999999;
int m = 99999999;

void dfs(int i, int sum) {
    if(i == n){
        M = max(sum,M);
        m = min(sum,m);
        return;
    }
    if(op[0]>0){
        op[0]--;
        dfs(i+1,sum + num[i]);
        op[0]++;
    }
    if(op[1]>0){
        op[1]--;
        dfs(i+1,sum - num[i]);
        op[1]++;
    }
    if(op[2]>0){
        op[2]--;
        dfs(i+1,sum * num[i]);
        op[2]++;
    }
    if(op[3]>0){
        op[3]--;
        dfs(i+1, sum / num[i]);
        op[3]++;
    }
}

int main() {
    cin.tie(0),ios::sync_with_stdio(0);
    
    cin >> n;
    num.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    dfs(1, num[0]);
    cout << M << '\n';
    cout << m << '\n';
}