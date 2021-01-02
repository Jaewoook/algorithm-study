package main

import (
    "os"
    "bufio"
    "strings"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    b, _, _ := reader.ReadLine()
    line := string(b)
    T, _ := strconv.Atoi(line)
    var sum uint64

    for ; T > 0; T-- {
        b, _, _ = reader.ReadLine()
        line = string(b)
        nums := strings.Fields(line)
        N, _ := strconv.Atoi(nums[0])
        num := make([]int, N)
        for i := 1; i <= N; i++ {
            num[i - 1], _ = strconv.Atoi(nums[i])
        }
        sum = 0
        for i := 0; i < N - 1; i++ {
            for j := i + 1; j < N; j++ {
                sum += computeGcd(num[i], num[j])
            }
        }
        writer.WriteString(strconv.FormatUint(sum, 10) + "\n")
    }
}

func computeGcd(x, y int) uint64 {
    if x < y {
        x, y = y, x
    }
    var divisor = y
    for y > 0 {
        divisor = x % y
        x = y
        y = divisor
    }

    return uint64(x)
}
