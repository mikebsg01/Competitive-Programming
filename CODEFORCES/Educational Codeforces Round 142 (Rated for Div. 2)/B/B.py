from sys import stdin

def readLine():
  return stdin.readline().strip()

def readInt():
  return int(readLine())

def readInts():
  return list(map(int, readLine().split()))

T, N = 0, 0

def canTellJokes(moodA, moodB, a, b, x):
  return moodA >= 0 and moodB >=0 and (a + b + x) > 0

def main():
  T = readInt()

  for i in range(T):
    ab, a, b, x = readInts()
    moodA, moodB = ab, ab
    ans = ab
    ab = 0
    while canTellJokes(moodA, moodB, a, b, x):
      maxJokes = 0
      if b > 0 and moodA > 0:
        maxJokes = min(moodA, b)
        b -= maxJokes
        moodA -= maxJokes
        moodB += maxJokes
      elif a > 0 and moodB > 0:
        maxJokes = min(moodB, a)
        a -= maxJokes
        moodB -= maxJokes
        moodA += maxJokes
      elif moodA > 0 and moodB > 0 and x > 0:
        maxJokes = min(min(moodA, moodB), x)
        x -= maxJokes
        moodA -= maxJokes
        moodB -= maxJokes
      else:
        maxJokes = 1
        moodA -= maxJokes
        moodB -= maxJokes
      ans += maxJokes
    print(ans)

if __name__ == '__main__':
  main()
