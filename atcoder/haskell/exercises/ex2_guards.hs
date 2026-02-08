-- Ex2: ガードと where
--
-- 整数 n を受け取り、FizzBuzz判定を返す関数を
-- ガード (|) と where を使って実装せよ。
--
-- ルール:
--   15の倍数 → "FizzBuzz"
--   3の倍数  → "Fizz"
--   5の倍数  → "Buzz"
--   それ以外 → 数値を文字列にして返す (show n)
--
-- ヒント: where で `mod` の結果を束縛すると綺麗に書ける

fizzBuzz :: Int -> String
fizzBuzz n
  | x == 0 = "FizzBuzz"
  | y == 0 = "Buzz"
  | z == 0 = "Fizz"
  | otherwise = show n
  where
    (_, x) = divMod n 15
    (_, y) = divMod n 5
    (_, z) = divMod n 3

main :: IO ()
main = do
  putStrLn $ fizzBuzz 15 -- 期待値: "FizzBuzz"
  putStrLn $ fizzBuzz 9 -- 期待値: "Fizz"
  putStrLn $ fizzBuzz 10 -- 期待値: "Buzz"
  putStrLn $ fizzBuzz 7 -- 期待値: "7"
  let results = map fizzBuzz [1 .. 15]
  putStrLn $ unwords results
