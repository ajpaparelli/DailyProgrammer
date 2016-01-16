#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

const double mut = 0.005;
const int samples = 50;

string rand_str(const int length)
{
	string s = "";
	static const char alphabet[] = 
	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstubwxyz!@#$%^&*(){}[]|\\-=.,?/`~<> ";

	for(int i = 0; i < length; i++)
	{
		s = s + alphabet[ rand() % (sizeof(alphabet)-1)];
	}
	
	return s;
}

int fitness(const string s1, const string s2)
{
	int fit = 0;
	for(int i = 0; i < s1.length(); i++)
		fit = fit + abs(int(s1[i]) - int(s2[i]));
	
	return fit;
}

//add propegate function
//add mutate function

int main()
{
	string base = "Hello World";
	string init_list[samples];
	int best_fit = 99999;
	int last_fit = 0;
	for(int i = 0; i<samples; i++)
		init_list[i] = rand_str(base.length());

	for(int i = 0; i<samples; i++)
	{
		last_fit = fitness(base, init_list[i]);
		cout << init_list[i] << " : " << last_fit << endl;
		best_fit = (last_fit < best_fit) ? last_fit : best_fit;
	}	
	cout << best_fit << endl;
	return 0;
}
