#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include "vector.h"

namespace alg {

  template<typename T>
  void merge(std::vector<T>& input, uint32_t start, uint32_t middle, uint32_t end) { 
    std::vector<T> left(input.begin() + start, input.begin() + middle); 
    std::vector<T> right(input.begin() + middle, input.begin() + end); 
    uint32_t j = 0; 
    uint32_t k = start; 
    for (uint32_t i = 0; i < left.size(); ++i) { 
      while (right[j] < left[i] && j < right.size()) { 
        input[k] = right[j]; 
        k++; 
        j++; 
      }
      input[k] = left[i]; 
      k++; 
    } 
  } // voide merge
  
  template<typename T> 
  void merge(std::vector<T>& input,
             std::vector<uint32_t>& index,
             uint32_t start,
             uint32_t middle,
             uint32_t end) {
    std::vector<T> left(input.begin() + start, input.begin() + middle); 
    std::vector<T> right(input.begin() + middle, input.begin() + end); 
    std::vector<uint32_t> index_l(index.begin() + start, index.begin() + middle); 
    std::vector<uint32_t> index_r(index.begin() + middle, index.begin() + end); 
    uint32_t j = 0; 
    uint32_t k = start; 
    for (uint32_t i = 0; i < left.size(); ++i) { 
      while (right[j] < left[i] && j < right.size()) { 
        input[k] = right[j]; 
        index[k] = index_r[j]; 
        k++; 
        j++; 
      }
      input[k] = left[i]; 
      index[k] = index_l[i]; 
      k++; 
    }
  } // void merge

  template<typename T>
  void mergesort(std::vector<T>& input, uint32_t start=0, uint32_t end=-1) { 
    if (end == -1) { 
      end = input.size(); 
    }
    if (start >= end - 1) { 
      return;  
    }
    uint32_t middle = start + (end - start) / 2; 
    mergesort(input, start, middle); 
    mergesort(input, middle, end); 
    merge(input, start, middle, end); 
  } // void mergesort

  template<typename T>
  void mergesort(std::vector<T>& input, 
                 std::vector<uint32_t>& index, 
                 uint32_t start=0, 
                 uint32_t end=-1) {
    if (end == -1) { 
      end = input.size(); 
    }
    if (start >= end - 1) { 
      return; 
    }
    uint32_t middle = start + (end - start) / 2; 
    mergesort(input, index, start, middle); 
    mergesort(input, index, middle, end); 
    merge(input, index, start, middle, end); 
  }

  template<typename T>
  int binarySearch(std::vector<T> input, T target, uint32_t start=0, uint32_t end=-1, const bool sorted=true) {
    if (!sorted) { 
      mergesort(input);  
    }
    if (end == -1) { 
      end = input.size(); 
    } 
    uint32_t i = start + (end - start) / 2; 
    if (i == start) { 
      if (input[i] == target) { 
        return i; 
      }
      else {
        return -1; 
      }
    }
    if (input[i] > target) { 
      return binarySearch(input, target, start, i);  
    }
    else if (input[i] < target) { 
      return binarySearch(input, target, i, end); 
    }
    else { 
      return i; 
    }

  } // binarySearch
} // namespace alg



#endif // ALGORITHM_H
