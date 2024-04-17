# Lv. 2 - 전화번호 목록
# https://school.programmers.co.kr/learn/courses/30/lessons/42577

from typing import List

def solution(phone_book: List[str]):
    phone_book.sort()

    for index in range(len(phone_book) - 1):
        if phone_book[index] == phone_book[index + 1][:len(phone_book[index])]:
            return False

    return True
