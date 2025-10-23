# lineFollowerBot
Code for a simple arduino bot following a line made up of black tape on a floor.

# How it works
The bot uses an array of 5 IR sensors placed at the front of the car , each IR sensor has an assigned weight -> [-2,-1,0,1,2]. When the sensor detects line (black) we multiply 1 with the corresponding weight of the sensor and add all the values. We also divide this sum by a value called 'count' which keeps track of how many sensors detected black out of the 5 sensors, this way we get an average approximation of where the line must be. We get a positive value ('sum') when the line is to the right of the bot and a negative value when the line is to the right.

This value (or the error) is used by the PID control function, for this particular use case derivative and integral are not really required so only proportional part is used. The error is multiplied by a constant (proprotionality coefficient) and the resultant value is used to change the relative speed of the left and the right tyres.

If the error is positive we want to turn our car to the right, so we increase the speed of the left tyre and decrease it for the right tyre. This gives the car an angular velocity since the left tyre has to cover more distance as compared to the right one. Similarly for a negative error we turn the car to the left, decrease speed for the left tyre and increase for the right.

# What I learned
I had to learn about PID control algorithm and how motors are powered by an external power source with the help of a transistor to control the voltage output to the motor thus controlling its RPM.

I also learned about Dijkstra's algorithm on weighted graphs and how it can be used to turn the line following bot into a maze solver. For a maze the start/end point and each turning point can be treated as a node.

However Dijkstra's algorithm has some shortcomings, it has no sense of direction so for a grid like maze it acts like brute force (flood fill). A* solves this by adding an additional parameter it keeps track of in the priority queue, this could be the euclidean distance between our current node and the end point for our use case.

# Challenges faced
The motor was facing voltage fluctuations which would create a car meant to move in a straight line turn left and right because of differing RPM's on the two motors.
This was solved by using a capacitor in parallel to the motor which opposes any voltage change.

# Potential Improvements
By studying the frictional coefficient between the car tyres and the floor, we could find an upper limit on the speed of the car when it's turning. This would keep the car from slipping on the turns.
