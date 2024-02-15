package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func main() {
	fmt.Println("H A N G M A N")
	fmt.Println()
	words := []string{"python", "java", "kotlin", "javascript", "html", "css", "ruby",
		"sql", "coffeescript", "crystal", "elixir", "go", "groovy", "php",
		"racket", "rust", "shell", "swift", "typescript", "pascal"}
	wins := 0
	loses := 0
	rand.Seed(time.Now().UnixNano())

	for {
		fmt.Print("Type \"play\", \"score\", or \"exit\": ")
		var menu string
		fmt.Scanln(&menu)

		if menu == "play" {
			currentAction := words[rand.Intn(len(words))]
			tip := strings.Repeat("-", len(currentAction))
			lives := 8
			usedLetters := make(map[rune]bool)

			for lives > 0 && strings.Contains(tip, "-") {
				fmt.Println(tip)
				fmt.Print("Input a letter: ")
				var action string
				fmt.Scanln(&action)
				if len(action) != 1 || action[0] < 'a' || action[0] > 'z' {
					fmt.Println("You should input a single lowercase letter")
					continue
				}
				letter := rune(action[0])
				if usedLetters[letter] {
					fmt.Println("You already typed this letter")
					continue
				}
				usedLetters[letter] = true
				if strings.Contains(currentAction, action) {
					var builder strings.Builder
					for i, char := range currentAction {
						if char == letter {
							builder.WriteRune(letter)
						} else {
							builder.WriteByte(tip[i])
						}
					}
					tip = builder.String()
				} else {
					fmt.Println("No such letter in the word")
					lives--
					fmt.Printf("Lives left: %d\n", lives)
				}
			}
			if lives == 0 {
				fmt.Println("You are hanged!")
				loses++
			} else {
				fmt.Printf("You guessed the word %s!\n", currentAction)
				fmt.Println("You survived!")
				wins++
			}
		} else if menu == "exit" {
			break
		} else if menu == "score" {
			fmt.Printf("You won %d times. You lost %d times.\n", wins, loses)
		} else {
			fmt.Println("Wrong input. Please, try again")
		}
	}
}
