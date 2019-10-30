# queens.py
# From Classic Computer Science Problems in Python Chapter 3
# Copyright 2018 David Kopec
#
# Modified by Russ Abbott (July/October, 2019)
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from copy import copy
from timeit import default_timer as timer
from typing import Dict, List, Optional, Set

from csp import all_different, CSP
from queens_display import display_solution


def n_queens_constraint(board) -> bool:
    board_size = len(board)
    up_down_pairs: List[List[int, int]] = [
                                            [board[i] - i, board[i] + i]
                                            for i in range(board_size) if board[i] is not None
                                           ]
    [l1, l2] = zip(*up_down_pairs)
    (up_diagonal, down_diagonal) = (list(l1), list(l2))

    up_diagonal_alt = [board[i] - i for i in range(board_size) if board[i] is not None]
    down_diagonal_alt = [board[i] + i for i in range(board_size) if board[i] is not None]

    assert up_diagonal == up_diagonal_alt and down_diagonal == down_diagonal_alt, \
        f'diagonals differ: up: {up_diagonal} != {up_diagonal_alt} or down: {down_diagonal} !={down_diagonal_alt}'
    return all_different(board) and all_different(up_diagonal) and all_different(down_diagonal)


# noinspection PyUnusedLocal
def propagate_column_constraint(_selected_col, selected_row, domains: Dict[int, Set[int]]) -> Dict[int, Set[int]]:
    reduced_domains: Dict[int, Set[int]] = copy(domains)
    # Prevent other columns from putting a queen in this queen's selected_row
    length = len(domains)

    for x in range (length):
        newSet: Set[int] = copy(domains[x])
        newSet.discard(selected_row)
        reduced_domains[x] = newSet

    reduced_domains[_selected_col]=set()
    return reduced_domains

# noinspection PyUnusedLocal
def getDiagonals(selected_column, selected_row, domains: Dict[int, Set[int]]):
    # newDomain: Dict[int, Set[int]] = copy(domains)
    length = len(domains)
    # because we know it must be a square, then the length of newDomain is the range for both x and y
    allDiagPos = []

    #appending top left
    for num, num2 in zip(range(selected_column - 1, -1, -1), range(selected_row - 1, -1, -1)):
        allDiagPos.append(tuple((num,num2)))
    
    #appending top right
    for num, num2 in zip(range(selected_column + 1, length, 1), range(selected_row - 1, -1 , -1)):
        allDiagPos.append(tuple((num,num2)))

    #appending bottom right
    for num, num2 in zip(range(selected_column + 1, length, 1), range(selected_row + 1, length, 1)):
        allDiagPos.append(tuple((num,num2)))

    #appending bottom left
    for num, num2 in zip(range(selected_column - 1, -1, -1), range(selected_row + 1, length, 1)):
        allDiagPos.append(tuple((num,num2)))
    return allDiagPos
    
def propagate_diagonals_constraint(selected_col, selected_row, domains: Dict[int, Set[int]]) -> Dict[int, Set[int]]:
    reduced_domains: Dict[int, Set[int]] = copy(domains)
    # Prevent other columns from putting a queen in this queen's diagonals
    """ Your code here """
    # using my small code snippet from above, getDiagonals returns a list of tuples of the coordinates of all the diagonals of the given selected col and row
    diagonals = getDiagonals(selected_col, selected_row, domains)
    for x,y in diagonals:
        newSet: Set[int] = copy(domains[x])
        newSet.discard(y)
        reduced_domains[x] = newSet

    return reduced_domains



def run_n_queens(board_size, first_fail=True, propagation=True, central_domain_selection=True):
    # The board is represented as a list. Each element represents the position, i.e., row, of the queen in that column.
    # (The program uses 0-based indexing since it's basic to Python. The results are labelled with 1-based indexing.)
    #
    # So board = [1, 3, 0, 2] means:
    #                                  0 1 2 3
    #                               0) . . Q .
    #                               1) Q . . .
    #                               2) . . . Q
    #                               3) . Q . .
    #
    # This model of the problem ensures that each column has exactly one queen--or None if no queen is assigned
    # to that column.

    # Intially, the board is empty. The board will substitute for the assignment dictionary.
    # A value of 0 means that no assignment has been made.
    board: List[Optional[int]] = [None]*board_size
    # Each board position has the same domain.
    # Note that instead of variable names we are using numbers as variables.
    board_size = len(board)
    common_domain = set(range(board_size))
    domains = {v: common_domain for v in range(board_size)}

    # Set assignment_limit to 0 to turn off tracing. A positive number indicates
    # the number of assignments to allow (and to display) before quitting.
    assignment_limit =  0

    # Create the CSP object
    csp: CSP[int, int] = CSP(board_size, assignment_limit, propagation, first_fail, central_domain_selection)
    csp.add_constraint(n_queens_constraint)
    csp.add_propagator(propagate_column_constraint)
    csp.add_propagator(propagate_diagonals_constraint)

    timer_start = timer()
    solution = csp.complete_the_assignment(board, domains)
    assignments = csp.assignment_count
    if solution:
        display_solution(solution, assignments, round(timer() - timer_start, 3))
    else:
        print(f'\nNo solution after {assignments} assignments.')


if __name__ == "__main__":
    run_n_queens(200, propagation=True, first_fail=True, central_domain_selection=True)