#if os(Linux)
    import Glibc
#else
    import Darwin
#endif
extension String: CollectionType {}

var a: [UInt64] = readLine()!.split(" ").map { UInt64($0)! }
let mod: UInt64 = 1000000007

let res = (a[0] * a[1] % mod) * a[2] % mod

print(res)
