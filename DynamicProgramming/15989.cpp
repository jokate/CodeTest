#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> numVector;
int dp[10001];

int main()
{
	//각각의 수는 각자마다 1로 구현할 수 있다는 전제
	fill_n(dp, 10001, 1);

	int num;
	cin >> num;

	//2로 뺼 수 있을시 (n-2) 만큼 표현이 가능.
	for(int i = 2; i < 10001; i++) 
	{
		dp[i] += dp[i - 2];
	}
	//3으로 표현 가능 시 (n-3)의 경우의 수 만큼 표현 가능
	for (int i = 3; i < 10001; i++)
	{
		dp[i] += dp[i - 3];
	}

	for(int i = 0; i < num; i++) 
	{
		int Samplenum;
		cin >> Samplenum;
		cout << dp[Samplenum] << endl;
	}
}

