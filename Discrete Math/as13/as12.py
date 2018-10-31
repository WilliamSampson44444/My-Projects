# William Sampson
# williamsampson44444@gmail.com
# wfsampson
# Assignment 12: Strongly connected Graph
# 5/2/17
# Status: Complete

import sys, collections

graph = collections.defaultdict(dict)
nodes = set()
visited = []

for line in sys.stdin:
    srcdst = line.split()
    graph[srcdst[0]][srcdst[1]] = True
    nodes.add(srcdst[0])
    nodes.add(srcdst[1])

for x in nodes:
    visited.clear()
    Stack = []
    Stack.append(x)
    visited.append(x)
    while(len(Stack) is not 0):
        node = Stack.pop(0)
        for y in graph[node]:
            if y not in visited:
                visited.append(y)
                Stack.append(y)

    if len(visited) is not len(nodes):
        print("False")
        exit(0)
    visited.clear()

print("True")


    
