
#include <iostream>
#include <vector>


using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	vector<string> rst;

	while( cin >> s )
	{
		int n;
		cin >> n;

		if( s.size() > 10000 || s.size() < 1 || n<1 || n >10000 )
		{ 
			cerr << "input error!  continue..." << endl; 
			continue;
		}

		vector<int> a(n), b(n);
		for( int i=0; i < n; i++ )
		{
			cin >> a[i];
			cin >> b[i];
		}

		for( int i=0; i < n; i++ )
		{
			if( a[i]>b[i] )
				std::swap( a[i], b[i] );
		} 

		for( int i=0; i < n; i++ )
			for( int i=0; i < n; i++ )
			{
				if( s[a[i]]>s[b[i]] )
					std::swap( s[a[i]], s[b[i]] );
			} 


		rst.push_back(s);

	}

	for(int i=0; i < rst.size(); i++)
		cout << rst[i] << endl;
	return 0;
}