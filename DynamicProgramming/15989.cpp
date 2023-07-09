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
	//������ ���� ���ڸ��� 1�� ������ �� �ִٴ� ����
	fill_n(dp, 10001, 1);

	int num;
	cin >> num;

	//2�� �E �� ������ (n-2) ��ŭ ǥ���� ����.
	for(int i = 2; i < 10001; i++) 
	{
		dp[i] += dp[i - 2];
	}
	//3���� ǥ�� ���� �� (n-3)�� ����� �� ��ŭ ǥ�� ����
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

