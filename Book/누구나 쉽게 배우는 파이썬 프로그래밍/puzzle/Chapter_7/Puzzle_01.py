import sys

def input_weight():
    return int(sys.stdin.readline())

def moon_weight(weight, increase_weight):
    for x in range(0,15):
        print(weight * (1 + 0.165))
        weight = weight+increase_weight;

moon_weight(input_weight(), 0.25)
