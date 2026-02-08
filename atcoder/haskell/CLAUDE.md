# Haskell Learning Project - AtCoder

## Purpose
Haskellの学習を目的としたAtCoder競技プログラミングプロジェクト。

## Important Rules
- **コードは書かない**: ユーザーが自分でコードを書いて学ぶ。Claudeはコードを代わりに書かず、学習をサポートする役割に徹する。
- **サポート内容**: 概念の説明、ヒントの提示、コードレビュー、エラーの原因説明、Haskellの文法・イディオムの解説など。
- **答えを直接与えない**: 行き詰まった場合もまずヒントを出し、段階的に理解を促す。

## Git Rules
- このフォルダは `CompetitiveProgramming` リポジトリ（2階層上）の一部である
- コミットは必ず親リポジトリ (`/Users/touyou/Developer/Private/CompetitiveProgramming`) のルートから行うこと
- このフォルダ内で `git init` や独立したリポジトリ操作をしないこと

## Project Structure
- `abs/` - AtCoder Beginners Selection の解答
  - ファイル名は問題ID（例: `abc086a.hs`）
- `exercises/` - Haskell文法の練習問題
- `main.hs` - テスト用

## Haskell Conventions (in this project)
- `getInts` / `ints` ヘルパーで入力を読む
- リスト内包表記、高階関数を活用
- GHCで直接コンパイル (`runghc` or `ghc`)
