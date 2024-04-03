from cs50 import get_float

quarters = 0
dimes = 0
nickels = 0
pennies = 0

while True:
    cents = get_float("Change Owed: ")
    if cents > 0:
        break

# This line makes 0.49999 to 50
cents = round(cents * 100)

while cents > 0:
    if cents >= 25:
        cents -= 25
        quarters += 1
    elif cents >= 10:
        cents -= 10
        dimes += 1
    elif cents >= 5:
        cents -= 5
        nickels += 1
    else:
        cents -= 1
        pennies += 1

print(quarters + dimes + nickels + pennies)
