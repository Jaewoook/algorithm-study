package main

import (
    "os"
    "bufio"
    "fmt"
    "strconv"
)

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var N int
    var M int64
    fmt.Fscan(reader, &N, &M)
    tree := make([]int, N)
    max_height := 0
    for i := 0; i < N; i++ {
        fmt.Fscan(reader, &tree[i])
        if max_height < tree[i] {
            max_height = tree[i]
        }
    }

    min_height, mid_height, ideal_height := 0, 0, 0
    prev_min, prev_max := 0, 0
    var ideal_length, result_length int64
    for {
        prev_min, prev_max = min_height, max_height
        mid_height = (min_height + max_height) / 2
        result_length = 0
        for i := 0; i < N; i++ {
            result_length += int64(max(tree[i] - mid_height, 0))
        }
        if result_length == M {
            ideal_height = mid_height
            break
        } else if result_length > M {
            if ideal_length < M || ideal_length > result_length {
                ideal_length = result_length
                ideal_height = mid_height
            }
            min_height = mid_height + 1
            if min_height > max_height {
                min_height = max_height
            }
        } else {
            max_height = mid_height - 1
            if min_height > max_height {
                max_height = min_height
            }
        }
        if min_height == prev_min && prev_max == max_height {
            break
        }
    }

    writer.WriteString(strconv.Itoa(ideal_height) + "\n")
}
