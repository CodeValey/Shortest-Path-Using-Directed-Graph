#include<iostream>
using namespace std;

int infinity = 9999;

void show_path(int* trace_path, int end_point)  // show the trace path
{
	int i = 0;
	while (1)
	{
		cout << trace_path[i];

		if (trace_path[i] == end_point)
			break;

		cout << "->";
		i=trace_path[i];

	}

}

void find_optimal_path(int starting_point, int ending_point , int** cost_matrix, int* des_cost, int* trace_path)
{

	if (starting_point == ending_point)              // base case 
	{
		des_cost[starting_point]   = 0;
		trace_path[starting_point] = 0;
		return;
	}

	find_optimal_path(starting_point + 1, ending_point, cost_matrix, des_cost, trace_path);


	int cost = cost_matrix[starting_point-1][ending_point-1];
	int next_point = ending_point;


	for (int i = starting_point; i < ending_point-1;i++)  // bottom up approach
	{ 
		if (cost > cost_matrix[ starting_point-1 ][i] + des_cost[i])        // use memoization concept
		{
			cost = cost_matrix[ starting_point-1 ][i] + des_cost[i];
			next_point = i+1;
		}
	}
	
	des_cost[starting_point-1] = cost;                       // build solution
	trace_path[starting_point] = next_point;

}





int main()
{

	


	const int n=8;

	int** cost_matrix = new int* [n];
	
	cost_matrix[0] = new int[n] {0, 100, 20, 300, 400, 500, 600, 700};
	cost_matrix[1] = new int[n] { infinity,  0, 50, 10, 100, 200, 300, 400 };
	cost_matrix[2] = new int[n] { infinity, infinity,  0, 30, 10, 90, 10, 150 };
	cost_matrix[3] = new int[n] { infinity, infinity, infinity, 0, 80, 160, 240, 320 };
	cost_matrix[4] = new int[n] { infinity, infinity, infinity, infinity, 0, 120, 240, 600 };
	cost_matrix[5] = new int[n] { infinity, infinity, infinity, infinity, infinity,  0, 120, 240 };
	cost_matrix[6] = new int[n] { infinity, infinity, infinity, infinity, infinity, infinity, 0,120};
	cost_matrix[7] = new int[n] { infinity, infinity, infinity, infinity, infinity, infinity, infinity,  0};
	
	
	int* cost2=new int[n] { 0,0,0,0,0,0,0,0 };

	int* trace_path2=new int[n] { 1,2,3,4,5,6,7,8};

	find_optimal_path(1, n, cost_matrix, cost2, trace_path2);
	
	cout << " Optimal cost : " << cost2[0] << endl;
	cout << "path : " << endl;
    show_path(trace_path2, n);
   

	return 0;
}


//
//cost_matrix[0] = new int[n] { 0, 100, 200, 40, 250, 300, 400, 500, 600, 700 };
//cost_matrix[1] = new int[n] { infinity, 0, 50, 10, 100, 200, 300, 400, 500, 600};
//cost_matrix[2] = new int[n] { infinity, infinity, 0, 30, 10, 90, 10, 150, 200, 250 };
//cost_matrix[3] = new int[n] { infinity, infinity, infinity, 0, 80, 160, 240, 320, 400, 430};
//cost_matrix[4] = new int[n] { infinity, infinity, infinity, infinity, 0, 120, 240, 600, 650, 700};
//cost_matrix[5] = new int[n] { infinity, infinity, infinity, infinity, infinity, 0, 120, 240, 300, 350};
//cost_matrix[6] = new int[n] { infinity, infinity, infinity, infinity, infinity, infinity, 0, 120, 140, 160};
//cost_matrix[7] = new int[n] { infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, 200, 400};
//cost_matrix[8] = new int[n] { infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, 400};
//cost_matrix[9] = new int[n] { infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0};

