#include <iostream>
#include <vector>
#include "../include/vector.h"

class Solution { 
  public: 
    double med(std::vector<int>& num1,
        std::vector<int>& num2, 
        uint32_t m1, 
        uint32_t m2, 
        uint32_t n1,
        uint32_t n2) { 
      std::cout << "m1: " << m1 << std::endl; 
      std::cout << "m2: " << m2 << std::endl;
      std::cout << "n1: " << n1 << std::endl; 
      std::cout << "n2: " << n2 << std::endl; 

      uint32_t m3 = m1 + (m2 - m1) / 2; 
      uint32_t n3 = n1 + (n2 - n1) / 2;

      std::cout << "m3: " << m3 << std::endl; 
      std::cout << "n3: " << n3 << std::endl; 
      std::cout << "=================" << std::endl; 
// 
//       if (m3 > n1) { 
//         n2 - n1 + 
//       }
      return 3.2;   
    }
    double findMedianSortedArrays(std::vector<int>& num1, std::vector<int>& num2) { 
      uint32_t m = num1.size() / 2; 
      uint32_t n = num2.size() / 2; 

      if (num1[m] > num2[n]) { 
        med(num1, num2, 0, m, n, num2.size()); 
        std::cout << "state1" << std::endl; 
      }
      else if (num1[m] < num2[n]) { 
        med(num2, num1, 0, n, m, num1.size()); 
        std::cout << "state2" << std::endl; 
      }
      else {
        return num1[m]; 
        std::cout << "state3" << std::endl; 
      }
      return 2.2; 
    }
}; // Solution



int main() {

  // define initiall variables
  std::vector<int> num1 {1, 2, 3, 4, 5, 6, 7, 1024, 2001, 2002, 2003, 2004, 2005, 2006, 2007}; 
  std::vector<int> num2 {1, 2, 3, 4, 5, 6, 7, 512, 513, 514, 515, 516, 517, 518, 519}; 
  Solution sol; 

  // main process

  vec::print(num1, "num1"); 
  vec::print(num2, "num2"); 
  std::cout << "output: " << sol.findMedianSortedArrays(num1, num2) << std::endl; 

  return 0; 
}
