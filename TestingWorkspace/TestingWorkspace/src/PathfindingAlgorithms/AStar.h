

#pragma once

#include "../common.h"

namespace Pathfinding
{
	class AStar : public Pathfinder
	{
	public:
		AStar(LevelGrid<bool>* grid);
		~AStar();
		virtual bool FindPath(const int2& start, const int2& goal, std::vector<int2>& path) const;
	
	private:
		int CalculateDistance(int2 from, int2 to) const;
		int2 GetLowestCostNode(LevelGrid<PathfindingNode>& pathfindingGrid, std::vector<int2>& list) const;
		bool CalculatePath(int2 endCoordinates, std::vector<int2>& path, LevelGrid<PathfindingNode>& nodeGrid) const;

	private:
		const int STRAIGHT_COST = 10;
		const int DIAGONAL_COST = 14;
		const int MAXIMUM_ITERATIONS = 40000;
	};



}



