#pragma once

#include "common.h"

namespace Pathfinding
{
	template <typename T>
	class LevelGrid
	{
	public:
		LevelGrid(int p_width, int p_height, T baseValue)
			: width(p_width), height(p_height)
		{
			values = std::vector<std::vector<T>>(width);
			for (size_t x = 0; x < width; x++)
			{
				values.push_back(std::vector<T>(height));
				for (size_t y = 0; y < height; y++)
				{
					values[x].push_back(baseValue);
				}
			}
		}

		LevelGrid() 
		{

		}

		LevelGrid(std::vector<std::vector<T>> p_values)
			: values(p_values)
		{
			width = values.size();
			height = (width > 0) ? values[0].size() : 0;
		}

		~LevelGrid()
		{
		}

		inline T GetValue(int x, int y) const { return values[x][y]; }
		inline T GetValue(int2 pos) const { return values[pos.x][pos.y]; }
		inline T& GetValueRef(int x, int y) { return values[x][y]; }
		inline T& GetValueRef(int2 pos) { return values[pos.x][pos.y]; }
		inline void SetValue(int x, int y, T value) { values[x][y] = value; }
		inline void SetValue(int2 pos, T value) { values[pos.x][pos.y] = value; }
		inline int GetWidth() const { return width; }
		inline int GetHeight() const { return height; }

		inline bool CheckBounds(int x, int y) const { return x >= 0 && y >= 0 && x < width && y < height; }
		inline bool CheckBounds(int2 pos) const { return pos.x >= 0 && pos.y >= 0 && pos.x < width&& pos.y < height; }

		void GetAllNeighborsCoordinates(int2 pos, std::vector<int2>& neighbors) const
		{
			for (int _x = pos.x - 1; _x <= pos.x + 1; _x++)
			{
				for (int _y = pos.y - 1; _y <= pos.y + 1; _y++)
				{
					if ((_y != pos.y || _x != pos.x) && CheckBounds(_x, _y))
						neighbors.push_back(int2(_x, _y));
					

				}
			}
		}

	private:
		std::vector<std::vector<T>> values;
		int width;
		int height;
	};

	inline std::ostream& operator<<(std::ostream& os, const LevelGrid<PathfindingNode>& grid)
	{
		os << "Grid:\n";

		for (size_t x = 0; x < grid.GetWidth(); x++)
		{
			std::cout << "X" << x;

			for (size_t y = 0; y < grid.GetHeight(); y++)
			{
				std::cout << "Y" << y;

				os << grid.GetValue(x, y);
				if (y < grid.GetHeight() - 1)
				{
					os << " | ";
				}

			}
			os << "\n";

		}


		return os;
	}
	
	inline std::ostream& operator<<(std::ostream& os, const LevelGrid<bool>& grid)
	{
		os << "Grid:\n";

		for (size_t x = 0; x < grid.GetWidth(); x++)
		{
			std::cout << "X" << x;

			for (size_t y = 0; y < grid.GetHeight(); y++)
			{
				std::cout << "Y" << y;

				os << grid.GetValue(x, y);
				if (y < grid.GetHeight() - 1)
				{
					os << " | ";
				}
				
			}
			os << "\n";

		}
		

		return os;
	}
	
	
}



