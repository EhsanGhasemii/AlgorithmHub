#include <iostream>
#include "../include/algorithm.h"
#include "../include/vector.h"
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>

class Solution { // O(n^2) 
  public: 
    std::vector<int> twoSum(std::vector<int>& nums, int target) { 
      for (uint32_t i = 0; i < nums.size(); ++i) { 
        for (uint32_t j = i + 1; j < nums.size(); ++j) {
          if (nums[i] + nums[j] == target) { 
            return {static_cast<int>(i), static_cast<int>(j)}; 
          }
        }
      }
      return {}; 
    } // twoSum
}; // class Solution

class Solution2 { // O(nlog(n)) - it does not work 
  public: 
    std::vector<uint32_t> twoSum(std::vector<int>& nums, int target) { 
      std::vector<uint32_t> index = vec::index(nums); 
      alg::mergesort(nums, index); 
      for (uint32_t i = 0; i < nums.size(); ++i) { 
        int second = alg::binarySearch(nums, target - nums[i]); 
        if (second != -1 && second != i) {
          if (index[i] > index[second]) {
            std::swap(index[i], index[second]); 
          }
          return {index[i], index[second]}; 
        }
      }
      return {}; 
    } // twoSum
}; // class Solution2



int main() { 

  // define necessory variables
  std::vector<int> input {9, 18, 7, 3, 22, 12, 1, 14}; 
  Solution sol; 
  int target = 13; 

  // main process
  std::vector<int> output = sol.twoSum(input, target); 
  

  // print results
  vec::print(input, "input"); 
  vec::print(output, "output"); 

  return 0; 
}
