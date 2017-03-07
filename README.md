# Google-Codejam-Kickstart-Round-A-2017
This is my solution to Google Codejam Kickstart Round A 2017.

Problem A
-----------

This is a math problem. For each possible shape, you just need to figure out the amount of squares of that shape then sum them up. Finally, this leads to a summation of integers, square of integers, cube of integers. Using corresponding summation formulae will give you an `O(1)` solution. Another issue is to use `number-theoretic reciprocal` to deal with the division.


Problem B
-----------

Dynamic programming. **The tricky part is, you may want to replace a '*' with 4 '?'s, where '?' can match 0~1 normal character.** With such trick, the transition equations are simplified significantly.


Problem C
-----------

Solve by `bisection method`. Given the bounding box of all stars, the two cubes must be put to opposite vertices to make them small enough. One just need to enumerate 4 possible pairs of opposite vertices, i.e.: (xmin, ymin, zmin) vs. (xmax, ymax, zmax), (xmax, ymin, zmin) vs. (xmin, ymax, zmax), (xmin, ymax, zmin) vs. (xmax, ymin, zmax), (xmax, ymax, zmin) vs. (xmin, ymin, zmax).
