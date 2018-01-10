import random

input = open("exemple.txt", "r").read().split()
output = open("aplicatii.in", "w")

def randrange(a, b):
    return " " + str(random.randint(a, b))

for name in input:
    output.writelines(name + randrange(10, 3000) + randrange(1, 28) + randrange(1, 12) + randrange(2012, 2017) + "\n")

output.close()