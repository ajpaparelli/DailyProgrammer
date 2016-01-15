#include<iostream>
#include<vector>
using namespace std;

int main() {
double input;
int min, max;
int lastbuy, maxpfbuy, maxpfsell;
vector<double> vec;

cin >> input;
while(input != -1)
{
vec.push_back(input);

cin >> input;
}

lastbuy = maxpfbuy = maxpfsell = 0;

if(vec.size() > 0)
{
	min = 0;
	max = 0;
	for(int i = 1; i < vec.size(); i++)
	{
		if(vec.at(min) > vec.at(i))
		{					  
			min = i;			
			lastbuy = i;
			max = i;
		}
		else if((vec.at(i) > vec.at(max)) && (lastbuy+1 != i))
		{			
			max = i;
			if((vec.at(max) - vec.at(min)) > (vec.at(maxpfsell) - vec.at(maxpfbuy)))
			{
				maxpfsell = max;
				maxpfbuy = min;
			}
		}
	}
}
cout << vec.at(maxpfbuy) << " " << vec.at(maxpfsell) << endl;
return 0;
}
