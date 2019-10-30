
# csp.py
# From Classic Computer Science Problems in Python Chapter 3
# Copyright 2018 David Kopec
#
# With relatively minor modifications by Russ Abbott (7/2019)
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

# Modified by Russ Abbott (2019)


# The first import allows the use of CSP as a type in all_different, a method within CSP.
# It shouldn't be necessary in Python 3.8
from __future__ import annotations
from collections import deque

from typing import Callable, Dict, Generic, List, Optional, Set, TypeVar

V = TypeVar('V')  # the type of the variables
D = TypeVar('D')  # the type of the domain elements


def all_different(board: List[int]):
    """
    Are all values in the assignment unique?

    This is such a common constraint that we are including it here.
    """
    assigned_board = [i for i in board if i is not None]
    return len(assigned_board) == len(set(assigned_board))


def assigned_board(board: List[int]):
    """
    The board values that are not None, which means unassigned.
    :param board:
    :return:
    """
    return [i for i in board if i is not None]


class CSP(Generic[V, D]):
    """
    A constraint satisfaction problem consists of 
        a) variables of type V that have 
        b) domains of values of type D and 
        c) constraints that determine the validity of a given assignment of values to variables.  
    """
    
    def __init__(self, board_size, assignment_limit, propagation, first_fail, central_domain_selection):
        self.board_size = board_size
        self.variables = list(range(board_size))
        self.constraints: List[Callable[..., bool]] = []
        self.propagators: List[Callable[..., Dict[V, Set[D]]]] = []
        self.first_fail = first_fail
        self.propagation = propagation
        self.central_domain_selection = central_domain_selection
        
        # Keeps track of the number of assignments created
        self.assignment_limit = assignment_limit
        self.assignment_count = 0
        self.printed_reached_limit = False

    def add_constraint(self, constraint: Callable[..., bool]) -> None:
        self.constraints.append(constraint)

    def add_propagator(self, propagator: Callable[..., Dict[V, Set[D]]]) -> None:
        self.propagators.append(propagator)

    def apply_propagators(self, selected_variable, selected_value, domains):
        for propagator in self.propagators:
            domains = propagator(selected_variable, selected_value, domains)
        return domains


    # the objective is to select the variable with the shortest length
    def firstFail(self, domains: Dict[V, Set[D]], unassigned_var: List[V]):
        validDomains = []
        counter = 0
        # first im adding all the domains that are NOT empty sets! counter keeps track of their index
        for x in domains.values():
            if len(x) != 0:
                validDomains.append(tuple((counter, x)))
            counter += 1
        try:
            shortestDomain = len((min([values[1] for values in validDomains], key=len)))
        except:
            return unassigned_var[0]

        for values in validDomains:
            if len(values[1]) == shortestDomain:
                index = unassigned_var.index(values[0])
                # print(unassigned_var[index])
                return unassigned_var[index]

    def centralDomain(self, possible_val: Set()) -> List():
        # converting them to a list so I can slice them easily
        listValues = list(possible_val)
        # double forward slash is an integer division
        firstHalf = listValues[:len(listValues)//2]
        lastHalf =  sorted(listValues[len(listValues)//2:])
        # reverse the first half then join them alternating
        firstHalf.reverse()

        newValues = []
        for i in range(len(lastHalf)):
            try:
                newValues.append(lastHalf[i])
            except:
                pass
            try:
                newValues.append(firstHalf[i])
            except:
                pass
            
        return newValues

    def complete_the_assignment(self, board: List[int], domains: Dict[V, Set[D]]) -> Optional[List[int]]:
        """
        Add variable/value pairs to assignment until it either fails a consistsency check or satisfies the constraints.
        :param board:
        :param domains:
        :return: a consistent assignment or None if no extension of assignment satisfies the constraints.
        """
        unassigned_variables: List[V] = [v for v in self.variables if board[v] is None]
        selected_variable = (unassigned_variables[0] if not self.first_fail else 
        # first fail (function created above)
        # get the variable with the shortest domain
        self.firstFail(domains, unassigned_variables)
                             )
        # print("selected variable: ", selected_variable)
        # Try all possible domain values of the selected variable
        possible_values = domains[selected_variable]
        adapted_possible_values = (possible_values if not self.central_domain_selection else 
        # central domain selection  (function created above)
        self.centralDomain(possible_values)
                                   )
        for selected_value in adapted_possible_values:
            # Extend the current assignment with: selected_variable: selected_value.
            # **assignment lists the elements of assignment.
            # So the following line creates a new dictiony with all the elements of
            # assignment plus the assignment to selected_variable.  selected_variable: selected_value
            extended_board = board.copy()
            extended_board[selected_variable] = selected_value
            self.assignment_count += 1
            reduced_domains = (domains if not self.propagation else
                               #         """ Complete the propagate method in queens.py """
                               self.apply_propagators(selected_variable, selected_value, domains)
                               )
            if self.assignment_limit:
                if self.assignment_count <= self.assignment_limit:
                    print(f'{self.assignment_count:2}. {extended_board}; reduced_domains: {reduced_domains}')
                else:
                    if not self.printed_reached_limit:
                        print(f'Reached the assignment_limit of {self.assignment_limit}. ')
                        self.printed_reached_limit = True
                    self.assignment_count = self.assignment_limit
                    return None
            if not self.is_consistent(extended_board):
                continue

            """ Your code goes here. """
            # If some unassigned variable has no possible values left, return None.
            isEmpty = True
            for domain in reduced_domains.items():
                if len(domain[1]) > 0:
                    isEmpty = False
                    break
            if isEmpty:
                # The board is consistent with the constraints. Is it complete? If so, return it as a solution.
                # A board is complete if every position has a value, i.e., there are no Nones.
                if None not in extended_board:
                    return extended_board
                return None

            # The assignment is consistent but not complete.
            # Use recursion to complete the assignment.
            # result will be either a valid assignment or None if no valid completion is found.
            result = self.complete_the_assignment(extended_board, reduced_domains)

            if result is None:
                # result will be None if we didn't find a valid assignment for board positions.
                # In that case, try the next value for selected_variable.
                continue
            else:
                # result is a valid assignment. Return it.
                return result

        # If no value for selected_variable yields a valid assignment, return None and
        # let the previous recursive level try the next value for its variable.
        return None

    def is_consistent(self, board: List[int]) -> bool:
        """
        Is this board consistent with all constraints?
        """
        return all(constraint(board) for constraint in self.constraints)