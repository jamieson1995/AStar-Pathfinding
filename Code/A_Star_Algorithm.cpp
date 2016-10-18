#include "A_Star_Algorithm.h"


A_Star_Algorithm::A_Star_Algorithm(void)
{
}


A_Star_Algorithm::~A_Star_Algorithm(void)
{
}

int A_Star_Algorithm::Algorithm(int Map[10][10]){

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ( (Map[i][j] == 4) || (Map[i][j] == 5) ){
				//Sets Start, end and current tiles to correct positions
				Start_Tile_x = i;
				Start_Tile_y = j;
				Current_Tile_x = i;
				Current_Tile_y = j;
			}
			if ( (Map[i][j] == 6) || (Map[i][j] == 7) ){
				End_Tile_x = i;
				End_Tile_y = j;
			}
		}
	}

	//Resets the vectors to empty so algorithm can be run more than once
	OpenSet.clear();
	ClosedSet.clear();

	OpenSet.push_back(new Node(Current_Tile_x, Current_Tile_y, CalculateDist(Current_Tile_x, Current_Tile_y, End_Tile_x, End_Tile_y), 0, NULL) );

	while(!OpenSet.empty()){
		float lowest_f_cost = OpenSet[0]->F_cost;
		float lowest_node = 0;

		for (int i = 0; i < OpenSet.size(); i++)
		{
			//Finds node with lowest f_cost
			if (OpenSet[i]->F_cost <= lowest_f_cost)
			{
				lowest_f_cost = OpenSet[i]->F_cost;
				lowest_node = i;
				Current_Tile_x = OpenSet[lowest_node]->Location_x;
				Current_Tile_y = OpenSet[lowest_node]->Location_y;
			}
		}


		//node with lowest f_cost is set to q
		Node* q = new Node(OpenSet[lowest_node]->Location_x, OpenSet[lowest_node]->Location_y, OpenSet[lowest_node]->H_cost, OpenSet[lowest_node]->G_cost, OpenSet[lowest_node]->parent);
		auto i = std::find(begin(OpenSet), end(OpenSet), OpenSet[lowest_node]);
		//node with lowest f_cost is removed from OpenSet and added to closed set
		OpenSet.erase(i);
		ClosedSet.push_back(q);

		//Next part of code checks all the neighbours
		Node* successor[8];
		bool NoNode[8];
		NoNode[0] = false;
		NoNode[1] = false;
		NoNode[2] = false;
		NoNode[3] = false;
		NoNode[4] = false;
		NoNode[5] = false;
		NoNode[6] = false;
		NoNode[7] = false;

		//Checks if neighbour is our of map bounds
		if (Current_Tile_y+1 > 9)
		{
				NoNode[0] = true;
		}
		if (NoNode[0] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x][Current_Tile_y+1] == 3)
			{
				NoNode[0] = true;
			}
			//Checks if neighbour is a forest tile.
			else if(Map[Current_Tile_x][Current_Tile_y+1] == 2)
			{
				successor[0] = new Node(q->Location_x, q->Location_y+1, CalculateDist(Current_Tile_x, Current_Tile_y+1, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x, Current_Tile_y+1, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[0] = new Node(q->Location_x, q->Location_y+1, CalculateDist(Current_Tile_x, Current_Tile_y+1, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x, Current_Tile_y+1, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if (Current_Tile_x+1 > 9)
		{
				NoNode[1] = true;
		}
		if (NoNode[1] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x+1][Current_Tile_y] == 3)
			{
				NoNode[1] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x+1][Current_Tile_y] == 2)
			{
				successor[1] = new Node(q->Location_x+1, q->Location_y, CalculateDist(Current_Tile_x+1, Current_Tile_y, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x+1, Current_Tile_y, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{		
				successor[1] = new Node(q->Location_x+1, q->Location_y, CalculateDist(Current_Tile_x+1, Current_Tile_y, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x+1, Current_Tile_y, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if(Current_Tile_y-1 < 0)
		{
			NoNode[2] = true;
		}
		if (NoNode[2] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x][Current_Tile_y-1] == 3)
			{
				NoNode[2] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x][Current_Tile_y-1] == 2)
			{
				successor[2] = new Node(q->Location_x, q->Location_y-1, CalculateDist(Current_Tile_x, Current_Tile_y-1, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x, Current_Tile_y-1, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[2] = new Node(q->Location_x, q->Location_y-1, CalculateDist(Current_Tile_x, Current_Tile_y-1, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x, Current_Tile_y-1, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if (Current_Tile_x-1 < 0)
		{
			NoNode[3] = true;
		}
		if (NoNode[3] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x-1][Current_Tile_y] == 3)
			{
				NoNode[3] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x-1][Current_Tile_y] == 2)
			{
				successor[3] = new Node(q->Location_x-1, q->Location_y, CalculateDist(Current_Tile_x-1, Current_Tile_y, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x-1, Current_Tile_y, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[3] = new Node(q->Location_x-1, q->Location_y, CalculateDist(Current_Tile_x-1, Current_Tile_y, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x-1, Current_Tile_y, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if ( (Current_Tile_x+1 > 9) || (Current_Tile_y+1 > 9) )
		{
			NoNode[4] = true;
		}
		if (NoNode[4] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x+1][Current_Tile_y+1] == 3)
			{
				NoNode[4] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x+1][Current_Tile_y+1] == 2)
			{
				successor[4] = new Node(q->Location_x+1, q->Location_y+1, CalculateDist(Current_Tile_x+1, Current_Tile_y+1, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x+1, Current_Tile_y+1, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[4] = new Node(q->Location_x+1, q->Location_y+1, CalculateDist(Current_Tile_x+1, Current_Tile_y+1, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x+1, Current_Tile_y+1, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if ( (Current_Tile_x-1 < 0) || (Current_Tile_y+1 > 9) )
		{
			NoNode[5] = true;
		}
		if (NoNode[5] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x-1][Current_Tile_y+1] == 3)
			{
				NoNode[5] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x-1][Current_Tile_y+1] == 2)
			{
				successor[5] = new Node(q->Location_x-1, q->Location_y+1, CalculateDist(Current_Tile_x-1, Current_Tile_y+1, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x-1, Current_Tile_y+1, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[5] = new Node(q->Location_x-1, q->Location_y+1, CalculateDist(Current_Tile_x-1, Current_Tile_y+1, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x-1, Current_Tile_y+1, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if ( (Current_Tile_x-1 < 0) || (Current_Tile_y-1 < 0) )
		{
			NoNode[6] = true;
		}
		if (NoNode[6] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x-1][Current_Tile_y-1] == 3)
			{
				NoNode[6] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x-1][Current_Tile_y-1] == 2)
			{
				successor[6] = new Node(q->Location_x-1, q->Location_y-1, CalculateDist(Current_Tile_x-1, Current_Tile_y-1, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x-1, Current_Tile_y-1, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[6] = new Node(q->Location_x-1, q->Location_y-1, CalculateDist(Current_Tile_x-1, Current_Tile_y-1, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x-1, Current_Tile_y-1, Start_Tile_x, Start_Tile_y), q);
			}
		}

		//Checks if neighbour is our of map bounds
		if ( (Current_Tile_x+1 > 9) || (Current_Tile_y-1 < 0) )
		{
			NoNode[7] = true;
		}
		if (NoNode[7] == false)
		{
			//Checks is neighbour is a water tile
			if (Map[Current_Tile_x+1][Current_Tile_y-1] == 3)
			{
				NoNode[7] = true;
			}
			//Checks if neighbour is a forest tile.
			else if (Map[Current_Tile_x+1][Current_Tile_y-1] == 2)
			{
				successor[7] = new Node(q->Location_x+1, q->Location_y-1, CalculateDist(Current_Tile_x+1, Current_Tile_y-1, End_Tile_x, End_Tile_y)+1, CalculateDist(Current_Tile_x+1, Current_Tile_y-1, Start_Tile_x, Start_Tile_y), q);
			}
			//If it is non of the above then it must be a grass tile or the destination.
			else
			{
				successor[7] = new Node(q->Location_x+1, q->Location_y-1, CalculateDist(Current_Tile_x+1, Current_Tile_y-1, End_Tile_x, End_Tile_y), CalculateDist(Current_Tile_x+1, Current_Tile_y-1, Start_Tile_x, Start_Tile_y), q);
			}
		}

		for (int i = 0; i < 8; i++)
		{
			//Checks to see if current neighbour has a node
			if (NoNode[i] == true){
				goto finish;
			}
			//Checks to see if the current neighbour is the destination
			if ( (q->Location_x == End_Tile_x) && (q->Location_y == End_Tile_y) )
			{
				goto finish_all;
			}
			else
			{
				for (int j = 0; j < OpenSet.size(); j++)
				{
					//These checks make sure the current neighbour isn't already in the OpenSet, and if it is, does it have a lower f_cost
					if (OpenSet[j]->Location_x == successor[i]->Location_x) 
					{
						if (OpenSet[j]->Location_y == successor[i]->Location_y)
						{
							if (OpenSet[j]->F_cost <= successor[i]->F_cost )
							{
								goto finish;
							}
						}
					}
				}
				for (int j = 0; j < ClosedSet.size(); j++)
				{
					//These checks make sure the current neighbour isn't already in the ClosedSet, and if it is, does it have a lower f_cost
					if (ClosedSet[j]->Location_x == successor[i]->Location_x) 
					{
						if (ClosedSet[j]->Location_y == successor[i]->Location_y) 
						{
							if (ClosedSet[j]->F_cost <= successor[i]->F_cost )
								{
									goto finish;
								}
						}
					}
				}
				//If the current neighbour is new, or has a lower f_cost if not new, then it gets added to the OpenSet
				OpenSet.push_back(successor[i]);
			}
			finish:;
		}
	}

	finish_all:;
	Node* current_parent;

	//if the OpenSet is empty, then there is no path.
	if (OpenSet.empty() == true){
		std::cout << std::endl;
		std::cout << "A path could not be found!" << std::endl;
		return Map[10][10];
	}

	for (int i = 0; i < ClosedSet.size(); i++)
	{
		//This finds the node in the closed set with the same position as the end tile, and it becomes the current parent.
		if ( (ClosedSet[i]->Location_x == End_Tile_x) && (ClosedSet[i]->Location_y == End_Tile_y) ){
			current_parent = ClosedSet[i];
			Map[ClosedSet[i]->parent->Location_x][ClosedSet[i]->parent->Location_y] = 8;
		}
	}
	//This while loop gets the current parent position and sets the map tile to the correct value.
	//Then the current parent becomes the current parent's parent.
	//The loop ends when the current parent's parent is the start tile.
	while ( (current_parent->parent->Location_y != Start_Tile_y) || (current_parent->parent->Location_x != Start_Tile_x) )
	{
		if (Map[current_parent->parent->Location_x][current_parent->parent->Location_y] == 1)
		{
			Map[current_parent->parent->Location_x][current_parent->parent->Location_y] = 8;
		}
		else if (Map[current_parent->parent->Location_x][current_parent->parent->Location_y] == 2)
		{
			Map[current_parent->parent->Location_x][current_parent->parent->Location_y] = 9;
		}
		current_parent = current_parent->parent;
	}
	return Map[10][10];
}

float A_Star_Algorithm::CalculateDist(int x1, int y1, int x2, int y2){

	float dist;

	dist = sqrt( pow(x1 - x2, 2) + (pow (y1 - y2, 2) ) );

	return dist;
}
