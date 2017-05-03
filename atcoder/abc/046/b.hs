import Control.Applicative

main = do
    [n, k] <- map read . words <$> getLine
    putStrLn . show $ solve n k

solve :: Int -> Int -> Int
solve 1 k = k
solve n k = (k - 1) * (solve (n-1) k)
