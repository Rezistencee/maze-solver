## Welcome to GitHub Pages

Hello everyone.

### Algorithm

My maze solution uses the right hand rule, which has a very simple algorithm in terms of real-world traversal.

The rule of the right hand determines that a person in the maze must stretch his right hand to the wall and move behind this wall without taking his hand off the wall.

### Algorithm defect

One of the drawbacks is that the right-hand rule will not be able to traverse intertwined mazes (mazes that have circular branches, etc.)

##Code

Let's look at the Move_Ability function, this function is designed to check if there is a wall in the direction the person is currently looking at.
The direction itself is regulated through the formulas:
- If there is a wall in the direction of the character: c.direction = (c.direction + 3)% 4;
- If there is no wall in the direction of the character: c.direction = (c.direction + 1)% 4;

Move function simply moves the character depending on the direction.

if (steps% 50 == 0) is a small addition to the algorithm so that there is some chance to go through the intricate maze.
