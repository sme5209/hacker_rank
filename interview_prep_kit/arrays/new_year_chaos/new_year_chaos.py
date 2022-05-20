#!/usr/bin/python3

import math
import os
import random
import re
import sys
from collections import deque
import logging


#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#

def minimumBribes(q):
    """
    Accumulates positive position changes, accumulates relative
     positions of all neutral or negative position changes
     (meaning that values not shifted or shifted negatively
     are checked for relative ordering)
    :param q:
    :return:
    """
    running_sum = 0
    jumped_ppl = deque()
    for idx, value in enumerate(q):
        idx1 = idx + 1  # base-1 array index
        diff = value - idx1

        if diff > 2:  # special case
            print("Too chaotic")
            return
        # normal case
        elif diff > 0:
            running_sum += diff
        else:  # diff <= 0
            # keep jumped_ppl deque to size of <= 10
            # NOTE: probabilistic approach, there could be more than
            # 10 consecutive jumped values
            for jumped_value in jumped_ppl:
                if jumped_value > value:
                    running_sum += 1
            jumped_ppl.append(value)
            if len(jumped_ppl) > 10:
                jumped_ppl.popleft()

    print(running_sum)


if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
