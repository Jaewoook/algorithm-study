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

    bytes, _, _ := reader.ReadLine()
    line := string(bytes)
    N, _ := strconv.Atoi(string(line))
    for i := 0; i < N; i++ {
        bytes, _, _ = reader.ReadLine()
        line = string(bytes)
        nums := strings.Fields(line)
        a, _ := strconv.Atoi(nums[0])
        b, _ := strconv.Atoi(nums[1])
        writer.WriteString(strconv.Itoa(a + b) + "\n")
    }
}
