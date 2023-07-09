#include <iostream>
#include <stack>

using namespace std;
stack<pair<int, int>> TowerStack;

int main()
{
	int TowerCount;
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> TowerCount;
	
	for(int i = 0; i < TowerCount; i++) 
	{
		int TowerNumber;
		cin >> TowerNumber;

		while (!TowerStack.empty())
		{
			if (TowerStack.top().second > TowerNumber) {
				cout << TowerStack.top().first << " ";
				break;
			}
			TowerStack.pop();
		}
		//만약에 찾는 것을 실패했을 경우.
		if (TowerStack.empty()) {
			
			cout << 0 << " ";
			
		}
		TowerStack.push(make_pair(i + 1, TowerNumber));
	}

}

