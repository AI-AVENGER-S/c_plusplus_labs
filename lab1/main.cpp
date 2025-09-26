#include <iostream>
#include "include/closest_to_bound.h"

using ll = long long;

int main()
{
  ll divider, bound;
  std::cout << "enter divider:";
  std::cin  >> divider;
  std::cout << "enter bound:";
  std::cin  >> bound;


  std::cout << "result: " << closest_to_bound(divider, bound) << std::endl;

  return 0;
}