#!/usr/bin/python3

import math
import os
import random
import re
import sys


# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    """
    Iterates over list, swapping each entry until it is in the correct location
    :param arr:
    :return:
    """
    swap_count = 0
    swap_map = {}

    # get all out-of-order entries in array
    for idx, entry in enumerate(arr):
        idx1 = idx + 1
        if idx1 != entry:
            swap_map[entry] = idx1

    for value in swap_map:
        # skip if entry and value are equal
        if swap_map[value] == value:
            continue
        swap_index = -1
        while value != swap_index:
            index = swap_map[value]
            swap_index = swap_map[index]
            swap_map[index] = index
            swap_count += 1
            swap_map[value] = swap_index

    return swap_count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
