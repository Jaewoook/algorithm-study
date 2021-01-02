package main

import (
    "os"
    "bufio"
    "fmt"
)

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
    loop:
    for a := 0; a < N; a++ {
        for _, b := range adjacency[a] {
            for _, c := range adjacency[b] {
                if a == c {
                    continue
                }
                for _, d := range adjacency[c] {
                    if a == d || b == d {
                        continue
                    }
                    for _, e := range adjacency[d] {
                        if a == e || b == e || c == e {
                            continue
                        }
                        exists = 1
                        break loop
                    }
                }
            }
        }
    }

    fmt.Fprintln(writer, exists)
}
