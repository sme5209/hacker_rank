#!/usr/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'commonChild' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING s1
#  2. STRING s2
#


def commonChild(s1, s2):
    # try with s1 as outer loop
    count = get_count(s1, s2)
    return count


def get_count(string1, string2):
    count = 0
    s_len = len(string1)
    print(f"String length = {s_len}")
    start_idx1 = 0
    start_idx2 = 0
    no_match_set1 = set()
    no_match_set2 = set()
    min_list1 = []
    min_list2 = []
    max_list = []

    while True:
        min_idx11, min_idx12 = find_min_max(string1, string2, start_idx1, start_idx2, min_list1, min_list2, max_list,
                                            no_match_set1, s_len)
        min_idx21, min_idx22 = find_min_max(string1, string2, start_idx2, start_idx1, min_list2, min_list1, max_list,
                                            no_match_set2, s_len)
        max_idx1 = max(min_idx11, min_idx12)
        max_idx2 = max(min_idx21, min_idx22)
        min_idx1, min_idx2 = (min_idx11, min_idx12) if max_idx1 <= max_idx2 else (min_idx21, min_idx22)
        if min_idx1 >= s_len or min_idx2 >= s_len:
            break
        else:
            count += 1

    return count


def find_min_max(string1, string2, start_idx1, start_idx2, min_list1, min_list2, no_match_set, s_len):
    max_list = []
    match = False
    for j in range(start_idx1, s_len):
        for i in range(start_idx2, s_len):
            if string1[j] in no_match_set:
                break
            if string1[j] == string2[i]:
                min_list1.append(j)
                min_list2.append(i)
                max_list.append(max(j, i))
                match = True
                break
        if not match:
            no_match_set.add(string1[start_idx1])
    if max_list:
        min_idx = min(max_list)
        new_start_idx = max_list.index(min_idx)
        start_idx1 = min_list1[new_start_idx] + 1
        start_idx2 = min_list2[new_start_idx] + 1
        return start_idx1, start_idx2

    return None, None


if __name__ == '__main__':
    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    print(result)
