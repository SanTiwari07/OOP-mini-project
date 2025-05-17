# 🎮 Number-Based Mini Game Suite in C++

A C++ console-based mini game suite that features three exciting games based on numbers and logic. This project is ideal for beginners who are learning C++ fundamentals, especially in file handling, random number generation, and control structures.

# 🧠 About the Project

This mini-project contains a collection of three simple yet entertaining games:

Number Guesser  

The system generates a random number between 1 and 100. The player has 8 attempts to guess the number. After each guess, the program gives a hint whether the number is too high or too low.

Minesweeper 4x4A simplified version of the Minesweeper game on a 4x4 grid.  

Players choose coordinates to reveal. If they hit a mine, the game ends. The game uses arrays and randomness to place mines.

Play Point (Dice Game)  

Simulates rolling two dice. The player guesses the total sum before the roll. Correct guesses earn points, incorrect guesses lose points. A simple game of luck and probability!

coin_filp  

User guesses either heads or tails (1 or 2), a random result determines win/loss and Matching guess wins the bet amount; wrong guess loses it.



# 🛠️ Features

🎲 4 fun mini-games in one program

📂 Score saving using file handling (score.txt) and player's story (data_player.txt)

🫮 Random number generation using rand()

🛡️ Input validation and basic error handling

📋 Clean and readable menu system

🧰 Modular code structure with reusable functions


# 🚀 How to Run the Project

🔧 Prerequisites

A C++ compiler (like g++, clang, or any IDE like Code::Blocks / Visual Studio / Dev C++)

Basic understanding of how to compile and run C++ programs

# 🧾 Compile and Run (Using Command Line)

g++ main.cpp -o game
./game

💡 Or, if using an IDE:

Open the main.cpp file.

Build and run the project.

# 📸 Demo

========= Welcome to the Number Game Suite =========    
Choose a game:  
  
0. Exit  
1. Number Guesser  
2. Minesweeper 4x4  
3. Play Point (Dice Game)  
4. coin filp
     
Enter your choice: _

# 🧑‍💻 Concepts Used

This project demonstrates the following C++ concepts:

Input/output (cin, cout)

Conditional statements (if, else)

Loops (for, while)

Arrays

Functions

File handling (ofstream, ifstream)

Random number generation (rand(), srand())

Header inclusion and modular coding

# 📈 Score System

Your score is stored in a file (score.txt) and updates after each game session:

🎯 Number Guesser: +10 points for correct guess

💣 Minesweeper: +5 points for each safe coordinate

🎲 Play Point: +10 for correct dice sum, -5 for wrong guess

# 📌 Future Improvements

Add difficulty levels

Use classes and object-oriented programming

Implement colored UI using platform-specific libraries

Add leaderboard feature

Store date and time of each game session

# 🤝 Contributing

Pull requests are welcome! If you'd like to improve or add new features to the game suite, feel free to fork the repo and submit your suggestions.

 # ✍️ Author

Made with 💻 and ❤️ by -

Sanskar Tiwari

Saai Khamkar

Siddhant Patil
