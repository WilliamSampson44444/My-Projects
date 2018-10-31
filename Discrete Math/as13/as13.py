# William Sampson
# williamsampson44444@gmail.com
# wfsampson
# Assignment 13: Shortest Paths
# 5/9/17
# Status: Incomplete

import sys, collections, queue

graph = collections.defaultdict(dict)
nodeset = set()

for line in sys.stdin:
    srcdst = line.split()
    graph[srcdst[0]][srcdst[1]] = srcdst[2] # Syntax: src, dst = weight
    nodeset.add((srcdst[0], None, -1))
    nodeset.add((srcdst[1], None, -1)) # Syntax: node,parent,distance

nodes = list()
for x in nodeset:
    nodes.append(x)
    
# Dijkstra's Algorithm - probably need to fix implementation
pq = queue.PriorityQueue(0)
pq.put((sys.argv[1], None, 0))

while(not pq.empty()):
    curShortest = pq.get()
    for x in graph[curShortest[0]]:
        weight = graph[curShortest[0], curShortest[1]]
        if curShortest[2] is not -1 and x[2] > curShortest[2] + weight:
            x[2] = curShortest[2] + graph[curShortest[1], curShortest[0]]
            x[1] = curShortest[0]
            pq.put(x)


# Do not question, only accept.
curNode = tuple((str(), str(), int()))
for x in nodes:
    if x[0] == sys.argv[2]:
        curNode = x
if curNode[2] is -1: # Definitely works
    print("No path from", sys.argv[1], "to", sys.argv[2])
else:# Might work
    toPrint = str(curNode[0])+" "+str(curNode[1])+" "+str(curNode[2])+".00"
    while curNode[2] is not 0:
        for x in nodes:
            if x[1] is not None and x[1][0] == curNode[1]:
                curNode = nodes[x]
        toPrint = str(curNode[0]) + " --> " + toPrint
    print(toPrint)
        
