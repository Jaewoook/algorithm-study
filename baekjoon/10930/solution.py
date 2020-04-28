import hashlib

key = input().encode()
print(hashlib.sha256(key).hexdigest())
