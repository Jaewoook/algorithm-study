package main

import (
    "os"
    "bufio"
    "fmt"
)

func dfs(adjacency [][]int, v []bool, start, depth int) bool {
    if depth == 5 {
        return true
    }

    for _, next := range(adjacency[start]) {
        if v[next] {
            continue
        }
        v[next] = true
        if dfs(adjacency, v, next, depth + 1) {
            return true
        }
        v[next] = false
    }

    return false
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var N, M, a, b int
    fmt.Fscan(reader, &N, &M)
    adjacency := make([][]int, N)
    for ; M > 0; M-- {
        fmt.Fscan(reader, &a, &b)
        adjacency[a] = append(adjacency[a], b)
        adjacency[b] = append(adjacency[b], a)
    }

    exists := 0
    v := make([]bool, N)
    for i := 0; i < N; i++ {
        v[i] = true
        if dfs(adjacency, v, i, 1) {
            exists = 1
            break
        }
        v[i] = false
    }

    fmt.Fprintln(writer, exists)
}
