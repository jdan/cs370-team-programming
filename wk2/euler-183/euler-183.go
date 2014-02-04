// Euler 183 Solution
// by Jordan Scales (for CS370)
// 1 Feb 2014

package main

import (
  "fmt"
  "strconv"
  "math"
  "os"
)

func main() {
  if len(os.Args) < 3 {
    usage()
    return
  }

  // d will hold our total. a and b is the range we will
  // iterate over
  var d int64
  a, _ := strconv.Atoi(os.Args[1])
  b, _ := strconv.Atoi(os.Args[2])

  for n := a; n <= b; n++ {
    k := maxPartition(n)

    // Compute (n/k)^k as a reduced fraction and set it to u/v
    // However, (n/k)^k is a terminating decimal iff (n/k) is
    // also terminating. Thus, we do not need to compute (n/k)
    _, v := reduce(n, k)

    // If v is terminating, add -N to the total
    // Otherwise, add N
    if isTerminating(v) {
      d -= int64(n)
    } else {
      d += int64(n)
    }
  }

  fmt.Println("Total:", d)
}


// Computes integer k such that (N/k)^k is maximized
// This is equal to N/e, rounded to the nearest integer
//
// We can compute this by taking the derivative of f(x) = (N/x)^x
// and finding its real intercept
func maxPartition(n int) int {
  // n/e will give the maximum partition
  // but first, we need to round n/e to the nearest integer
  //
  // Math.floor(x + 0.5) <=> round(x)
  return int(math.Floor(float64(n) / math.E + 0.5));
}


// Reduces two integers a and b as if they were the numerator
// and denominator of a fraction
func reduce(a int, b int) (int, int) {
  k := gcd(a, b)

  return a / k, b / k
}


// Computes the greatest common denominator between two integers
// This can probably be optimized
func gcd(a int, b int) int {
  if b == 0 {
    return a
  } else {
    return gcd(b, a % b)
  }
}


// Determines whether or not D is the denominator of a fraction whose
// decimal representation terminates
//
// This is equivalent to whether or not D is fully composed of multiples
// of 2 and 5
func isTerminating(d int) bool {
  for {
    if d % 5 != 0 {
      break
    }

    d /= 5
  }

  for {
    if d % 2 != 0 {
      break
    }

    d /= 2
  }

  return d == 1
}


func usage() {
  fmt.Println("Usage: euler-183 [a] [b]")
  fmt.Println("Where a and b are bounds")
  fmt.Println("Problem 183 specifies a=5 and b=10000")
}
