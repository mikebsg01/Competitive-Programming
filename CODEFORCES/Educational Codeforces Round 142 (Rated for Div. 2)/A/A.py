from sys import stdin

def readLine():
  return stdin.readline().strip()

def readInt():
  return int(readLine())

def readInts():
  return list(map(int, readLine().split()))

T, N = 0, 0

def main():
  T = readInt()
  for i in range(T):
    N = readInt()
    ans = N
    A = readInts()
    A.sort()
    if A[0] == 1:
      j = 1
      while j < N:
        if A[j] == 1:
          ans -= 1
        j += 2
    print(ans)


if __name__ == '__main__':
  main()