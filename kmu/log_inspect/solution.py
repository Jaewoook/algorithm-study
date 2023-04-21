import sys
import re
REGEX = re.compile(r"^line_name : [a-zA-Z]+ product_name : [a-zA-Z]+ error_level : [a-zA-Z]+ message : [a-zA-Z]+$")
T = int(input())

for _ in range(T):
    count = 0
    n = int(input())
    for i in range(n):
        message = sys.stdin.readline()
        if len(message) >= 100:
            count += 1
            continue
        match_result_2 = REGEX.match(message)
        if match_result_2 == None:
            count += 1

    print(count)

# sample input
#
# 1
# 4
# line_name : db product_name : dbtest error_level : info message : test
# line_name : test product_name : I DONT CARE error_level : error message : x
# line_name : ThisIsJustForTest product_name : TestAndTestAndTestAndTest error_level : test message : IAlwaysTestingAndIWillTestForever
# line_name : oberervability product_name : LogViewer error_level : error

# sample output
#
# 3
