# algorithm study solution archive

This is an archive repository contains PS solutions.

## Languages I used

- C / C++
- Java
- Python
- JavaScript (TypeScript)
- Go

## Online Judge Profile

- [Baekjoon Online Judge](https://acmicpc.net/user/ajw4586)
- [Codeforces](https://codeforces.com/profile/ahnjaewook)

## algorithm CLI

The algorithm CLI automates routine tasks to save time.

### Usage

```sh
./algorithm [command] [platform] [options]

# This command generates solution file at ./leetcode/1. Two Sum/solution.cpp
./algorithm create leetcode -l cpp \
-no 1 -n "Two Sum" \
-l https://leetcode.com/problems/two-sum/
```

### Commands

- **create** command creates solution file for specific platform using passed problem number, name, link.

- **commit** command perform git commit on your behalf using template-based commit message.

### Options

- `-l`, `--lang`: Specify langauge
- `-h`, `--help`: Print help message
- Options for **create**:
  - `-no`, `--number`: Specify problem number
  - `-n`, `--name`: Specify problem name
  - `-l`, `--link`: Specify problem link
  - `-d`, `--date`: Specify file creation date (default: today's date)
