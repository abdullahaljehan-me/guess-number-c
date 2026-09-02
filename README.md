# 🎲 Guess The Number - C

Welcome to **Guess The Number**, a clean, interactive, and robust command-line game written in pure C. 

Instead of a rigid, robotic experience, this game features intuitive mechanics, helpful feedback, and dynamic reactions based on your performance. Can you read the computer's mind?

## Features

- **Three Difficulty Levels**: Choose between Easy (1-50, 7 chances), Medium (1-100, 6 chances), and Hard (1-200, 5 chances).
- **Scoring System**: Earn points based on the difficulty level and how many chances you have left. Higher risk equals higher reward.
- **Session High Scores**: The game tracks your fewest attempts to win for each difficulty level during your current play session.
- **Hint System**: Stuck? Type `0` to get a **one-time free hint** per round, revealing if the number is Even/Odd and whether it is in the upper or lower half of the range.
- **Forgiving Mechanics**: Accidentally typed a letter? Guessed a number out of bounds? The game safely handles invalid input and does not waste your precious chances.
- **Dynamic Feedback**: The game reacts to your performance. Guess it on the first try? It will acknowledge the incredible feat. Take a few tries? It will still cheer you on.
- **Seamless Replayability**: Easy menu looping allows you to play again, change difficulty, or exit without restarting the program.

## How to Play

1. Run the game and select your difficulty level (1, 2, or 3) or choose to Exit (4).
2. The computer generates a secret number within the chosen range.
3. Type your guess and press Enter. The game will tell you if you are **Too High** or **Too Low**.
4. Find the number before you run out of chances!
5. **Pro Tips**: 
   - Type `0` at any time to use your **one-time hint**.
   - Type `-1` at any time to **quit** the current round and return to the menu.

## Prerequisites

To compile and run this game, you need:
- A C compiler (like `gcc`, `clang`, or `MinGW`).
- A terminal or command prompt.

## Installation & Running

### 1. Clone the repository
```bash
git clone https://github.com/your-username/guess-number-c.git
cd guess-number-c
