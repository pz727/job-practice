
#include <iostream>
#include <vector>


using namespace std;
static vector< vector< int > > vh;
void add( vector<int> & v)
{ 
	vh.push_back(v);
}

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	 
	add(v);
	v[0] = 5;

	for(auto& v1:v)
			std::cout << v1 << std::endl;

	for(auto& v2:vh)
		for(auto& v3:v2)
			std::cout << v3 << std::endl;


  return 0;
}





