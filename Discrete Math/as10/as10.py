# William F. Sampson
# williamsampson44444@gmail.com
# wfsampson
# Assignment 10: No O Bigger
# as10.py - Full program file for Assignment 10.
# 4/18/17
# Function: Given a program which takes a single int as input to increase how 
# long it takes to complete, determines the big O order of that program

from timeit import Timer, sys
from subprocess import call

times = []
t = Timer(lambda:call([sys.argv[1], str(1024)]))#Setup for the times
t2 = Timer(lambda:call([sys.argv[1], str(2048)]))

t.timeit(number = 1)#Cacheing the program to reduce overhead
times.append(t.timeit(number = 3)/3)#Initial time
times.append(t2.timeit(number = 3)/3)#Time of doubled set

#Some quick arithmetic
const = abs(times[0] - times[1])
log = abs(times[0] * 1.1 - times[1])
line = abs(times[0] * 2 - times[1])
linmic = abs(times[0] * 2 * 1.1 - times[1])
quad = abs(times[0] * 4 - times[1])
cubic = abs(times[0] * 8 - times[1])

# Ugly block of elifs
if const < log:
    print("O(1)")
elif log < line:
    print("O(log n)")
elif line < linmic:
    print("O(n)")
elif linmic < quad:
    print("O(n log n)")
elif quad < cubic:
    print("O(n^2)")
else:
    print("O(n^3)")

