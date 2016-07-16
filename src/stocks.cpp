#include <iostream>
#include <vector>
#include <limits.h>
#include <Eigen/Core>

using namespace std;

int maxProfit(vector<int>& prices, int& buy, int& sell);

int maxProfit(vector<int>& prices);

int main(int argc, char const *argv[])
{
	vector<int> prices;
	int tmp;
	while( cin>>tmp )
		prices.push_back(tmp);
	cout << endl;
	// int buy(0), sell(0);

	// int maxprofit = maxProfit(prices,buy,sell);

	// cout << endl << maxprofit << " " << buy << " " << sell << endl;

	int maxprofit = maxProfit(prices);

	cout << endl << maxprofit  << endl;

	return 0;
}

//return profit
int maxProfit(vector<int>& prices, int& buy, int& sell)
{
	// Best Time to Buy and Sell Stock  

	/*Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
	Subscribe to see which companies asked this question*/

	buy = sell = 0;
	if(prices.size()<2)
		return 0;

	int maxprofit(0);
	int local_min = INT_MAX;
	int tmp_buy(-1);
	for(size_t i=0; i< prices.size(); i++)
	{
			if( prices[i] < local_min )
			{
				local_min = prices[i];
				tmp_buy = i;
			}
			else
			{
				maxprofit = max( maxprofit, prices[i] - local_min );
				sell = i;
				buy = tmp_buy;
			}
	}
	return maxprofit;
}

int maxProfit(vector<int>& prices) 
{
    
    if(prices.empty())
    // if(prices.size()<2)
        return 0;
 
    vector<int> preprofit(prices.size(),0),backprofit(prices.size(),0);
    
    int min = INT_MAX;
    int pre(0);
    for(size_t i=0; i< prices.size();i++)
    {
        if(prices[i]<min)
            min = prices[i];
        else
            pre = max(pre, prices[i]-min);
        preprofit[i] = pre;
    }

    int back = 0;
    int m = INT_MIN;
    for(int i = prices.size()-1; i>=0; i--)
    {
        if(prices[i]>m)
        {
            m = prices[i];
        }
        else
            back = max(back, m - prices[i]);
        backprofit[i] = back;
    }        
    for(auto& p: backprofit)
			cout <<  p << endl;
    int maxprofit(0);
    for(size_t i=0; i< prices.size();i++)
    {
        maxprofit = max(maxprofit, preprofit[i]+backprofit[i] );
    }
    return maxprofit;
}
