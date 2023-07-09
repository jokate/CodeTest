#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> GroundVector;

int main()
{
	int Height;
	int Width;
	int Sum = 0;
	cin >> Height >> Width;

	for(int i = 0; i < Width; i++) 
	{
		int GroundHeight;
		cin >> GroundHeight;
		GroundVector.push_back(GroundHeight);
	}

	for (int i = 0; i < Width - 1; i++) 
	{
		int RightBound = 0;
		int LeftBound = 0;

		//���� ���� �߿� ��谡 �Ǵ� �κ��� ã�� ��, ���� ���� ��踦 �������� �ؼ� ���̸� ���Ѵ�.

		for(int j = 0; j < i; j++) 
		{
			if (LeftBound < GroundVector[j])
				LeftBound = GroundVector[j];
		}

		for (int j = Width - 1; j > i; j--)
		{
			if (RightBound < GroundVector[j])
				RightBound = GroundVector[j];
		}
		Sum += max(0, min(LeftBound, RightBound) - GroundVector[i]);
	}
	cout << Sum;
}

