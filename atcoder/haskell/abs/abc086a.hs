ints :: IO [Int]
ints = map read . words <$> getLine

main :: IO ()
main = do
  inputs <- ints
  putStrLn (if any even inputs  then "Even" else "Odd")
