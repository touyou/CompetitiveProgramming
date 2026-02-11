import Data.List (nub)

main :: IO ()
main = do
  n <- read <$> getLine :: IO Int
  d <- sequence [read <$> getLine :: IO Int | _ <- [1 .. n]]
  let result = nub d
  print $ length result
