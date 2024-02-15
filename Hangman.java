import java.util.*;

public class Hangman {
    public static void main(String[] args) {
        System.out.println("H A N G M A N");
        System.out.println();
        String[] words = {"python", "java", "kotlin", "javascript", "html", "css", "ruby",
                "sql", "coffeescript", "crystal", "elixir", "go", "groovy", "php",
                "racket", "rust", "shell", "swift", "typescript", "pascal"};
        int wins = 0;
        int loses = 0;
        Scanner scanner = new Scanner(System.in);

        label:
        while (true) {
            System.out.print("Type \"play\", \"score\", or \"exit\": ");
            String menu = scanner.nextLine();
            switch (menu) {
                case "play":
                    String currentAction = words[new Random().nextInt(words.length)];
                    char[] tip = new char[currentAction.length()];
                    Arrays.fill(tip, '-');
                    int lives = 8;
                    List<Character> usedLetters = new ArrayList<>();

                    while (true) {
                        System.out.println(String.valueOf(tip));
                        System.out.print("Input a letter: ");
                        String action = scanner.nextLine();

                        if (action.length() != 1) {
                            System.out.println("You should input a single letter");
                            System.out.println();
                            continue;
                        }
                        char letter = action.charAt(0);
                        if (!Character.isLowerCase(letter)) {
                            System.out.println("It is not an ASCII lowercase letter");
                            System.out.println();
                            continue;
                        }
                        if (usedLetters.contains(letter)) {
                            System.out.println("You already typed this letter");
                            System.out.println();
                            continue;
                        }
                        boolean letterFound = false;
                        for (int i = 0; i < currentAction.length(); i++) {
                            if (currentAction.charAt(i) == letter) {
                                tip[i] = letter;
                                letterFound = true;
                            }
                        }
                        if (!letterFound) {
                            System.out.println("No such letter in the word");
                            lives--;
                            if (lives == 0) {
                                break;
                            }
                            System.out.println("Lives left: " + lives);
                        }
                        usedLetters.add(letter);
                        if (String.valueOf(tip).equals(currentAction)) {
                            break;
                        }
                        System.out.println();
                    }
                    if (lives == 0) {
                        System.out.println("You are hanged!");
                        loses++;
                    } else {
                        System.out.println("You guessed the word " + currentAction + "!");
                        System.out.println("You survived!");
                        wins++;
                    }
                    break;
                case "exit":
                    break label;
                case "score":
                    if (wins == 1 && loses == 1) {
                        System.out.println("You won 1 time. You lost 1 time.");
                    } else if (wins == 1) {
                        System.out.println("You won 1 time. You lost " + loses + " times.");
                    } else if (loses == 1) {
                        System.out.println("You won " + wins + " times. You lost 1 time.");
                    } else {
                        System.out.println("You won " + wins + " times. You lost " + loses + " times.");
                    }
                    break;
                default:
                    System.out.println("Wrong input. Please, try again");
                    break;
            }
        }
    }
}
