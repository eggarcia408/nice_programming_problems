#!/usr/bin/python3



def balancedBrackets(strInput):

    openBrackets = ["[","(","{", "<"]
    bracketMapping = {"]":"[",")":"(","}":"{", ">":"<"}
    closedBrackets = list(bracketMapping.keys())

    #will treat current list as a stack
    current = []
    top = -1

    for c in strInput:
        if c in openBrackets:
            current.append(c)
        elif c in closedBrackets:
            #checking if stack is empty
            #name of list itself is considered false if its empty
            #if list is not empty, the name of list is considered true
            if not current:
                return "False"
            #unmatching/unbalanced brackets
            elif bracketMapping[c] != current[len(current) - 1]:
                return "False"
            else:
                #if no index specified in pop,
                #that means it removes last element in list
                current.pop()

    if not current:
        return "True"
    else:
        return "False"

string = str(raw_input())

if balancedBrackets(string) == "True":
    print("Balanced")
else:
    print("Not Balanced")
