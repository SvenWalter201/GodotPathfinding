#include "common.h"

namespace Pathfinding
{
	
	AStar::AStar(LevelGrid<bool>& p_grid)
		: Pathfinder(p_grid)
	{		
	}

	AStar::~AStar() 
	{	
	}

	bool AStar::FindPath(const int2& start,const int2& goal, std::vector<int2>& path) const
	{
		std::vector<int2> openList;
		std::vector<int2> closedList;

		int width = grid.GetWidth();
		int height = grid.GetHeight();

		LevelGrid<PathfindingNode> nodeGrid(width, height, PathfindingNode(0,0));

		int currentIterations = 0;

		for (size_t x = 0; x < grid.GetWidth(); x++)
		{
			for (size_t y = 0; y < grid.GetHeight(); y++)
			{
				PathfindingNode node(x, y);
				node.g = 1000000;
				node.h = 1000000;
				node.s = 1000000;
				node.cameFromCoordinates = int2(-1, -1);
				nodeGrid.SetValue(x, y, node);
			}
		}

		PathfindingNode startNode = nodeGrid.GetValue(start);
		startNode.g = 0;
		startNode.h = CalculateDistance(start, goal);
		nodeGrid.SetValue(start, startNode);
		openList.push_back(start);

		while (openList.size() > 0 && currentIterations < MAXIMUM_ITERATIONS)
		{
			//std::cout << "OpenListSize" << openList.size() << std::endl;
			currentIterations++;
			int2 current = GetLowestCostNode(nodeGrid, openList);

			if (current == goal)
			{
				//std::cout << nodeGrid << std::endl;
				return CalculatePath(goal, path, nodeGrid);
			}

			//std::cout << openList.size() << ";";
			openList.erase(std::remove(openList.begin(), openList.end(), current), openList.end());
			//std::cout << openList.size() << std::endl;

			closedList.push_back(current);

			std::vector<int2> neighborCoordinates; 
			grid.GetAllNeighborsCoordinates(current, neighborCoordinates);
			//std::cout << "Neighbors: " << neighborCoordinates.size() << std::endl;
			for (size_t i = 0; i < neighborCoordinates.size(); i++)
			{
				int2 neighborCoord = neighborCoordinates[i];

				if (std::find(closedList.begin(), closedList.end(), neighborCoord) != closedList.end())
					continue;

				if (grid.GetValue(neighborCoord))
				{
					closedList.push_back(neighborCoord);
					continue;
				}

				PathfindingNode neighbor = nodeGrid.GetValue(neighborCoord);
				int tempGCost = nodeGrid.GetValue(current).g + CalculateDistance(current, neighborCoord);

				if (tempGCost < neighbor.g)
				{
					neighbor.g = tempGCost;
					neighbor.h = CalculateDistance(neighborCoord, goal);
					neighbor.s = neighbor.g + neighbor.h;
					neighbor.cameFromCoordinates = current;
					nodeGrid.SetValue(neighborCoord, neighbor);

					if (std::find(openList.begin(), openList.end(), neighborCoord) == openList.end())
						openList.push_back(neighborCoord);
				}
			}
		}

		std::cout << "No Path found" << std::endl;
		return false;
	}

	int AStar::CalculateDistance(int2 from, int2 to) const
	{
		int x = abs(from.x - to.x);
		int y = abs(from.y - to.y);
		int remaining = abs(x - y);
		int smaller = (x < y) ? x : y;
		return DIAGONAL_COST * smaller + STRAIGHT_COST * remaining;
	}

	int2 AStar::GetLowestCostNode(LevelGrid<PathfindingNode>& pathfindingGrid, std::vector<int2>& list) const
	{
		int2 lowest = list[0];
		for (int i = 0; i < list.size(); i++)
		{
			if (pathfindingGrid.GetValue(list[i]).s < pathfindingGrid.GetValue(lowest).s)
				lowest = list[i];
		}

		return lowest;
	}

	bool AStar::CalculatePath(int2 endCoordinates, std::vector<int2>& path, LevelGrid<PathfindingNode>& nodeGrid) const
	{
		path.push_back(endCoordinates);

		//std::cout << "Generating oath" << std::endl;

		PathfindingNode currentNode = nodeGrid.GetValue(endCoordinates);

		while (currentNode.cameFromCoordinates != int2(-1, -1))
		{
			//std::cout << currentNode.cameFromCoordinates << std::endl;

			path.push_back(currentNode.cameFromCoordinates);
			currentNode = nodeGrid.GetValue(currentNode.cameFromCoordinates);
		}

		//path.reserve(path.size());
		return true;
	}
}
