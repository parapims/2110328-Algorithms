#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double W, N;
    cin >> W >> N;

    vector<vector<double>> v(N, vector<double>(3, 0));

    for (int i = 0; i < N; i++) {
        cin >> v[i][1];
    }

    for (int i = 0; i < N; i++) {
        cin >> v[i][2];
    }

    for (int i = 0; i < v.size(); i++) {
        v[i][0] = (v[i][1] / v[i][2]);
    }

    sort(v.rbegin(), v.rend());

    double price = 0;

    for (int i = 0; i < v.size(); i++) {
        if (W > 0) {
            if (v[i][2] <= W) {
                price += v[i][1];
                W -= v[i][2];
            } else {
                price += (v[i][0]) * W;
                break;
            }
        }
    }

    cout << fixed << setprecision(4) << price << endl;
    return 0;
}
