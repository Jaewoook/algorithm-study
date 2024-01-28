import sys

expr = sys.stdin.readline().strip()
expr_arr = []
term = ""
for c in expr:
    if c == "+" or c == "-":
        expr_arr.append(int(term))
        expr_arr.append(c)
        term = ""
        continue
    term += c
if term != "":
    expr_arr.append(int(term))

result = 0
mode = "plus"
for term in expr_arr:
    if term == "-":
        mode = "minus"
    elif term == "+":
        pass
    else:
        if mode == "plus":
            result += term
        else:
            result -= term

print(result)
