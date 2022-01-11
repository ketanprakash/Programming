dp = [0 for i in range(10000)]
def fib(n):
  if dp[n] != 0:
    return dp[n]
  if n == 0 or n == 1:
    dp[n] = n
    return n
  dp[n] = fib(n - 1) + fib(n - 2)
  return dp[n]

n = int(input())
for i in range(0, n + 1):
  print(fib(i), end = " ")