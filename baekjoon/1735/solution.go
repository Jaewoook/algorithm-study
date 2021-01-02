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

    var x1, x2, y1, y2 int
    fmt.Fscan(reader, &x1, &y1, &x2, &y2)

    x1 = x1 * y2 + x2 * y1
    y1 *= y2
    r := computeGcd(y1, x1)

    fmt.Fprint(writer, x1 / r)
    fmt.Fprint(writer, " ")
    fmt.Fprintln(writer, y1 / r)
}

func computeGcd(x, y int) int {
    divisor := 0
    if x < y {
        x, y = y, x
    }

    for y != 0 {
        divisor = x % y
        x = y
        y = divisor
    }

    return x
}
