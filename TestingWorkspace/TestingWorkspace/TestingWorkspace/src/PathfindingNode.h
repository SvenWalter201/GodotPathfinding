#pragma once

namespace Pathfinding
{
	class PathfindingNode
	{
	public:
		PathfindingNode();
		PathfindingNode(int x, int y);
		~PathfindingNode();

		inline int GetS() { return s; }
		inline void SetS() { s = h + g; }


	public:
		int x;
		int y;
		int g;
		int h;
		int s;
		int2 cameFromCoordinates;
	};

	inline std::ostream& operator<<(std::ostream& os, const PathfindingNode& node)
	{
		os << "Node:\n";
		os << int2(node.x, node.y);
		os  << " G: " << node.g << ", H: " << node.h << ", S:" << node.s << ", CF:" << node.cameFromCoordinates;

		return os;
	}
}
