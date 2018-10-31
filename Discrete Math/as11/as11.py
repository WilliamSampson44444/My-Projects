# William F. Sampson
# williamsampson44444@gmail.com
# wfsampson
# Assignment 11: Properties of Functions
# 4/25/17
rangeVal = range(-(10**6), 10**6 + 1)

def is_function(function):
      for x in rangeVal:
            if(function(x) not in rangeVal):
                  return False
      return True

def is_partial(partial):
      for x in rangeVal:
            if(partial(x) in rangeVal):
                  return True
      return False

def is_injective(injective):
      if(is_function(injective)):
         y = set()
         for x in rangeVal:
               y.add(injective(x))      
         if(len(y) == 2 * 10**6 + 1):
               return True
      return False

def are_equivalent(fcn_1, fcn_2):
      if(is_function(fcn_1) and is_function(fcn_2)):
            for x in rangeVal:
                  if(fcn_1(x) != fcn_2(x)):
                        return False
            return True
      return False
