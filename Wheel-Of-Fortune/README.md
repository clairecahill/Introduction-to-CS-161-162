# Wheel-of-Fortune
# Description
This is a modified version of the popular game Wheel of Fortune. It takes 1-3 players and begins with a non-player entering a secret message to be guessed. This user also enters the amount of rounds to be played. Players will compete by guessing letters in the message, which earns them money. The player who guesses the secret phrase correctly gets to keep their bank at the end of the round. After all the rounds have been played, the player with the most money in their bank is the winner. 

# Specifics
With each turn, a player will choose to 1) spin the wheel 2) buy a vowel for $10 or 3) solve the puzzle. The player's turn is over when they make an incorrect guess for either a letter or the phrase. Spinning a 0 results in losing that turn and losing your bank for the round. Spinning a number between 1-20 allows the user to guess a consonant, and if that letter is in the secret message, they will earn the number spun times the amount of times the letter appears in the message. Spinning a 21 results in the player losing their turn, but they get to keep their bank. 

# Requirements
- The program must print out 1) the number spun on the wheel 2) the number of letters found in a guess 3) the total round earnings 4) the message with the correctly guessed slots and blank slots 5) (once the message is guessed) a winning message and the game totals for all players and 6) (after all rounds) a message with the winning player.
- You must not use arrays, only C++ strings.
- The program must ignore cases. 
- The program must handle user input errors

