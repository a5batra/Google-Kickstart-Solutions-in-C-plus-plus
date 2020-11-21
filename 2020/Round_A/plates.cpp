//
// Created by Ankit Batra on 11/18/20.
//

/** Problem
 * Dr. Patel has N stacks of plates. Each stack contains K plates.
 * Each plate has a positive beauty value, describing how beautiful it looks.
 * Dr. Patel would like to take exactly P plates to use for dinner tonight.
 * If he would like to take a plate in a stack, he must also take all of the plates above it in that stack as well.
 * Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.
 *
 * Input
 * The first line of the input gives the number of test cases, T. T test cases follow.
 * Each test case begins with a line containing the three integers N, K and P. Then, N lines follow.
 * The i-th line contains K integers, describing the beauty values of each stack of plates from top to bottom.
 *
 * Output
 * For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1)
 * and y is the maximum total sum of beauty values that Dr. Patel could pick. */

#include <iostream>
#include <vector>

using std::vector;

const int N = 51;
const int K = 31;
const int P = N * K;

int n, k, p;
int values[N][K], pref[N][K];
int dp[N][P];

int maxBeautyValue(int idx, int taken) {
    if (taken == p) {
        return 0;
    }
    if (idx > n || taken > p) {
        return -1e9;
    }
    if (dp[idx][taken] != -1) return dp[idx][taken];

    int ans = 1e-9;
    for (int i = 0; i <= k; ++i) {
        ans = std::max(ans, pref[idx][i] + maxBeautyValue(idx + 1, taken + i));
    }

    return dp[idx][taken] = ans;
}

int main() {
    int t;
    std::cin >> t;

    int tc = 0;

    while (t--) {
        tc++;
        memset(dp, -1, sizeof(dp));
        std::cin >> n >> k >> p;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                std::cin >> values[i][j];
                pref[i][j] = pref[i][j - 1] + values[i][j];
            }
        }
        int ans = maxBeautyValue(1, 0);
        std::cout << "Case #" << tc << ": " << ans << std::endl;
    }
    return 0;
}