
#include <iostream>
#include <random>

using namespace std;
std::random_device rd;
static default_random_engine e(rd());//生成随机无符号数

int main()
{
	std::vector<int>   ab(10);
	for( auto& a:ab )
	{
		a=5;//u的范围范围便是e生成的随机数范围
	}
	for(auto a:ab)
	{
		cout << a << endl;//u的范围范围便是e生成的随机数范围
	}

  return 0;
}





