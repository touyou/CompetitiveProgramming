-- Ex1: 関数合成とポイントフリー
--
-- 整数のリストを受け取り、
-- 「偶数だけ残す → 各要素を2倍する → 合計を求める」
-- をポイントフリースタイル（引数を書かない形）で実装せよ。
--
-- 例: solve [1,2,3,4,5] => 12   (2*2 + 4*2 = 12)
-- 例: solve [10,15,20] => 60    (10*2 + 20*2 = 60)
-- 例: solve [1,3,5] => 0

solve :: [Int] -> Int
solve = sum . map (* 2) . filter even

main :: IO ()
main = do
  print $ solve [1, 2, 3, 4, 5] -- 期待値: 12
  print $ solve [10, 15, 20] -- 期待値: 60
  print $ solve [1, 3, 5] -- 期待値: 0
  print $ solve [] -- 期待値: 0
  putStrLn $
    if all id [solve [1, 2, 3, 4, 5] == 12, solve [10, 15, 20] == 60, solve [1, 3, 5] == 0]
      then "OK!"
      else "NG..."
