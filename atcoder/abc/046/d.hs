main = do
    s <- getLine
    putStrLn . show $ solve s

solve :: String -> Int
solve s = let (_,_,score) = foldl maximizer (0,0,0) s in score

maximizer :: (Int, Int, Int) -> Char -> (Int, Int, Int)
maximizer (p, g, score) hand
    | hand == 'g' && p < g = (p+1, g, score+1)
    | hand == 'g' && p >= g = (p, g+1, score)
    | hand == 'p' && p < g = (p+1, g, score)
    | hand == 'p' && p >= g = (p, g+1, score-1)
