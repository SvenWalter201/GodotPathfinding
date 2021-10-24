
#pragma once

#include "common.h"

namespace Pathfinding
{
	class Pathfinder
	{
	public:
		Pathfinder(LevelGrid<bool>& p_grid);
		virtual ~Pathfinder();
		virtual bool FindPath(const int2& start, const int2& goal, std::vector<int2>& path) const;

	protected:
		LevelGrid<bool> grid;
	};
}
