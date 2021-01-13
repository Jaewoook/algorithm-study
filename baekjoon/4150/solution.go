package main

import (
    "os"
    "bufio"
    "math/big"
    "fmt"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    n := big.NewInt(0)
    fmt.Fscan(reader, n)
    if n.Cmp(big.NewInt(2)) <= 0 {
        fmt.Fprintln(writer, 1)
        return
    }

    counter := big.NewInt(2)
    prev_1 := big.NewInt(1)
    prev_2 := big.NewInt(1)
    for counter.Cmp(n) <= 0 {
        counter.Add(counter, big.NewInt(1))
        prev_1.Add(prev_1, prev_2)
        prev_1, prev_2 = prev_2, prev_1
    }
    fmt.Fprintln(writer, prev_1)
}
