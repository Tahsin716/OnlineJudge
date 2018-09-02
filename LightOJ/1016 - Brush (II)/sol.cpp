#include <bits/stdc++.h>

using namespace std;

vector<int> YCoordinate;

int main()
{
	int T, testCase = 0;

	scanf("%d", &T);

	while (T--)
	{
		//Here n is the total no. of dust points, w is the width of the brush
		//x is the x-coordinate and y is the y-cooridinate of the brush.
		int n, w, x, y;

		scanf("%d%d", &n, &w);

		//We are going to push the y co-ordinates into a vector
		//we are taking the y - coridinates into the vector because
		//Samee moves the brush horizontally (along x - axis), so every new move
		//is done vertically (along y - axis), thus we will take y - coordinates into the
		//vector.
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);

			YCoordinate.push_back(y);
		}

		//We are sorting the y - coordinates because the coordinates
		//will obviously stay in an order, thus we need to sort it as the
		//coordinates were not inserted in ascending order.
		sort(YCoordinate.begin(), YCoordinate.end());

		//We will need atleast one move all the time, as
		//just moving the brush means one move.
		int count = 1; 

		//We will subtract the current y-coordinate with the previous y-coordinate
		//if the difference between them is greater than the brush width, that means 
		//both the dust points cannot be covered with one brush move, so we need to
		//increase the move count. We will then change our prevCoordinate to the current one
		//to check the next coordinate.
		int prevCoordinate = YCoordinate[0];

		for (int i = 1; i < n; i++)
		{
			//w is less than current coordinate - previous coordinate
			//so one move is not enough to remove them, thus move will be increased
			if (w < YCoordinate[i] - prevCoordinate)
			{
				count++;
				prevCoordinate = YCoordinate[i]; //Update previous coordinate to the current one, to check the next coordinate
			}
		}

		printf("Case %d: %d\n", ++testCase, count);

		//To remove data from previous test case
		YCoordinate.clear(); 
	}

	return 0;
}