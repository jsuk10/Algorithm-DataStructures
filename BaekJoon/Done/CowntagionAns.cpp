#include<iostream>


using namespace std;
int N;
int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<N;++i) {
        int u, v; cin >> u >> v;
        a[u]++; a[v]++;
    }
    ++a[1];
    int ans = N-1;
    for(int i=1;i<=N;++i) {
        int sz = 1;
        while(sz < a[i]) {
            sz *= 2;
            ++ans;
        }
        cout << i << " " << a[i] << " "<<ans <<"\n";
    }
    cout << ans << '\n';
    return 0;
}