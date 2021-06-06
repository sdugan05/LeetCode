#include <iostream>
#include <vector>
#include <cmath>

// Done

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> vec_a = nums1;
    std::vector<int> vec_b = nums2;

    int total_length = nums1.size() + nums2.size();
    int half_length = total_length / 2;

    // Make sure vec_a is the smaller array
    if(vec_a.size() > vec_b.size()) {
        std::vector<int> temp_vec_c = vec_a;
        vec_a = vec_b;
        vec_b = temp_vec_c;
    }

    int left = 0;
    int right = vec_a.size() - 1;
    while (true) {
        // Splitting both arrays into two parts; The left two parts, if merged make up the left half of a combined sorted array 
        int a_part_1 = floor(left + (right - left) / 2.0);
        float b_part_1 = half_length - a_part_1 - 2;

        int a_left;
        int a_right;
        int b_left;
        int b_right;

        if (a_part_1 >= 0) {
            a_left = vec_a.at(a_part_1);
        } else {
            a_left = -10000;
        }

        if (a_part_1 + 1 < vec_a.size()) {
            a_right = vec_a.at(a_part_1 + 1);
        } else {
            a_right = 10000;
        }


        if (b_part_1 >= 0) {
            b_left = vec_b.at(b_part_1);
        } else {
            b_left = -10000;
        }

        if (b_part_1 + 1 < vec_b.size()) {
            b_right = vec_b.at(b_part_1 + 1);
        } else {
            b_right = 10000;
        }

        std::cout << a_left << std::endl;
        std::cout << a_right << std::endl;
        std::cout << b_left << std::endl;
        std::cout << b_right << std::endl;

        // Check if the split is correct
        if (a_left <= b_right && b_left <= a_right) {
            // If the total length is odd
            if (total_length % 2 == 1) {
                // Return the smaller of the two rights
                if (a_right < b_right) {
                    return a_right;
                } else {
                    return b_right;
                }
            }
            // If even
            int max_left;
            if (a_left > b_left) {
                max_left = a_left;
            } else {
                max_left = b_left;
            }
            
            int min_right;
            if (a_right < b_right) {
                min_right = a_right;
            } else {
                min_right = b_right;
            }
            
            int avg = (max_left + min_right) / 2;
            return avg;
        } else if (a_left > b_right) {
            right = a_part_1 - 1;
        } else {
            left = a_part_1 + 1;
        }
    }
    // Never reached because given valid input, the loop will always return
    return 0;
}

int main() {
    // Test case
    std::vector<int> input_a = {1, 3};
    
    std::vector<int> input_b = {2};
    // 1, 1, 2, 2, 2, 3, 3, 5, 6

    std::cout << findMedianSortedArrays(input_a, input_b) << std::endl;

    return 0;
}
