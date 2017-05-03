#if os(Linux)
    import Glibc
#else
    import Darwin
#endif
extension String: CollectionType {}

var N: Int = Int(readLine()!)!
var a: [Int] = readLine()!.split(" ").map { Int($0)! }
var res = Dictionary<Int, Int>()

for i in 0 ..< N {
    res[a[i]] = i+1
}

a.sortInPlace(>)

for i in 0 ..< N {
    print(res[a[i]]!)
}
