extension String: CollectionType {}
func readInts() -> [Int] {
    return readLine()!.split(" ").map({ Int($0)! })
}

let n: Int = Int(readLine()!)!
let s: [Int] = readInts()
let m: Int = Int(readLine()!)!
var p: [[Int]] = (0..<m).map({ _ in (0..<n).map({_ in 0 }) })

for i in 0..<m {
    p[i] = readInts()
}

func dfs(mp: [Int], ps: [Int]) -> [Int] {
    if mp.count == 0 {
        return ps
    }
    var res:[Int] = s
    for i in 0..<mp.count {
        var nextmp:[Int] = mp
        nextmp.removeAtIndex(i)
        var nextps: [Int] = (0..<n).map{_ in 0}
        for j in 0 ..< n {
            nextps[p[mp[i]][j] - 1] = ps[j]
        }
        let temp = min_array(res, b: dfs(nextmp, ps: nextps))
        res = temp
    }
    return res
}

func min_array(a: [Int], b: [Int]) -> [Int] {
    for i in 0 ..< a.count {
        if a[i] > b[i] {
            return b
        } else if a[i] < b[i] {
            return a
        }
    }
    return a
}

var max_p: Int = 1 << m
var t: [Int] = s
for i in 0 ..< max_p {
    let mp: [Int] = (0..<m).map({ $0 }).filter({(i >> $0) & 1 == 1})
    let temp: [Int] = min_array(t, b: dfs(mp, ps: s))
    t = temp
}

print(t.map({String($0)}).joinWithSeparator(" "))