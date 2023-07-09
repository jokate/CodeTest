#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int SisLocation;
int Time = 0;
int AnswerTime;
void Tree();
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> LocationTimeQueue;
bool visited[100001];

void WalkBackward(pair<int, int> LocationTime) {
	int AfterLocation = LocationTime.second - 1;
	if (AfterLocation >= 0 && !visited[AfterLocation]) {
		visited[AfterLocation] = true;
		LocationTimeQueue.push(pair<int, int>(LocationTime.first + 1, AfterLocation));
	}
}

void WalkForward(pair<int, int> LocationTime) {
	int AfterLocation = LocationTime.second + 1;
	if (AfterLocation < 100001 && !visited[AfterLocation]) {
		visited[AfterLocation] = true;
		LocationTimeQueue.push(pair<int, int>(LocationTime.first + 1, AfterLocation));
	}
}

void Teleport(pair<int, int> LocationTime) {
	int AfterLocation = LocationTime.second * 2;
	if (AfterLocation < 100001 && !visited[AfterLocation]) {
		visited[AfterLocation] = true;
		LocationTimeQueue.push(pair<int, int>(LocationTime.first, AfterLocation));
	}
}

void Tree()
{
	while (!LocationTimeQueue.empty()) {
		pair<int, int> LocationTimeGet = LocationTimeQueue.top();
		LocationTimeQueue.pop();

		if (LocationTimeGet.second == SisLocation) {
			AnswerTime = LocationTimeGet.first;
			return;
		}

		Teleport(LocationTimeGet);

		WalkForward(LocationTimeGet);

		WalkBackward(LocationTimeGet);
	}
}

int main()
{
	int SBLocation;
	cin >> SBLocation >> SisLocation;
	visited[SBLocation] = 1;

	LocationTimeQueue.push(pair<int, int>(Time, SBLocation));
	Tree();

	cout << AnswerTime << endl;

}

