#include "common.h"

namespace Pathfinding
{
	PathfindingNode::PathfindingNode()
	{
		x = 0;
		y = 0;
		g = 0;
		h = 0;
		s = 0;
	}

	PathfindingNode::PathfindingNode(int x, int y) 
	{
		this->x = x;
		this->y = y;
		g = 0;
		h = 0;
		s = 0;
	}

	PathfindingNode::~PathfindingNode() 
	{

	}

}
