getInts :: IO [Int]
getInts = map read . words <$> getLine

exec :: ([Int], Int) -> Int
exec (a, n) = if any odd a then n else exec (map (`div` 2) a, n + 1)

main :: IO ()
main = do
  _ <- getLine
  a <- getInts
  print $ exec (a, 0)
