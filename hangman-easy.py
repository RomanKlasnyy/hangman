import random
from string import ascii_lowercase

print('H A N G M A N')
print()
words = ['python', 'java', 'kotlin', 'javascript', 'html', 'css', 'ruby',
         'sql', 'coffeescript', 'crystal', 'elixir', 'go', 'groovy', 'php',
         'racket', 'rust', 'shell', 'swift', 'typescript', 'pascal']
wins = 0
loses = 0

while True:
    menu = input('Type "play", "score", or "exit": ')
    if menu == 'play':
        c_action = random.choice(words)
        tip = list((len(c_action)) * '-')
        lives = 8
        used_letters = []
        while True:
            print(''.join(tip))
            action = input('Input a letter: ')
            if len(action) != 1:
                print('You should input a single letter')
                print()
                continue
            if action not in ascii_lowercase:
                print('It is not an ASCII lowercase letter')
                print()
                continue
            if action in used_letters:
                print('You already typed this letter')
                print()
                continue
            if action not in tip and action in c_action:
                for i, letter in enumerate(c_action):
                    if letter == action:
                        tip[i] = action
            else:
                print('No such letter in the word')
                lives -= 1
                if lives == 0:
                    break
                print(f'Lives left: {lives}')
            used_letters.append(action)
            if '-' not in tip:
                break
            print()
        if lives == 0:
            print('You are hanged!')
            loses += 1
        else:
            print(f'You guessed the word {c_action}!')
            print('You survived!')
            wins += 1
    elif menu == 'exit':
        break
    elif menu == 'score':
        if wins == 1 and loses == 1:
            print(f'You won 1 time. You lost 1 time.')
        elif wins == 1:
            print(f'You won 1 time. You lost {loses} times.')
        elif loses == 1:
            print(f'You won {wins} times. You lost 1 time.')
        else:
            print(f'You won {wins} times. You lost {loses} times.')
    else:
        print('Wrong input. Please, try again')
