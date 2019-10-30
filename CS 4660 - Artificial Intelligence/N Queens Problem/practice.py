from copy import copy
from timeit import default_timer as timer
from typing import Dict, List, Optional, Set

domains = {0: {0, 1, 2, 3, 4}, 1: {0, 1, 2, 3, 4},
           2: {0, 1, 2, 3, 4}, 3: {0, 1, 2, 3, 4},
           4: {0, 1, 2, 3, 4}}
print(domains)
selected_row = 1
selected_col = 2
# print(len(domains))
# for num in range(len(domains)):
#     if(num == selected_col):
#         domains[num].clear()
#     else:
#         domains[num].remove(selected_row)
# print(domains)

# zipped = list(zip([1, 2, 3, 4, 5], ['a','b','c','d','e']))
# print(zipped)
# unzipped = list(zip(*zipped))
# print(unzipped)


def getDiagonals(selected_column, selected_row, domains: Dict[int, Set[int]]):
    # newDomain: Dict[int, Set[int]] = copy(domains)
    length = len(domains)
    # because we know it must be a square, then the length of newDomain is the range for both x and y
    allDiagPos = []

    #appending top left
    for num, num2 in zip(range(selected_column - 1, -1, -1), range(selected_row - 1, -1, -1)):
        # topLeft.append(tuple((num,num2)))
        allDiagPos.append(tuple((num,num2)))
    
    #appending top right
    for num, num2 in zip(range(selected_column + 1, length, 1), range(selected_row - 1, -1 , -1)):
        # topRight.append(tuple((num,num2)))
        allDiagPos.append(tuple((num,num2)))

    #appending bottom right
    for num, num2 in zip(range(selected_column + 1, length, 1), range(selected_row + 1, length, 1)):
        # bottomRight.append(tuple((num,num2)))
        allDiagPos.append(tuple((num,num2)))

    #appending bottom left
    for num, num2 in zip(range(selected_column - 1, -1, -1), range(selected_row + 1, length, 1)):
        # bottomLeft.append(tuple((num,num2)))
        allDiagPos.append(tuple((num,num2)))
    
    print(allDiagPos)

# print("getting diagonals: ", getDiagonals(1,1, domains))
getDiagonals(2,2, domains)
