# William F. Sampson
# williamsampson44444@gmail.com
# wfsampson
# Assignment 7: Binary Sets
# 3/31/17
# Status: Incomplete
# Function: Implements functions which determine if a relation meets the 
# requirements of a property

def is_reflexive(Set, Relation):
    ref = True
    for a in Set:
        if (a,a) not in Relation:
            ref = False
    return ref

def is_symmetric(Relation):
    ref = True
    for (a,b) in Relation:
        if(b,a) not in Relation:
            ref = False
    return ref
    
def is_antisymmetric(Relation):
    ref = True
    for (a,b) in Relation:
        if(b,a) in Relation:
            if(b != a):
                ref = False
    return ref

def is_transitive(Relation):
    for (a,b) in Relation:
        for (d,c) in Relation:
            if (b,c) in Relation:
                if (a,c) not in Relation:
                    return False
    return True

def composite(R1, R2):
    ref = set()
    for (a,b) in R1:
        for (c,d) in R2:
            if b == c:
                ref.add((a,d))
    return ref

def is_equivalence(Set, Relation):
    return (is_reflexive(Set, Relation) and is_symmetric(Relation) and is_transitive(Relation))
