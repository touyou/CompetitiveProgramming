-- Ex5: Data.Map と Data.Set
--
-- (a) 文字列中の各文字の出現回数を Map で数える関数
--
-- (b) 2つのリストの共通要素を Set で求める関数
--
-- (c) リストから重複を除いて、元の順序を保ったまま返す関数
--     （Set を使って「見たことがあるか」を管理する）

import qualified Data.Map.Strict as Map
import qualified Data.Set as Set

-- (a) 各文字の出現回数
-- 例: charCount "hello" => fromList [('e',1),('h',1),('l',2),('o',1)]
-- 例: charCount "aaa" => fromList [('a',3)]
--
-- ヒント: foldl' と Map.insertWith (または Map.fromListWith)
charCount :: String -> Map.Map Char Int
charCount = undefined -- TODO

-- (b) 2つのリストの共通要素（Set で返す）
-- 例: commonElems [1,2,3,4] [3,4,5,6] => fromList [3,4]
-- 例: commonElems [1,2] [3,4] => fromList []
--
-- ヒント: Set.fromList してから Set.intersection
commonElems :: [Int] -> [Int] -> Set.Set Int
commonElems = undefined -- TODO

-- (c) 重複除去（順序保持）
-- 例: uniqueKeepOrder [3,1,4,1,5,9,2,6,5,3] => [3,1,4,5,9,2,6]
-- 例: uniqueKeepOrder "abracadabra" => "abrcd"
--
-- ヒント: Set を「見た要素の集合」として持ちながらリストを走査する再帰関数
--         補助関数 go :: Set.Set a -> [a] -> [a] を定義すると良い
uniqueKeepOrder :: Ord a => [a] -> [a]
uniqueKeepOrder = undefined -- TODO

main :: IO ()
main = do
  -- (a)
  print $ charCount "hello"       -- fromList [('e',1),('h',1),('l',2),('o',1)]
  print $ charCount "aaa"         -- fromList [('a',3)]
  -- (b)
  print $ commonElems [1,2,3,4] [3,4,5,6]  -- fromList [3,4]
  print $ commonElems [1,2] [3,4]           -- fromList []
  -- (c)
  print $ uniqueKeepOrder [3,1,4,1,5,9,2,6,5,3]  -- [3,1,4,5,9,2,6]
  print $ uniqueKeepOrder "abracadabra"            -- "abrcd"
