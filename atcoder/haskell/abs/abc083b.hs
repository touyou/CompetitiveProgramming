getInts :: IO [Int]
getInts = map read . words <$> getLine

main :: IO ()
main = do
  [n, a, b] <- getInts
  let results = [i | i <- [1 .. n], let s = sum $ map (read . (: [])) (show i), a <= s && s <= b]
  print $ sum results
