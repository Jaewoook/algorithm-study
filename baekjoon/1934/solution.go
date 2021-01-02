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

    var T, a, b, x, y, r int
    fmt.Fscan(reader, &T)
    for ; T > 0; T-- {
        fmt.Fscan(reader, &a, &b)
        if a < b {
            a, b = b, a
        }
        x, y = a, b
        for y != 0 {
            r = y
            y = x % y
            x = r
        }
        fmt.Fprintln(writer, a / r * b)
    }
}
