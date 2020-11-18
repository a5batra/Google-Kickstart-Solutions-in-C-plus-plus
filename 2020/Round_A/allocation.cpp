//
// Created by ankitb on 11/17/20.
//

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int numHouses(vector<int>& nums, int& amount) {
    sort(nums.begin(), nums.end());
    int maxHouses = 0;

    for (int num : nums) {
        if (amount > num) {
            maxHouses++;
            amount -= num;
        }
    }
    return maxHouses;
}

int main() {
    int T;
    int N, B;
    int price = 0;
    std::cin >> T;

    vector<int> nums;

    int maxHouses = 0;
    int i = 1;
    int temp;

    while (--T) {
        std::cin >> N >> B;
        for (int i = 0; i < N; ++i) {
            std::cin >> temp;
            nums.push_back(temp);
        }
        maxHouses = numHouses(nums, B);
        std::cout << "Case #" << i << ": " << maxHouses;
        i++;
        nums.clear();
        maxHouses = 0;

    }
    return 0;
}