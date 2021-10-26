#pragma once
#include "common.h"

namespace Pathfinding
{
	class int2
	{
	public:
		int2();
		int2(int p_x, int p_y);
		~int2();

		int x = 0;
		int y = 0;

		inline bool operator==(const int2& other) { return x == other.x && y == other.y; }
		inline bool operator!=(const int2& other) { return !(*this == other); }
		inline int2& operator+=(const int2& other) 
		{ 
			x += other.x;
			y += other.y;
			return *this;
		}
		inline int2& operator-=(const int2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
	};

	
	inline std::ostream& operator<<(std::ostream& os, const int2& obj)
	{
		os << "(" << obj.x << "," << obj.y <<")";
		return os;
	}
	
	inline std::ostream& operator<<(std::ostream& os, const std::vector<int2>& list)
	{
		for (size_t i = 0; i < list.size(); i++)
		{
			int2 current = list[i];
			os << current;
			if (i < list.size() - 1)
			{
				os << ":";
			}
		}
		
		return os;
	}
}


