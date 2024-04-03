# TODO
from cs50 import get_int

while True:
    try:
        height = get_int("Height: ")
        if height <= 8 and height >= 1:
            break
    except:
        ValueError("Enter an integer between 1-8 inclusive.")

for i in range(height):
    print((height - i - 1) * " ", end="")
    print((i + 1) * "#", end="")
    print()
