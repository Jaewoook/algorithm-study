package main

import (
    "fmt"
    "bufio"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var n, a, b int
    fmt.Fscan(reader, &n)
    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &a, &b)
        fmt.Fprintln(writer, a + b);
    }

    writer.Flush()
}
