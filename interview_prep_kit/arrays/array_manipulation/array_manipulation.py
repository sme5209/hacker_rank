#!/usr/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'arrayManipulation' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY queries
#

def arrayManipulation(n, queries):
    """
    Hashes boundary updates (+k on left-hand side and -k on right-hand side + 1),
     then sorts dict keys sequentially and sums over values to find max value
    :param n:
    :param queries:
    :return:
    """
    d = {}
    for query in queries:
        x, y, incr = tuple(query)
        d.setdefault(x, 0)
        d[x] = d[x] + incr
        if y <= n + 2:
            d.setdefault(y + 1, 0)
            d[y + 1] = d[y + 1] - incr

    maxx = 0
    x = 0

    for i in sorted(d):
        x += d[i]
        if maxx < x:
            maxx = x

    return maxx

# NOTE: none of this worked because of memory complexity

'''
def arrayManipulation(n, queries):
    diff_size = n + 1
    diff_list = [0] * diff_size

    for query in queries:
        a, b, k = tuple(query)
        a1 = a - 1
        b1 = b - 1
        diff_list[a1] += k
        diff_list[b1 + 1] -= k

    base_size = diff_size - 1
    max_idx = 0
    for i in range(1, base_size):
        diff_list[i] = diff_list[i] + diff_list[i - 1]
        if diff_list[i] > diff_list[max_idx]:
            max_idx = i
    return diff_list[max_idx]


def arrayManipulation(n, queries):
    base_list = [0] * n
    diff_list = build_diff_list(base_list)

    for query in queries:
        a, b, k = tuple(query)
        update_diff_list(diff_list, a, b, k)

    return update_base_list(diff_list, base_list)


def build_diff_list(base_list):
    diff_size = len(base_list) + 1
    diff_list = [0] * diff_size
    diff_list[0] = base_list[0]
    for i in range(1, diff_size - 1):
        diff_list[i] = base_list[i] - base_list[i - 1]
    return diff_list


def update_diff_list(diff_list, left, right, val):
    left1 = left - 1
    right1 = right - 1
    diff_list[left1] += val
    diff_list[right1 + 1] -= val


def update_base_list(diff_list, base_list):
    base_size = len(base_list)
    assert(base_size == len(diff_list) - 1)
    base_list[0] = diff_list[0]
    max_idx = 0
    for i in range(1, base_size):
        base_list[i] = diff_list[i] + base_list[i - 1]
        if base_list[i] > base_list[max_idx]:
            max_idx = i
    return base_list[max_idx]
'''


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    print(result)
