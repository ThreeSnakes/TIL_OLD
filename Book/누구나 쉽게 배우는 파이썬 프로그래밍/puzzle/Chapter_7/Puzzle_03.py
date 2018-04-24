import sys

def input_value():
    return (sys.stdin.readline())

def moon_weight():
    for x in range(0, max_year):
        global weight
        print(weight * (1 + 0.165))
        weight = weight + increase_weight
    
print("Please enter your current Earth weight")
weight = float(input_value())
print("Please enter the amount your weight might increase each year")
increase_weight = float(input_value())
print("Please enter the number of years")
max_year = int(input_value())

moon_weight()
