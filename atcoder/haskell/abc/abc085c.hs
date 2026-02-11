getInts :: IO [Int]
getInts = map read . words <$> getLine

head' :: [[Int]] -> [Int]
head' xs = case xs of
  (y : _) -> y
  [] -> [-1, -1, -1]

main :: IO ()
main = do
  [n, y] <- getInts
  let result = filter (\[a, b, c] -> a >= 0 && b >= 0 && c >= 0) [[a, b, c] | a <- [0 .. n], b <- [0 .. n - a], let c = n - a - b, 10000 * a + 5000 * b + 1000 * c == y]
  putStrLn $ unwords (map show (head' result))