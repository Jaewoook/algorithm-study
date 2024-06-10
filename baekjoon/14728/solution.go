package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    rawLine, _, _ := reader.ReadLine()
    line := strings.Fields(string(rawLine))
    N, _ := strconv.Atoi(line[0])
    T, _ := strconv.Atoi(line[1])

    time_portion := [][]int{}
    for i := 0; i < N; i++ {
        rawLine, _, _ = reader.ReadLine()
        line = strings.Fields(string(rawLine))
        time, _ := strconv.Atoi(line[0])
        portion, _ := strconv.Atoi(line[1])

        time_portion = append(time_portion, []int{time, portion})
    }

    dp := make([][]int, N + 1)
    for i := range dp {
        dp[i] = make([]int, T + 1)
    }

    for i := 1; i <= N; i++ {
        time := time_portion[i - 1][0]
        portion := time_portion[i - 1][1]
        for max_time := range dp[i] {
            dp[i][max_time] = dp[i - 1][max_time]

            if max_time - time < 0 {
                continue
            }

            dp[i][max_time] = max(dp[i][max_time], dp[i - 1][max_time - time] + portion)
        }
    }

    writer.WriteString(strconv.Itoa(dp[N][T]) + "\n")

}
