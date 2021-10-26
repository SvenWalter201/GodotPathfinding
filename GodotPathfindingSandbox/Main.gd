extends Node2D

var pfSolver

# Called when the node enters the scene tree for the first time.
func _ready():
	pfSolver = load("res://bin/pathfindingsolver.gdns").new()
	pfSolver.GenerateLevelGrid()

func _on_Sprite_position_changed(node, new_pos):
	print("The position of " + node.name + " is now " + str(new_pos))
	var path = pfSolver.FindPath(Vector2(0,0), Vector2(3,4))
	print(path)
	
	
