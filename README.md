#
# Maze_Generator_and_Solver
Here is a little program who generate mazes and solve them.
#
# How to use 
> make
Two binarys will show up on them respective folder (generator and solver).

To execute generator :
> ./generator lines cols perfect
Lines and cols are your two number to create your maze (don't go more than 100 * 100, it's begin to be kinda slow).
And the perfect argument is optional. It's to create a perfect maze who has no loops and no clusters.

To execute solver :
> ./solver filepath
Filepath is the path of your maze.
