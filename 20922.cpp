#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	int k;
	int n;
	unordered_map<int, int> IntCounter;
	bool InBound = false;
	int FrontCounter = 0;
	int BackCounter = 0;
	int Member = 0;
	vector<int> numberVector;
	int MaximumLength = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		numberVector.push_back(number);
	}
	int Distance = 0;
	while (BackCounter < n)
	{
		if (!InBound) {
			if (++IntCounter[numberVector[BackCounter]] <= k)
			{
				BackCounter++;
				Distance++;
			}
			else {
				InBound = true;
			}
		}
		else
		{
			if (IntCounter[numberVector[BackCounter]] > k)
			{
				IntCounter[numberVector[FrontCounter]]--;
				FrontCounter++;
				Distance--;
			}
			else {
				InBound = false;
				BackCounter++;
				Distance++;
			}
		}
		MaximumLength = max(MaximumLength, Distance);
	}
	printf("%d", MaximumLength);

}
