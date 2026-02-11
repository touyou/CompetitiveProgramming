import Data.List (isPrefixOf)

judge :: String -> Bool
judge s
  | "maerd" `isPrefixOf` s = judge (drop 5 s)
  | "remaerd" `isPrefixOf` s = judge (drop 7 s)
  | "esare" `isPrefixOf` s = judge (drop 5 s)
  | "resare" `isPrefixOf` s = judge (drop 6 s)
  | s == "" = True
  | otherwise = False

main :: IO ()
main = do
  s <- getLine
  let revS = reverse s
  putStrLn (if judge revS then "YES" else "NO")
