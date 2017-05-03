#! python

# s2 = raw_input().split('/')
def conv(c):
    if c == '0':
        return 0
    return 1

def solve(s1):
    s2 = s1.split('/')
    s3 = []
    for i in s2:
        s = bin(int(i,16))
        s3.append(s[2:])
    if len(s3[0]) > len(s3[1]):
        while len(s3[1]) < len(s3[0]):
            s3[1] = '0' + s3[1]
    else:
        while len(s3[0]) < len(s3[1]):
            s3[0] = '0' + s3[0]
    ans = ""
    y = 0
    while y < len(s3[0]):
        a = conv(s3[0][y])
        b = conv(s3[1][y])
        if a == 1 and b == 1:
            c = conv(s3[0][y+1])
            d = conv(s3[1][y+1])
            if c == 1 and d == 0:
                if y + 2 < len(s3[0]):
                    e = conv(s3[0][y+2])
                    f = conv(s3[1][y+2])
                    if e == 1 and f == 1:
                        ans += 'N'
                        y += 3
                    else:
                        ans += 'R'
                        y += 2
                else:
                    ans += 'R'
                    y += 2
            elif c == 0 and d == 1:
                if y + 2 < len(s3[0]):
                    e = conv(s3[0][y+2])
                    f = conv(s3[1][y+2])
                    if e == 1 and f == 1:
                        ans += 'U'
                        y += 3
                    else:
                        ans += 'L'
                        y += 2
                else:
                    ans += 'L'
                    y += 2
        elif a == 0 and b == 1:
            if y + 2 < len(s3[0]):
                e = conv(s3[0][y+2])
                f = conv(s3[1][y+2])
                if e == 1 and f == 0:
                    ans += 'S'
                    y += 3
                else:
                    ans += 'J'
                    y += 2
            else:
                ans += 'J'
                y += 2
        elif a == 1 and b == 0:
            e = conv(s3[0][y+2])
            f = conv(s3[1][y+2])
            if e == 1 and f == 0:
                ans += 'T'
                y += 3
            else:
                ans += 'Z'
                y += 3
        else:
            y += 1
    return ans

def test(s1,s2):
    if solve(s1) == s2:
        print "ok"
    else:
        print "bad..."

test( "2ed8aeed/34b0ea5b", "LTRSUNTSJ" )
test( "00000200/00000300", "L" )
test( "00018000/00010000", "R" )
test( "00002000/00006000", "J" )
test( "00000700/00000200", "T" )
test( "01400000/01c00000", "U" )
test( "00003800/00002800", "N" )
test( "000c0000/00180000", "S" )
test( "00003000/00001800", "Z" )
test( "132eae6c/1a64eac6", "LRJTUNSZ" )
test( "637572d0/36572698", "ZSNUTJRL" )
test( "baddb607/d66b6c05", "LTJZTSSSN" )
test( "db74cd75/6dac6b57", "ZZZTJZRJNU" )
test( "3606c2e8/1b0d8358", "ZZSSLTJ" )
test( "ad98c306/e6cc6183", "UZZZZZZ" )
test( "4a4aaee3/db6eeaa6", "JJLLUUNNS" )
test( "ecd9bbb6/598cd124", "TSSZZTTRR" )
test( "e0000002/40000003", "TL" )
test( "a0000007/e0000005", "UN" )
test( "c0000003/80000006", "RS" )
test( "40000006/c0000003", "JZ" )
test( "01da94db/00b3b6b2", "TSUJLRSR" )
test( "76eeaaea/24aaeeae", "TRNNUUNU" )
test( "1dacaeee/1566e444", "NRJZUTTT" )
test( "26c9ac60/6c6d66c0", "JSZLRJZS" )
test( "6c977620/36da5360", "ZZLLTNZJ" )
test( "069aeae6/0db34eac", "SJSLTUNS" )
test( "06d53724/049da56c", "RRULRNJJ" )
test( "069b58b0/04d66da0", "RLRSLZJR" )
test( "1b6eced4/11b46a9c", "RZZTZNRU" )
test( "522e8b80/db6ad900", "JLLJNLJT" )
test( "6546cdd0/376c6898", "ZULSZRTL" )
test( "4e6d5b70/6ad9d620", "LNSSURST" )
test( "37367772/65635256", "SNSZNTNJ" )
test( "25535d58/377669cc", "LUUSLTUZ" )
test( "0ae6a55d/0eacedcb", "UNSUJUTJ" )
test( "76762edc/23536a88", "TZNZJNRT" )
