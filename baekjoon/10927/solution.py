import hashlib

key = input().encode()
print(hashlib.md5(key).hexdigest())
