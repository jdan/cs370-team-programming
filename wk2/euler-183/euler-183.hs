-- gcd used to reduce fractions
-- gcd :: Integral a => a -> a -> a
-- gcd a 0 = a
-- gcd a b = gcd b $ mod a b

terminates :: Integral a => a -> Bool
terminates 1 = True
terminates n
  | (mod n 2) == 0 = terminates $ n / 2
  | (mod n 5) == 0 = terminates $ n / 5
  | otherwise      = False

main = do
  putStrLn $ terminates 10
