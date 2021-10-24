#include "pathfindingsolver.h"

using namespace godot;

void PathfindingSolver::_register_methods()
{
    register_method("_process", &PathfindingSolver::_process);
    register_method("GenerateLevelGrid", &PathfindingSolver::GenerateLevelGrid);
    register_method("FindPath", &PathfindingSolver::FindPath);
}

PathfindingSolver::PathfindingSolver()
{
}

PathfindingSolver::~PathfindingSolver()
{
}

void PathfindingSolver::_init()
{
    time_passed = 0.0;
}

void PathfindingSolver::_process(float delta)
{
    time_passed += delta;

    Vector2 new_position = Vector2(
        10 + (10 * sin(time_passed * 2.0)),
        10 + (10 * cos(time_passed * 1.5 )));

    set_position(new_position);
}

void PathfindingSolver::GenerateLevelGrid() 
{
    std::vector<std::vector<bool>> values{
    std::vector<bool>{false, false, false, false, false},
    std::vector<bool>{true, true, true, true, false},
    std::vector<bool>{true, true, true, true, false},
    std::vector<bool>{true, true, false, true, false},
    };

    grid = LevelGrid<bool>(values);
}

Array PathfindingSolver::FindPath(Vector2 start, Vector2 end)
{
    int2 int_start((int)start.x, (int)start.y);
    int2 int_end((int)end.x, (int)end.y);

    AStar pf = AStar(grid);
    std::vector<int2> path;
    bool result = pf.FindPath(int_start, int_end, path);

    Array arr;

    
    for (size_t i = 0; i < path.size(); i++)
    {
        int2 c = path[i];
        arr.push_back(Vector2((float)c.x, (float)c.y));
    }
    
    return arr;
}