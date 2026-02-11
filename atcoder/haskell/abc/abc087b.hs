main :: IO ()
main = do
  a <- read <$> getLine :: IO Int
  b <- read <$> getLine :: IO Int
  c <- read <$> getLine :: IO Int
  x <- read <$> getLine :: IO Int
  let result = [(i, j, k) | i <- [0 .. a], j <- [0 .. b], k <- [0 .. c], 500 * i + 100 * j + 50 * k == x]
  print $ length result
