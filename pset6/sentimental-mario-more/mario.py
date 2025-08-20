from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

spaces = height - 1

for _ in range(height):

    print(" " * spaces, end="")

    print("#" * (height - spaces), end="")

    print("  ", end="")

    print("#" * (height - spaces), end="")

    print("")
    spaces -= 1
