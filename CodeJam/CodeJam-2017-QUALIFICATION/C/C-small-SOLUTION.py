S = []
N = 0

def simulate():
  maxMinLR = 0
  maxMaxLR = 0
  pos = 1

  for i in range(1, N + 1):
    if S[i] == 0:
      left = right = 0
      j = i - 1
      k = i + 1

      while j >= 0 and S[j] == 0:
        left = left + 1
        j = j - 1
        # print("j: " + str(j))

      while k < (N + 2) and S[k] == 0:
        right = right + 1
        k = k + 1
        # print("k: " + str(k))
        
      minLR = min(left, right)
      maxLR = max(left, right)

      # print("left: " + str(left) + " right: " + str(right))
      # print("minLR: " + str(minLR) + " maxLR: " + str(maxLR))

      if minLR > maxMinLR:
        maxMinLR = minLR
        maxMaxLR = maxLR
        pos = i
        # print("1 - MaxMinLR: " + str(maxMinLR) + " maxMaxLR: " + str(maxMaxLR) + " pos: " + str(pos))
      elif minLR == maxMinLR and maxLR > maxMaxLR:
        maxMaxLR = maxLR
        pos = i
        # print("2 - MaxMinLR: " + str(maxMinLR) + " maxMaxLR: " + str(maxMaxLR))
    else:
      left = 0

  S[pos] = 1
  return [pos, maxMaxLR, maxMinLR]

T = int(input())

for i in range(1, T + 1):
  tmp = input().split(' ')
  N = int(tmp[0])
  K = int(tmp[1])

  S = [0] * (N + 2)
  S[0] = 1
  S[N + 1] = 1
  
  for j in range(K):
    result = simulate()

  """
  for i in range(N + 2):
    print(str(i) + " ", end='')
  print()

  for i in range(N + 2):
    print(str(S[i]) + " ", end='')
  print()
  """

  print("Case #" + str(i) + ": " + str(result[1]) + " " + str(result[2]))