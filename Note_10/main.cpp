#include "message.h"
#include "cal_add.h"
#include "cal_substract.h"

int main() {
  int a = 1;
  int b = 2;
  auto c = Add(a , b);
  Message message;
  message.Print(std::to_string(c));
  return 0;
}