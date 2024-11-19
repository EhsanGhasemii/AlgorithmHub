#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#include <cstdint>
#include <numeric>
#include <iomanip>

namespace vec {

  template<typename T>
  void print(std::vector<T> input, std::string name="-") {
    std::cout << name << ": ["; 
    for (uint32_t i = 0; i < input.size(); ++i) { 
      std::cout << std::fixed << std::setprecision(8) << input[i];
      if (i < input.size() - 1) { 
        std::cout << ", "; 
      } 
    }
    std::cout << "]" << std::endl; 
  } // void print

  template<typename T>
  void print(std::vector<std::vector<T>> input, std::string name="-") {
    std::cout << name << ": ["; 
    for (uint32_t i = 0; i < input.size(); ++i) { 
      std::cout << "["; 
      for (uint32_t j = 0; j < input[i].size(); ++j) { 
        std::cout << input[i][j]; 
        if (j < input[i].size() - 1) { 
          std::cout << ", "; 
        }
      } // iterate over j
      std::cout << "]"; 
      if (i < input.size() - 1) { 
        std::cout << std::endl; 
      }
    } // iterate over i
    std::cout << "]" << std::endl; 
  } // void print

  template<typename T> 
  std::vector<uint32_t> index(std::vector<T> input) { 
    std::vector<uint32_t> output(input.size()); 
    std::iota(output.begin(), output.end(), 0); 
    return output; 
  }
} // namespace vec  



#endif
