-- Ex3: パターンマッチの発展
--
-- (a) asパターン (@) を使う問題
--     リストの先頭要素が最大値なら True を返す関数。
--     リスト全体と先頭要素の両方が必要になる場面。
--
-- (b) ネストしたパターンマッチを使う問題
--     2つのソート済みリストをマージして1つのソート済みリストにする関数。
--     （マージソートの merge 部分）

-- (a) 先頭が最大値か？
-- 例: headIsMax [5,3,1,2] => True
-- 例: headIsMax [3,5,1,2] => False
-- 例: headIsMax [7] => True
-- 例: headIsMax [] => False
--
-- ヒント: xs@(x:_) のように書くと xs でリスト全体、x で先頭が取れる
headIsMax :: [Int] -> Bool
headIsMax = undefined -- TODO

-- (b) ソート済みリストのマージ
-- 例: mergeSorted [1,3,5] [2,4,6] => [1,2,3,4,5,6]
-- 例: mergeSorted [1,1] [1,2] => [1,1,1,2]
-- 例: mergeSorted [] [1,2,3] => [1,2,3]
--
-- ヒント: 両方のリストの先頭を比較して小さい方を取る再帰
mergeSorted :: [Int] -> [Int] -> [Int]
mergeSorted = undefined -- TODO

main :: IO ()
main = do
  -- (a) テスト
  print $ headIsMax [5,3,1,2]   -- True
  print $ headIsMax [3,5,1,2]   -- False
  print $ headIsMax [7]          -- True
  print $ headIsMax []           -- False
  -- (b) テスト
  print $ mergeSorted [1,3,5] [2,4,6]   -- [1,2,3,4,5,6]
  print $ mergeSorted [1,1] [1,2]       -- [1,1,1,2]
  print $ mergeSorted [] [1,2,3]        -- [1,2,3]
  print $ mergeSorted [10,20] []        -- [10,20]
