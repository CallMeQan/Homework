#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Function for matrix multiplication
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += ((A[i][k] % MOD) * (B[k][j] % MOD)) % MOD;
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

// Function for matrix exponentiation
vector<vector<int>> matrixExponentiation(const vector<vector<int>>& M, int exponent) {
    if (exponent == 0) {
        int size = M.size();
        vector<vector<int>> identity(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            identity[i][i] = 1;
        }
        return identity;
    }
    if (exponent % 2 == 1) {
        return matrixMultiply(M, matrixExponentiation(M, exponent - 1));
    }
    vector<vector<int>> halfExponent = matrixExponentiation(M, exponent / 2);
    return matrixMultiply(halfExponent, halfExponent);
}

int calculateCoconutIslands(int N, int K, const vector<int>& a) {
    vector<vector<int>> M(K, vector<int>(K, 0));

    // Construct the matrix M
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (i == 0 && j < K - 1) {
                M[i][j] = a[K - j - 1];
            } else if (j == i - 1) {
                M[i][j] = 1;
            }
        }
    }

    // Raise M to the power of (N - K)
    vector<vector<int>> M_power = matrixExponentiation(M, N - K);

    // Multiply M_power with the initial sequence a
    vector<int> result(K, 0);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            result[i] += ((M_power[i][j] % MOD) * (a[j] % MOD)) % MOD;
            result[i] %= MOD;
        }
    }

    return result[K - 1];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }

    int count = calculateCoconutIslands(N, K, a);

    cout << count << endl;

    return 0;
}