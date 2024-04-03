import sys

import random
from pyfiglet import Figlet

figlet = Figlet()
if len(sys.argv) == 1:
    # choose random font
    text = input("Input: ")
    font_list = figlet.getFonts()
    rand_num = random.randint(0, 549)
    figlet.setFont(font=str(font_list[rand_num]))
    print(figlet.renderText(text))

elif len(sys.argv) == 3:
    # check argv[1] == -f or --font and argv[2] fontname in figlet's font list
    if (sys.argv[1] == "-f" or sys.argv[1] == "--font") and (
        sys.argv[2] in figlet.getFonts()
    ):
        text = input("Input: ")
        figlet.setFont(font=sys.argv[2])
        print(figlet.renderText(text))
    else:
        print("Invalid Usage")
        sys.exit(1)


else:
    print("Invalid Usage")
    sys.exit(1)
