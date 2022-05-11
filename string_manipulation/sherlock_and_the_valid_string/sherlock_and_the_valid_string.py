#!/usr/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    """
    TODO: clean up logic
    :param s:
    :return:
    """
    freq_dict = {}
    is_valid = True
    for char in s:
        if char in freq_dict:
            freq_dict[char] += 1
        else:
            freq_dict[char] = 1
    print(freq_dict)

    match_dict = {}
    for freq in freq_dict.values():
        if freq in match_dict:
            match_dict[freq] += 1
        else:
            match_dict[freq] = 1
    print(match_dict)

    if len(match_dict.values()) == 1:
        print("Only 1 freq")
        return "YES"
    elif len(match_dict.values()) > 2:
        print("More than 2 freqs")
        return "NO"

    count_list = []
    for items in match_dict.items():
        freq = items[0]
        count = items[1]
        count_list.append((freq, count))

    freq0 = count_list[0][0]
    freq1 = count_list[1][0]
    count0 = count_list[0][1]
    count1 = count_list[1][1]

    print(f"2 freqs ({freq0} and {freq1}) with counts {count0} and {count1}, respectively")
    if (abs(freq0 - freq1) > 1 and not (freq0 * count0 == 1 or freq1 * count1 == 1)) or (count0 > 1 and count1 > 1):
        return "NO"
    else:
        return "YES"


if __name__ == '__main__':
    s = input()

    result = isValid(s)

    print(result)
