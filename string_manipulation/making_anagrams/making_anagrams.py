#!/usr/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'makeAnagram' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING a
#  2. STRING b
#

def makeAnagram(a, b):
    """
    Hashes matching chars between two words
    :param a:
    :param b:
    :return:
    """
    char_dict = {}
    matches = 0
    for char in a:
        if char in char_dict:
            char_dict[char] += 1
        else:
            char_dict[char] = 1
    for char in b:
        if char in char_dict and char_dict[char] > 0:
            matches += 1
            char_dict[char] -= 1

    return (len(a) - matches) + (len(b) - matches)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
