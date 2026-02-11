-- Ex6: Maybe を使いこなす
--
-- 学校の成績管理。生徒名から点数を引き、成績判定する。
-- 存在しない生徒の場合は安全に処理すること。

import Data.Map.Strict qualified as Map
import Data.Maybe (fromMaybe)

scores :: Map.Map String Int
scores = Map.fromList [("Alice", 85), ("Bob", 62), ("Carol", 91), ("Dave", 45)]

-- (a) 生徒の点数を取得し、ランク文字列を返す
--     存在しない生徒なら "Unknown"
--     90以上: "A", 70以上: "B", 50以上: "C", それ以外: "D"
--
-- 例: getRank "Alice" => "B"
-- 例: getRank "Carol" => "A"
-- 例: getRank "Dave"  => "D"
-- 例: getRank "Eve"   => "Unknown"
--
-- ヒント: Map.lookup で Maybe Int を取得し、
--         maybe を使って Nothing/Just の処理を分ける。
--         ランク判定にはガードが使える。
getRank :: String -> String
getRank name = maybe "Unknown" toRank (Map.lookup name scores)

toRank :: Int -> String
toRank v
  | v >= 90 = "A"
  | v >= 70 = "B"
  | v >= 50 = "C"
  | otherwise = "D"

-- (b) 2人の生徒の点数の差を求める。
--     どちらかが存在しなければ Nothing を返す。
--
-- 例: scoreDiff "Alice" "Bob"  => Just 23
-- 例: scoreDiff "Alice" "Eve"  => Nothing
-- 例: scoreDiff "Eve" "Frank"  => Nothing
--
-- ヒント: case で2つの lookup 結果をタプルにして同時にマッチ
--         または do 記法で Maybe をモナドとして使う
scoreDiff :: String -> String -> Maybe Int
scoreDiff a b = do
  aScore <- Map.lookup a scores
  bScore <- Map.lookup b scores
  return (aScore - bScore)

main :: IO ()
main = do
  -- (a)
  putStrLn $ getRank "Alice" -- "B"
  putStrLn $ getRank "Carol" -- "A"
  putStrLn $ getRank "Dave" -- "D"
  putStrLn $ getRank "Eve" -- "Unknown"
  -- (b)
  print $ scoreDiff "Alice" "Bob" -- Just 23
  print $ scoreDiff "Alice" "Eve" -- Nothing
  print $ scoreDiff "Eve" "Frank" -- Nothing
  print $ scoreDiff "Carol" "Dave" -- Just 46
