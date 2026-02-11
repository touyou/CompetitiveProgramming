-- Ex4: fold と scan
--
-- (a) foldl' を使って、リストの最大値を求める関数を実装せよ。
--     (Data.List の maximum を使わずに)
--
-- (b) scanl を使って、累積和を求める関数を実装せよ。
--     先頭に 0 を含む形で返すこと。
--
-- (c) (b) の累積和を使って、区間和を求める関数を実装せよ。
--     rangeSum xs l r = xs[l] + xs[l+1] + ... + xs[r] (0-indexed)

import Data.List (foldl')

-- (a) リストの最大値（空リストの場合は minBound を返す）
-- 例: myMaximum [3,1,4,1,5,9] => 9
-- 例: myMaximum [-5,-3,-1] => -1
--
-- ヒント: foldl' f 初期値 リスト の形。初期値は minBound が使える
myMaximum :: [Int] -> Int
myMaximum = foldl' max minBound

-- (b) 累積和（先頭に 0 を含む）
-- 例: cumSum [1,2,3,4] => [0,1,3,6,10]
-- 例: cumSum [5,5,5] => [0,5,10,15]
--
-- ヒント: scanl を使えば1行で書ける
cumSum :: [Int] -> [Int]
cumSum x = scanl (+) 0 x

-- (c) 区間和 (0-indexed, l と r は両端含む)
-- 例: rangeSum [1,2,3,4] 1 3 => 9  (2+3+4)
-- 例: rangeSum [1,2,3,4] 0 0 => 1
-- 例: rangeSum [10,20,30] 0 2 => 60
--
-- ヒント: cumSum の結果を cs とすると cs!!(r+1) - cs!!l
rangeSum :: [Int] -> Int -> Int -> Int
rangeSum xs l r = cumSum xs !! (r + 1) - cumSum xs !! l

main :: IO ()
main = do
  -- (a)
  print $ myMaximum [3, 1, 4, 1, 5, 9] -- 9
  print $ myMaximum [-5, -3, -1] -- -1
  -- (b)
  print $ cumSum [1, 2, 3, 4] -- [0,1,3,6,10]
  print $ cumSum [5, 5, 5] -- [0,5,10,15]
  -- (c)
  print $ rangeSum [1, 2, 3, 4] 1 3 -- 9
  print $ rangeSum [1, 2, 3, 4] 0 0 -- 1
  print $ rangeSum [10, 20, 30] 0 2 -- 60
