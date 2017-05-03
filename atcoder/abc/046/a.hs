import Control.Applicative

main = do
    [a, b, c] <- map read . words <$> getLine
    putStrLn . show $ solve a b c

solve :: Int -> Int -> Int -> Int
solve a b c
    | a == b && b == c = 1
    | a == b || b == c || c == a = 2
    | otherwise = 3
