first_roman = input()
second_roman = input()

roman_to_num = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

place_value_to_roman = {
    1: ('I', 'V'),
    10: ('X', 'L'),
    100: ('C', 'D'),
    1000: ('M')
}

romans = tuple(roman_to_num.keys())

def convert_roman_to_decimal(roman: str):
    roman = reversed(roman)
    result = 0
    prev_n = None
    for n in roman:
        if prev_n is not None:
            prev_n_order = romans.index(prev_n)
            n_order = romans.index(n)
            if prev_n_order <= n_order:
                result += roman_to_num[n]
            else:
                result -= roman_to_num[prev_n]
                result += roman_to_num[prev_n] - roman_to_num[n]
        else:
            result += roman_to_num[n]
        prev_n = n

    return result

def decimal_to_roman(decimal: int):
    result = ''
    place_value = 1
    unit = 0
    while decimal > 0:
        unit = decimal % 10
        while unit > 0:
            if unit == 9:
                result = place_value_to_roman[place_value][0] + place_value_to_roman[place_value * 10][0] + result
                break
            elif unit == 5:
                result = place_value_to_roman[place_value][1] + result
                break
            elif unit == 4:
                result = place_value_to_roman[place_value][0] + place_value_to_roman[place_value][1] + result
                break
            else:
                result = place_value_to_roman[place_value][0] + result
                unit -= 1

        decimal //= 10
        place_value *= 10

    return result

first_value = convert_roman_to_decimal(first_roman)
second_value = convert_roman_to_decimal(second_roman)
print(first_value + second_value)
print(decimal_to_roman(first_value + second_value))
