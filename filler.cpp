#include <fstream>

using namespace std;

int main () {
  ofstream binary;
  char buffer[4096] = {0};
  binary.open("zeroes.bin", ios::out | ios::binary);
  binary.write(buffer, 4096);
  binary.close();

  for (char & ele : buffer) ele = static_cast<char>(255);
  binary.open("ffoes.bin", ios::out | ios::binary);
  binary.write(buffer, 4096);
  binary.close();

  return 0;
}