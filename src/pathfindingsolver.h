#pragma once

#include <Godot.hpp>
#include <Sprite.hpp>
#include "common.h"
#include <Array.hpp>

using namespace Pathfinding;

namespace godot
{

    class PathfindingSolver : public Sprite
    {
        GODOT_CLASS(PathfindingSolver, Sprite)

    public:
        static void _register_methods();

        PathfindingSolver();
        ~PathfindingSolver();

        void _init(); // our initializer called by Godot

        void _process(float delta);

        void GenerateLevelGrid();

        Array FindPath(Vector2 start, Vector2 end);

    private:
        float time_passed = 0.0;
        LevelGrid<bool> grid;
    };

}