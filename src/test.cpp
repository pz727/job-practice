
#include <iostream>
#include <vector>
// #include <stdlib.h>
#include <memory>
#include <math.h>
#include <algorithm>

using namespace std;
void foo(int* p)
{
std::cout << *p << std::endl;
}


void bar(std::shared_ptr<int> p)
{
++(*p);
}

int main()
{
	std::vector<int> v;
	// v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	 
	std::for_each(std::begin(v), std::end(v), [](int n) {std::cout << n << std::endl;});
	 
	auto is_odd = [](int n) {return n%2==1;};
	auto pos = std::find_if(std::begin(v), std::end(v), is_odd);
	if(pos != std::end(v))
	std::cout << *pos << std::endl;

  return 0;
}





