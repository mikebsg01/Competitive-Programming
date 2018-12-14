def isTidy(s):
  for i in range(len(s) - 1):
    if s[i + 1] < s[i]:
      return False
  return True

T = int(input())

for i in range(T):
  N = int(input())
  S = str(N)

  while not isTidy(S):
    for j in range(len(S) - 1):
      if S[j + 1] < S[j]:
        tmp = list(S)
        tmp[j] = str(int(S[j]) - 1)
        for k in range(j + 1, len(S)):
          tmp[k] = str(9)
        S = "".join(tmp)
    tmp = list(S)

    if S[0] == '0':
      S = S[1:len(S)]

  print("Case #" + str(i + 1) + ": " + S)

    