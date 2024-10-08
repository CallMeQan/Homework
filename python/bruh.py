# input n, generate an array with random number, size of n
from math import sqrt
import random
n = int(input("Input n: "))
arr = []
for i in range(n):
    arr.append(random.randint(0, 100))

def isPerfectSquare(n):
  root = sqrt(n)
  return root * root == n

for num in arr:
    if isPerfectSquare(num):
        print(num)
          