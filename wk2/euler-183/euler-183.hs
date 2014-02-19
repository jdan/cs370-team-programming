-- Euler 183 Solution
-- by Jordan Scales (for CS370)
-- Feb 19, 2014
-- https://projecteuler.net/problem=183

-- Determines whether the given denominator of a reduced fraction leads to
-- a terminating decimal
terminates :: Integral a => a -> Bool
terminates 1 = True
terminates n
  | (mod n 2) == 0 = terminates $ div n 2
  | (mod n 5) == 0 = terminates $ div n 5
  | otherwise      = False

main = do
  putStrLn $ show solution
    where
      -- ΣD(N) for 5 ≤ N ≤ 10000
      solution = sum [d(i) | i <- [5..10000]]
      -- Let D(N) = N if M(N) is a non-terminating decimal and
      -- D(N) = -N if M(N) is a terminating decimal.
      d n
        | terminates m = -n
        | otherwise    =  n
        where
          -- M(n) = Pmax
          -- For our purposes, m refers to the reduced denominator of
          --   n / k, where M(n) is normally (n/k)^k
          -- k = round(n / e)
          m = div pmax $ gcd pmax n
          pmax = round $ (realToFrac n) / (exp 1)
