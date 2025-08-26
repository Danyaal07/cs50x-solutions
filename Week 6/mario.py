from cs50 import get_int

height = -1

while height > 8 or height < 1:
    height = get_int("Enter height: ")

i = 0
while i < height:

    for _ in range(height - i - 1):
        print(" ", end = "")

    for _ in range(i + 1):
        print("#", end = "")

    print("  ", end = "")

    for _ in range(i + 1):
        print("#", end = "")

    print()

    i += 1
