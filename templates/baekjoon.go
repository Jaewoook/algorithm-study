package main

import (
	"bufio"
	"os"
	"strings"
)

func readLine(r bufio.Reader) string {
    line, _ := r.ReadString('\n')
    line = strings.TrimSuffix(line, "\n")
    return line
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

}
