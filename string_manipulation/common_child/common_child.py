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
    count1 = get_count(s1, s2)
    print(f"count1 = {count1}")
    # try with s2 as outer loop
    count2 = get_count(s2, s1)
    print(f"count2 = {count2}")
    return max(count1, count2)


def get_count(string1, string2):
    no_match_set1 = set()
    count = 0
    s_len = len(string1)
    print(f"String length = {s_len}")
    start_idx2 = 0
    child_list = []
    for k in range(s_len):
        start_idx1 = k
        while True:
            min_list1 = []
            min_list2 = []
            max_list = []
            for j in range(start_idx1, s_len):
                # print(f"Outer loop index = {j}")
                if string1[j] in no_match_set1:
                    continue
                match = False
                for i in range(start_idx2, s_len):
                    if string1[j] == string2[i]:
                        min_list1.append(j)
                        min_list2.append(i)
                        # max_list.append(max(j, i))
                        match = True
                        break
                if not match:
                    no_match_set1.add(string1[j])
            if min_list2:
                count += 1
                min_idx = min(min_list2)
                start_idx2 = min_idx + 1
                if start_idx2 >= s_len:
                    break
                start_idx1 = min_list1[min_list2.index(min_idx)] + 1
                if start_idx1 >= s_len:
                    break
                print(f"New s1 index = {start_idx1}, new s2 index = {start_idx2}")
            else:
                break
        child_list.append(count)

    print(child_list)
    return max(child_list)


if __name__ == '__main__':
    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    print(result)
