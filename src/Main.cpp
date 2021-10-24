/*

#pragma once

#include "common.h"


using namespace Pathfinding;


LevelGrid<bool>* InitializeTestGrid()
{
    std::vector<std::vector<bool>> values{
    std::vector<bool>{false, false, false, false, false},
    std::vector<bool>{true, true, true, true, false},
    std::vector<bool>{true, true, true, true, false},
    std::vector<bool>{true, true, false, true, false},
    };

    LevelGrid<bool>* grid = new LevelGrid<bool>(values);
    return grid;
}


int main()
{
    int2 a = int2(0,0);
    int2 b = int2(3,4);
    int2 c = int2(3, 4);
    //std::cout << "Testing Int2" << std::endl;
    //std::cout << a << std::endl;
    //std::cout << (a == b) << std::endl;
    //std::cout << (a == c) << std::endl;
    std::cout << "Testing LevelGrid" << std::endl;
    LevelGrid<bool>* levelGrid = InitializeTestGrid();
    //std::cout << "Width" << levelGrid->GetWidth() << std::endl;
    //std::cout << "Height" << levelGrid->GetHeight() << std::endl;
    //std::cout << *levelGrid << std::endl;
    

    AStar pf = AStar(levelGrid);
    std::vector<int2> path;
    bool result = pf.FindPath(a, b, path);
    std::cout << "Result: " << result << "; Path: " << path << std::endl;
    return 0;
}
*/

