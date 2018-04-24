import sys

def input_weight():
    return int(sys.stdin.readline())

def moon_weight(weight, increase_weight, max_year):
    for x in range(0, max_year):
        print(weight * (1 + 0.165))
        weight = weight+increase_weight;

def max_year():
    return int(sys.stdin.readline())

moon_weight(input_weight(), 0.25, max_year())
