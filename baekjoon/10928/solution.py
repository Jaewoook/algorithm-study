import hashlib

key = input().encode()
print(hashlib.sha1(key).hexdigest())
