#include <iostream>

using namespace std;

class Solution {
  public:
    int minFlips(int a, int b, int c) {
      int sum = a + b;

      while (sum != c) {
        if (sum < c) {
          
        }

        if (sum > c) {

        }
      }
    }

    int flipBit(int num, int index) {
      num ^= 1UL << index;
      return num;
    }
};

int main() {
  Solution sol;

  cout << sol.flipBit(5, 3) << endl;
}

