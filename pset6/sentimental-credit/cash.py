from cs50 import get_float


while True:
    change = get_float("Change: ")
    if (change > 0):
        break

count = 0
round(change, 2)
while change > 0:
    if (change - 0.25 >= 0):
        change -= 0.25
        change = round(change, 2)
        count += 1

    elif (change - 0.10 >= 0):
        change -= 0.10
        change = round(change, 2)
        count += 1

    elif (change - 0.05 >= 0):
        change -= 0.05
        change = round(change, 2)
        count += 1

    elif (change - 0.01 >= 0):
        change -= 0.01
        change = round(change, 2)
        count += 1
    else:
        count += 1
        break

print(count)
