#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>>& W, int n) {
    vector<vector<int>> D = W;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (D[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << D[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> W(n, vector<int>(n));

    cout << "Enter the weight matrix (use a large number for infinity): \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> W[i][j];
            if (W[i][j] == 0 && i != j) {
                W[i][j] = INT_MAX;
            }
        }
    }

    floydWarshall(W, n);

    return 0;
}
