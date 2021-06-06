#include <iostream>

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Done

int climbStairs(int n) {
    switch (n)
    {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            return 1;
        }
        case 2:
        {
            return 2;
        }
    }

    int prev = 2;
    int prev_prev = 1;
    int all = 0;

    for (int i = 2; i < n; i++)
    {
        all = prev + prev_prev;
        prev_prev = prev;
        prev = all;
    }

    return all;
}

int main() {
    int test_case = 3;
    // Expected output: 3
    // 1. 1 step + 1 step + 1 step
    // 2. 1 step + 2 steps
    // 3. 2 steps + 1 step
    // Actual output:

    int result = climbStairs(test_case);
    
    std::cout << result << std::endl;

    return 0;
}
