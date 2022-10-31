a, b = 1, 1
q = {1}
for i in range(0, 10**2) :
  x = q
  q.pop(0)
  print(x)
  q.append(x * a)
  q.append(x + b) 