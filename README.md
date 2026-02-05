# Casino-Number-Guessing-Game-using-C
This program is a menu-driven casino game written in C, where the player bets money and guesses a random number. The game tracks balance, wins, losses, and total games played.

🔹 Key Features
------------------------
Initial balance of 1000

Three difficulty levels:
Easy (1–5)
Medium (1–10)
Hard (1–20)

Random number generation using rand()

Betting system with win bonus & loss penalty

Lucky bonus if the number is 7

Game statistics tracking

🔹 Program Flow
---------------------------------
Displays a welcome message

Takes player name

Shows a menu:
Play Game
View Rules
View Statistics
Exit

User selects options until exit

🔹 Important Functions
--------------------------------
Function	Purpose
welcome()	Displays welcome banner
showMenu()	Shows main menu
playGame()	Handles betting, guessing & results
showRules()	Displays game rules
showStats()	Shows wins, losses & balance
getRandom()	Generates random number based on level

🔹 Winning & Losing Logic
---------------------------------------
Win → balance increases by bet × level
Lose → bet amount deducted
Lucky Bonus → +200 if number is 7

🔚 Conclusion
----------------------------------------------
This project demonstrates random number generation, conditional logic, functions, and menu-driven programming in C. It simulates a basic casino betting game and helps understand game logic, loops, and user interaction.
