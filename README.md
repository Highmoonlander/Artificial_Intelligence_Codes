# AI Course Projects

This repository contains several AI-related projects and algorithms implemented in C++ and Prolog as part of my college AI course. The projects demonstrate various search algorithms, a Tic-Tac-Toe game with and without AI, constraint satisfaction problems (CSP), and a Prolog-based expert system.

## Contents

### 1. **Tic-Tac-Toe Game**
   - **With AI**: Uses a Minimax algorithm to make decisions for the computer player.
   - **Without AI**: A simple two-player Tic-Tac-Toe game implementation.
   - The game demonstrates decision-making using adversarial search techniques.

### 2. **Search Algorithms** (C++)
   This folder contains implementations of several search algorithms, including:
   - **Uninformed Search Algorithms**:
     - **Breadth-First Search (BFS)**: Explores all nodes level by level.
     - **Depth-First Search (DFS)**: Explores as deep as possible along each branch.
   - **Informed Search Algorithms**:
     - **Best-First Search**: Uses a heuristic to prioritize nodes.
     - **A\* Search**: Combines the cost to reach a node with a heuristic estimate to find the optimal path.
     - **AO\* Search**: Used in graphs with both AND and OR nodes.
   These algorithms are fundamental for AI problem-solving, especially in pathfinding and graph traversal.

### 3. **Constraint Satisfaction Problem (CSP) - Graph Coloring** (C++)
   - Solves the Graph Coloring problem using backtracking, a key example of a constraint satisfaction problem.
   - Explores ways to color a graph such that no two adjacent nodes share the same color.

### 4. **Prolog Expert System**
   - A simple expert system implemented in Prolog to diagnose diseases based on a set of symptoms.
   - This system asks the user questions to gather information and provides a diagnosis based on matching symptoms to predefined disease rules.
   
## How to Run Prolog Expert System:
   1. Run the Prolog file using a Prolog interpreter (e.g., SWI-Prolog):
      ```
      swipl expert_system.pl
      ```
   3. Use the `diagnose.` command to start the diagnostic process.
