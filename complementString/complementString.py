#!/usr/bin/python3

import sys

'''
    Bases in the DNA are: A,T,C,G
    The complement of each base are the following:
        A --> T
        T --> A
        C --> G
        G --> C

    The program takes input a string with bases only, reverses the string and
    output the complement of the string
        Example:
            Input is: AACGTA
            OutPut is: TACGTT

            Explanation: The reverse string of input string is: ATGCAA
                         Complement of each character in the string is: TACGTT

'''

def check(s,com):

    for c in s:
        if c not in com.keys():
            print("Input String has an unrecognized DNA Base")
            sys.exit(0)


complements = {"A":"T", "T":"A", "C":"G", "G":"C"}
complement_string = ""
original_string = str(input()).upper()

check(original_string, complements)

reverse_string = original_string[::-1]

for c in reverse_string:
    complement_string = complement_string + complements[c]

print(complement_string)





