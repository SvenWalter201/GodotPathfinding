#include "common.h"

namespace Pathfinding
{
	
	Pathfinder::Pathfinder(LevelGrid<bool>& p_grid)
		: grid(p_grid) 
	{

	}
	
	
	Pathfinder::~Pathfinder() 
	{
	}

	bool Pathfinder::FindPath(const int2& start, const int2& goal, std::vector<int2>& path) const
	{
		return false;
	};
}

