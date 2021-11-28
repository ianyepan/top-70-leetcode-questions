class Solution {
 public:
  int getSum(int x, int y) {
    while (y != 0) {
      unsigned int carry = x & y;  // AND: calculate carry
      x = x ^ y;                   // XOR: actual addition for each current position
      y = carry << 1;              // left shift carry
    }
    return x;
  }
};
