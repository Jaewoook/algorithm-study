# Lv. 2 - 전화번호 목록
# https://school.programmers.co.kr/learn/courses/30/lessons/42577

def solution(phone_book: list[str]):
    numInfo = {}
    for num in phone_book:
        numInfo[num] = 1

    for num in phone_book:
        phone = ""
        for digit in num:
            phone += digit

            if phone in numInfo and phone != num:
                return False

    return True
