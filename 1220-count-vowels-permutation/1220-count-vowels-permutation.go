import (
	"math"
)

func countVowelPermutation(n int) int {
    val := 0
	v := int(math.Pow(10, 9)) + 7

	if n == 1 {
		return 5
	}

	dpa := make([]int, n+1)
	dpe := make([]int, n+1)
	dpi := make([]int, n+1)
	dpo := make([]int, n+1)
	dpu := make([]int, n+1)

	dpa[2] = 1
	dpe[2] = 2
	dpi[2] = 4
	dpo[2] = 2
	dpu[2] = 1

	for i := 3; i <= n; i++ {
		dpa[i] = dpe[i-1] % v
		dpe[i] = (dpa[i-1] + dpi[i-1]) % v
		dpi[i] = (dpa[i-1] + dpe[i-1] + dpo[i-1] + dpu[i-1]) % v
		dpo[i] = (dpi[i-1] + dpu[i-1]) % v
		dpu[i] = dpa[i-1] % v
	}

	val = (dpa[n] + dpe[n] + dpi[n] + dpo[n] + dpu[n]) % v

	return val
}