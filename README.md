# Flight-Path-Optimization
 A simple implementation of Dijkstra’s Algorithm to find the shortest and optimized path for aircrafts in terms of fuel and time efficiency. It calculates the expected time to reach the destination and Fuel left by travelling the optimized path and also calculates the path with less noise  interferance.

 ## Problem Statement 
 In modern aviation, efficient flight path planning is critical for minimizing operational costs, reducing environmental impact, and ensuring timely arrivals. Given the complexities of air travel, including varying fuel consumption rates and time delays due to factors such as noise interference and air traffic, it is essential to develop an algorithm that can determine the most optimal route for aircraft.

 ### Objective
The objective of this project is to implement a simplified version of Dijkstra’s Algorithm to identify the shortest and most efficient flight path for aircraft based on two key metrics: fuel consumption and time efficiency. The algorithm will not only calculate the expected time to reach the destination but also estimate the remaining fuel upon arrival, ensuring that aircraft can complete their journeys safely and effectively.

 ### Assumptions:
1. Graph Structure: Nodes represent airports, and edges represent possible flight paths between them.
2. Weights: The weights on the edges represent fuel consumption and  time.
3. Fuel Constraints: Each node will also track the fuel left after reaching it.

 ### Dijkstra's Algorithm
 Dijkstra's algorithm is a fundamental graph search algorithm designed to find the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights. It operates by initializing the distance to the source node as zero and all others as infinity, then iteratively selecting the unvisited node with the smallest tentative distance and exploring its neighbors. For each neighbor, it calculates the potential shorter path through the current node and updates the distances accordingly. The algorithm continues until all nodes are visited or the shortest path to a specific target node is found. With a time complexity of O((V+E)logV) using a priority queue.

 ### Implementation
 1. User Input Order: 
<li>The program first asks the user to input the number of airports (n).</li>
<li>Next, it prompts for the source and target airports.</li>
<li>Then, the user is asked to input the number of connections (m) between the airports, followed by the specific connections.</li>


