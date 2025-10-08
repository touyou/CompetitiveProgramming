import Data.List (sort)

getInts :: IO [Int]
getInts = map read . words <$> getLine

main :: IO ()
main = do
  _ <- getLine
  a <- getInts
  let sorted = sort a
  let oddA = [x | (i, x) <- zip [1 ..] sorted, odd i]
  let evenA = [x | (i, x) <- zip [1 ..] sorted, even i]
  let diff = sum oddA - sum evenA
  print . abs $ diff
