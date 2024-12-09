import turtle
import os
import sys

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
    wn = turtle.Screen()
    wn.title("L-system")
    turtle.tracer(0, 0)
    skk = turtle.Turtle()
    turtle.Screen().setworldcoordinates(-500, -500, turtle.Screen().window_width() - 1, turtle.Screen().window_height() - 1)
    skk.shapesize(stretch_wid=.1, stretch_len=.1, outline=.1)  
    skk.left(90)
    
    for letter in readFile():
        if letter in ["F","G"]:            
            skk.forward(TURTLE_RANGE)
        elif letter == "-":
            skk.right(DEGREES)
        elif letter == "+":
            skk.left(DEGREES)
        
    turtle.update()
    turtle.Screen().exitonclick()

if __name__ == "__main__":
    main()