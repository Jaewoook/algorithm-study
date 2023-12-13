import sys

OPERATORS = {
    "": 0,
    "+": 1,
    "-": 1,
    "*": 2,
    "/": 2,
    "(": 3,
    ")": 3,
};

def pop_stack(operator: str, stack: list[str], exp: list[str]):
    if len(stack) == 0:
        return

    top = stack[-1]

    while len(stack) > 0 and OPERATORS[top] >= OPERATORS[operator]:
        if top == "(" and operator != ")":
            break

        top = stack.pop()
        if top != "(":
            exp.append(top)

        if len(stack) > 0:
            top = stack[-1]

def pop_stack_paren(stack: list[str], exp: list[str]):
    top = stack[-1]

    while top != "(":
        exp.append(stack.pop())
        top = stack[-1]

    stack.pop()

for _ in range(int(sys.stdin.readline())):
    N = int(sys.stdin.readline())

    exp = sys.stdin.readline().split()

    operator_stack = []
    postfix_exp = []
    for item in exp:
        if OPERATORS.get(item) == None:
            postfix_exp.append(int(item))
            continue

        if len(operator_stack) == 0 or operator_stack[-1] == "(":
            operator_stack.append(item)
            continue

        top = operator_stack[-1]
        if item == ")":
            pop_stack_paren(operator_stack, postfix_exp)
            continue

        if OPERATORS[top] < OPERATORS[item]:
            operator_stack.append(item)
            continue

        if OPERATORS[top] >= OPERATORS[item]:
            pop_stack(item, operator_stack, postfix_exp)
            operator_stack.append(item)
            continue

    pop_stack("", operator_stack, postfix_exp)

    operands = []
    for item in postfix_exp:
        if OPERATORS.get(item) == None:
            operands.append(item)
            continue

        rop = operands.pop()
        lop = operands.pop()
        if item == "+":
            operands.append(lop + rop)
        elif item == "-":
            operands.append(lop - rop)
        elif item == "*":
            operands.append(lop * rop)
        elif item == "/":
            operands.append(lop / rop)

    print(operands.pop())

# sample input

# 4
# 5
# 2 + 2 * 2
# 7
# ( 2 + 2 ) * 2
# 3
# 2 - 3
# 9
# 2 + 3 * 5 / 2 - 1
