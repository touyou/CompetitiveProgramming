#if os(Linux)
    import Glibc
#else
    import Darwin
#endif

var s: String!
var i: Int!

s = readLine()!
i = Int(readLine()!)

print(s[s.startIndex.advancedBy(i-1)])
