package main

import "fmt"

func main() {

	// 람다 기본 사용법
	sum := func(n ...int) int { // 익명 함수 -> 람다
		s := 0
		for _, i := range n {
			s += i
		}
		return s
	}

	result := sum(1, 2, 3, 4, 5)
	fmt.Println(result)
}
