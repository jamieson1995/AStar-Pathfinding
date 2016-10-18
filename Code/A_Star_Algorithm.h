#pragma once
#include <vector>
#include <iostream>
#include <math.h>

	struct Node{

		int Location_x;
		int Location_y;
		float H_cost;
		float G_cost;
		float F_cost;
		Node* parent;

		Node(int _Location_x, int _Location_y, float _H_cost, float _G_cost, Node* _parent){
			Location_x = _Location_x;
			Location_y = _Location_y;
			H_cost = _H_cost;
			G_cost = _G_cost;
			F_cost = H_cost + G_cost;
			parent = _parent;
		}


	};

class A_Star_Algorithm
{
private:

	std::vector<Node*> ClosedSet;
	std::vector<Node*> OpenSet;	

	int Start_Tile_x;
	int Start_Tile_y;
	int Current_Tile_x;
	int Current_Tile_y;
	int End_Tile_x;
	int End_Tile_y;

public:
	A_Star_Algorithm(void);
	~A_Star_Algorithm(void);
	float CalculateDist(int x1, int y1, int x2, int y2);

	int Algorithm(int Map[10][10]);
};
