# 🎲 Guess The Number - C

Welcome to **Guess The Number**, a fun and interactive command-line game written in pure C! 

Instead of a rigid, robotic experience, this game features a friendly tone, forgiving mechanics, and dynamic reactions based on how well you play. Can you read the computer's mind?

## Features

- **Three Difficulty Levels:** Choose between Easy (1-50), Medium (1-100), and Hard (1-200).
- **Humanized Feedback:** No more aggressive ALL-CAPS yelling. The game talks to you like a friend, using emojis and conversational text.
- **Forgiving Mechanics:** Accidentally typed a letter? Guessed a number out of bounds? The game forgives you and doesn't waste your precious chances!
- **Dynamic Reactions:** The game reacts to your performance. Guess it on the first try? It will call you a mind reader! Take a few tries? It'll cheer you on.
- **Replayability:** Seamless menu looping so you can jump right back in without restarting the program.

## How to Play

1. Select your difficulty level.
2. The computer generates a secret number within the chosen range.
3. Type your guess. The game will tell you if you are **Too High** or **Too Low**.
4. Find the number before you run out of chances!
5. Type `-1` at any time to quit the current round.

## Prerequisites

To compile and run this game, you need:
* A C compiler (like `gcc`).
* A terminal or command prompt.

## Installation & Running

### 1. Clone the repository
```bash
git clone https://github.com/your-username/guess-number-c.git
cd guess-number-c
