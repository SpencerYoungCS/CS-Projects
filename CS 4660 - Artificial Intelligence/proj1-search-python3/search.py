# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util


class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return [s, s, w, s, w, w, s, w]


def depthFirstSearch(problem):
    # The Fringe
    stack = util.Stack()
    stack.push((problem.getStartState(), []))
    # now we just need a way to keep track of the parent, and the level or depth
    visited = []
    while stack:
        current_node, path = stack.pop()
        visited.append(current_node)
        if problem.isGoalState(current_node):
            return path
        for node in problem.getSuccessors(current_node):
            if node[0] not in visited:
                new_path = list(path)
                new_path.append(node[1])
                stack.push((node[0], new_path))


def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    # our fringe
    queue = util.Queue()
    queue.push((problem.getStartState(), []))
    visited = []

    while queue:
        current_node, path = queue.pop()
        visited.append(current_node)
        if problem.isGoalState(current_node):
            return path
        for node in problem.getSuccessors(current_node):
            if node[0] not in visited:
                new_path = list(path)
                new_path.append(node[1])
                visited.append(node[0])
                queue.push((node[0], new_path))


def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    # our fringe
    queue = util.PriorityQueue()
    queue.push((problem.getStartState(), []), 0)
    visited = []

    while queue:
        (current_node), path = queue.pop()
        if problem.isGoalState(current_node):
            return path
        if current_node not in visited:
            visited.append(current_node)
            for node in problem.getSuccessors(current_node):
                if node[0] not in visited:
                    new_path = list(path)
                    new_path.append(node[1])
                    new_cost = problem.getCostOfActions(new_path)
                    queue.push((node[0], new_path), new_cost)

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0


def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    # our fringe
    pqueue = util.PriorityQueue()
    pqueue.push((problem.getStartState(), []), 0)
    visited = []

    while pqueue:
        (current_node), path = pqueue.pop()
        if problem.isGoalState(current_node):
            return path
        if current_node not in visited:
            visited.append(current_node)
            for node in problem.getSuccessors(current_node):
                if node[0] not in visited:
                    new_path = list(path)
                    new_path.append(node[1])
                    new_cost = problem.getCostOfActions(new_path) + heuristic(node[0], problem)
                    pqueue.push((node[0], new_path), new_cost)


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
