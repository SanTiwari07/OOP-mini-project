# OOP-mini-project

# 🎮 C++ Mini Casino Game (Console-Based)
This code implements a console-based mini-casino game in C++ that includes four games:

  1.Number Guesser  
  2.Minesweeper-inspired Game   
  3.Play Point (Dice Sum Prediction)  
  4.Coin Flip  

All games are derived from a common base class user which handles user name input and point entry. The global points variable starts with 1000 points and is modified based on game performance.

# Structure & Flow

# 1. Base Class - user
-Handles user's name and betting points.  
-Validates whether the entered bet is within available points.  

# 2. Game 1: number_guesser
-Inherits from user.
-User has 8 attempts to guess a random number between 0 and 100.  
The fewer the attempts, the higher the multiplier:  

1st try = 10x   
2nd try = 8x  
...  
8th try = 1x  
Fail = 0x  

# 3. Game 2: minesweeper_4x4
-Simulates a 4x4 grid with 5 random mine positions.  
-User must avoid the mines by selecting safe grid cells.  
-Each safe selection increases earnings by 1.75x per step.  
-Entering 0 0 exits the game with an additional 10 points.  

# 4. Game 3: play_point
-A dice game with 3 rolls.  
-User predicts the total sum (range 3 to 18).  
Rewards:

Exact match = 5x  
±1 = 2x  
±2 = no gain/loss  
Others = -2x loss  

# 5. Game 4: coin_filp
-User guesses either heads or tails (1 or 2).  
-A random result determines win/loss.  
-Matching guess wins the bet amount; wrong guess loses it.  
-Random Number Generation  
-Uses random_device and mt19937 seeded with current time for randomness.  
-Dice and mine placements are generated with uniform_int_distribution.  

# Highlights
-Demonstrates use of OOP in C++ (Inheritance, Encapsulation).  
-Implements input validation and basic game logic.  
-Great project for beginners to practice control flow, loops, and randomness in C++.  
