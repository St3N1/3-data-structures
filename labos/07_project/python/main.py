import turtle
import os
import sys
import math
from pprint import pprint

BASEDIR = os.path.dirname(os.path.abspath(__file__))
FILENAME = BASEDIR + "/L-system.txt"
TURTLE_RANGE = 10
DEGREES = float(sys.argv[1])

def readFile():
    f = open(FILENAME)
    content = f.read().splitlines()
    f.close()
    return str(content)[1:-1]

def main():
    # wn = turtle.Screen()
    # wn.title("L-system")
    # turtle.tracer(0, 0)
    # skk = turtle.Turtle()
    # turtle.Screen().setworldcoordinates(-500, -500, turtle.Screen().window_width() - 1, turtle.Screen().window_height() - 1)
    # skk.shapesize(stretch_wid=.1, stretch_len=.1, outline=.1)  
    # skk.left(90)
    
    # for letter in readFile():
    #     if letter in ["F","G"]:            
    #         skk.forward(TURTLE_RANGE)
    #     elif letter == "-":
    #         skk.right(DEGREES)
    #     elif letter == "+":
    #         skk.left(DEGREES)
        
    # turtle.update()
    # turtle.Screen().exitonclick()
    Ru(DEGREES)
    Rl(DEGREES)
    Rh(DEGREES)

def Ru(alpha:float):
    ru = [
        [math.cos(alpha), math.sin(alpha), 0],
        [-math.sin(alpha), math.cos(alpha), 0],
        [0, 0, 1]
    ]
    pprint(ru)

def Rl(alpha:float):
    rl = [
        [math.cos(alpha), 0, -math.sin(alpha)],
        [0, 1, 0],
        [math.sin(alpha), 0, math.cos(alpha)]
    ]
    pprint(rl)
    
def Rh(alpha:float):
    rh = [
        [1, 0, 0],
        [0, math.cos(alpha), -math.sin(alpha)],
        [0, math.sin(alpha), math.cos(alpha)]
    ]
    pprint(rh)


if __name__ == "__main__":
    main()