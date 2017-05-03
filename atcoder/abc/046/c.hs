import Control.Applicative
import Control.Monad

main = do
    n <- readLn
    ts <- map (map read . words) <$> replicateM n getLine
    putStrLn . show $ solve n ts

solve :: Int -> [[Int]] -> Int
solve n (f:ts) = sum $ foldl calc f ts

calc :: [Int] -> [Int] -> [Int]
calc [t, s] [nt, ns]
    | nt < t || ns < s = [nt*a, ns*a]
    | otherwise = [nt, ns]
    where
        a = max (timeTil nt t) (timeTil ns s)

timeTil :: Int -> Int -> Int
timeTil nt t
    | t `mod` nt == 0 = t `div` nt
    | otherwise = t `div` nt + 1
