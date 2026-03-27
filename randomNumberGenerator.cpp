#include <iostream>
#include <random>  // Essential for modern random numbers
#include <vector>

using namespace std;
void generateRandomNumbers(int n, int l, int r) {
    // 1. Seed the random number engine using hardware entropy
    std::random_device rd;

    // 2. Choose a generator (Mersenne Twister is the standard go-to)
    std::mt19937 gen(rd());

    // 3. Define the distribution range [l, r] (inclusive)
    std::uniform_int_distribution<> dis(l, r);

    std::cout << "Generating " << n << " numbers between " << l << " and " << r << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << dis(gen) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 5, l = 1, r = 100;
    cin >> n >> l >> r;
    generateRandomNumbers(n, l, r);
    return 0;
}