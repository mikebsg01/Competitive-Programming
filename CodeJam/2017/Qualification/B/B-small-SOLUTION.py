T = int(input())

for i in range(T):
  N = int(input())

  for j in range(N, 0, -1):
    s = str(j)
    solution = True

    for k in range(1, len(s)):
      if s[k] < s[k - 1]:
        solution = False
        break

    if solution:
      print("Case #" + str(i + 1) + ": " + s)
      break