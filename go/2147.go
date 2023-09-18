const (
    seat = "S"
    plant = "P"
    mod = 1e9 + 7
)

func numberOfWays(corridor string) int {
    var (
        seatsCount, plantsInBetweenCount int
        isEvenSeats, first bool
        plantsInBetween []int
    )

    seatsCount, isEvenSeats = countSeats(corridor)

    if !isEvenSeats || seatsCount == 0 {
        return 0
    }

    removeEdgePlants(&corridor)

    plantsInBetween = []int{}
    for _, v := range corridor {
        vStr := string(v)

        // Skip plants between a pair of seats
        if first && vStr == plant {
            continue;
        }

        // Second seat of div was found
        if first && vStr == seat {
            first = false
            continue
        }

        if vStr == seat {
            first = true
            plantsInBetween = append(plantsInBetween, plantsInBetweenCount)
            plantsInBetweenCount = 0
            continue
        }

        plantsInBetweenCount++;
    }

    return calculateNumOfWays(plantsInBetween)
}

func countSeats(corridor string) (int, bool) {
    seatsCount := 0;
    for _, obj := range corridor {
        if obj == 'S' {
            seatsCount++
        }
    }
    return seatsCount, isEven(seatsCount)
}

func isEven(num int) bool {
    return num % 2 == 0
}

func removeEdgePlants(corridor *string) {
	start := string((*corridor)[0])
	end := string((*corridor)[len((*corridor)) - 1])
	for start == plant || end == plant {
        if len(*corridor) == 0 { break }

		start = string((*corridor)[0])
		end = string((*corridor)[len((*corridor)) - 1])
		
        if start == plant {
            *corridor = (*corridor)[1:]
        }

        if end == plant {
            *corridor = (*corridor)[:len((*corridor)) - 1]
        }
    }
}

func calculateNumOfWays(arr []int) int {
    // (pib1 + 1) * (pib2 + 1) ... (pibn + 1) = numOfWays
    numOfWays := 1
    for _, v := range arr {
        numOfWays = (numOfWays * (v + 1)) % mod
    }

    // n mod (10e9 + 7)
    return numOfWays
}
