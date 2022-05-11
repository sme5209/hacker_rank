#!/usr/bin/python3

import math
import os
import random
import re
import sys


# Complete the substrCount function below.
def substrCount(n, s):
    """

    :param n:
    :param s:
    :return:
    """
    count = 0
    for idx, char in enumerate(s):
        chain = True
        right_hand_chars = 0
        left_hand_chars = 0
        for i in range(idx, n):
            if i == 0:
                count += 1
            else:
                if chain:
                    if s[i] == char:
                        count += 1
                    else:
                        left_hand_chars = i - idx
                        right_hand_chars = 0
                        chain = False
                else:
                    if s[i] == char:
                        right_hand_chars += 1
                        if left_hand_chars == right_hand_chars:
                            count += 1
                            break
                    else:
                        break
    return count


if __name__ == '__main__':
    n = int(input())

    s = input()

    result = substrCount(n, s)

    print(result)
