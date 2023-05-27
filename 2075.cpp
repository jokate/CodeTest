// CodeTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int num;
		for (int j = 0; j < n; ++j) {
			cin >> num;

			if (pq.size() == n) {
				if(num > pq.top())
				{
					pq.pop();
					pq.push(num);
				}
			}	
			else {
				pq.push(num);
			}
		}
	}
	cout << pq.top() << endl;


}
