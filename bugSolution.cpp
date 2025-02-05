#include <iostream>
#include <vector>
#include <chrono>

int main() {
  // Using std::vector<bool>
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<bool> boolVector(1000000); 
  for (size_t i = 0; i < boolVector.size(); ++i) {
    boolVector[i] = (i % 2 == 0); 
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "std::vector<bool> time: " << duration.count() << " microseconds" << std::endl;

  // Using std::vector<char> for bit manipulation (more efficient alternative)
  start = std::chrono::high_resolution_clock::now();
  std::vector<char> charVector(1000000 / 8 + 1); // Each char holds 8 bits
  for (size_t i = 0; i < 1000000; ++i) {
    if (i % 2 == 0) {
      charVector[i / 8] |= (1 << (i % 8));
    }
  }
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "std::vector<char> time: " << duration.count() << " microseconds" << std::endl;

  return 0;
}
