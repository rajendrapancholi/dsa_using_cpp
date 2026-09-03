class Solution
{
private:
  int helper(int n)
  {
    if (n == 0 || n == 1)
      return n;
    return helper(n - 1) + helper(n - 2);
  }

public:
  int fib(int n)
  {
    return helper(n);
  }
};