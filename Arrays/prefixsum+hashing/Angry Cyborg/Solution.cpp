// Problem Link : https://www.codechef.com/practice/course/arrays-strings-advanced/ARRAYSP06/problems/AGCY
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector < int > vt(n+1, 0);
        while (q--) {
            int l, r;
            cin >> l >> r;
            vt[l] += 1;
            if (r + 1 < n+1) {
                vt[r + 1] -= (r - l + 2);
                if (r + 2 < n+1) vt[r + 2] += (r - l + 1);
            }
        }
        for (int i = 1; i < n+1; i++) vt[i] += vt[i - 1];
        for (int i = 1; i < n+1; i++) vt[i] += vt[i - 1];
        for (int i = 1; i < n+1; i++) cout << vt[i] << " ";
        cout << "\n";

    }
}
