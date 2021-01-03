package main

import (
    "os"
    "bufio"
    "fmt"
    "strconv"
    "math"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var N, M, a, b int
    var c int64
    fmt.Fscan(reader, &N, &M)

    num := make([]int64, N + 1)
    height := int(math.Ceil(math.Log2(float64(N)))) + 1
    tree := make([]int64, 1 << height)

    for ; M > 0; M-- {
        fmt.Fscan(reader, &a, &b, &c)

        if (a == 0) {
            _c := int(c)
            if b > _c {
                b, _c = _c, b
            }
            writer.WriteString(strconv.FormatInt(query(tree, 1, N, 1, b, _c), 10) + "\n")
        } else {
            modifier := c - num[b]
            num[b] = c
            update(tree, 1, N, 1, b, modifier)
        }
    }
}

func query(tree []int64, l_range, r_range, node, start, end int) int64 {
    if end < l_range || r_range < start {
        return 0
    }
    if start <= l_range && r_range <= end {
        return tree[node]
    }
    mid := (l_range + r_range) / 2
    left := query(tree, l_range, mid, node << 1, start, end)
    right := query(tree, mid + 1, r_range, node << 1 | 1, start, end)
    return left + right
}

func update(tree []int64, l_range, r_range, node, target int, modifier int64) {
    if target < l_range || r_range < target {
        return
    }

    tree[node] += modifier
    if (l_range == r_range) {
        return
    }

    mid := (l_range + r_range) / 2
    update(tree, l_range, mid, node << 1, target, modifier)
    update(tree, mid + 1, r_range, node << 1 | 1, target, modifier)
}
