# Tic-Tac-Toe Variants Game Collection

## Overview
This project is a collection of **8 different Tic-Tac-Toe variants**, allowing players to enjoy a variety of strategic board games. The game is implemented in **C++**, featuring a menu-based interface for easy selection and navigation.

## Games Included
1. **Pyramid Tic-Tac-Toe**
2. **Four-in-a-row**
3. **5x5 Tic-Tac-Toe**
4. **Word Tic-Tac-Toe**
5. **Numerical Tic-Tac-Toe**
6. **Misere Tic-Tac-Toe**
7. **4x4 Tic-Tac-Toe**
8. **Ultimate Tic-Tac-Toe**
9. **SUS (Special Unique Style) Tic-Tac-Toe**

## How to Run
### Prerequisites
- A **C++ compiler** (e.g., g++, Clang, or MSVC)
- A terminal or command prompt

### Compilation
```sh
 g++ -o tic_tac_toe main.cpp BoardGame_Classes.cpp main_Pyramid.cpp main_Four_In_A_Row.cpp main_5x5.cpp main_word.cpp main_Numerical.cpp main_misere.cpp main_4x4.cpp main_Ultimate.cpp main_sus.cpp
```

### Running the Game
```sh
./tic_tac_toe
```

## Features
- **User-friendly menu system** for easy game selection
- **Different gameplay styles** for each Tic-Tac-Toe variant
- **Error handling** for invalid inputs
- **Continuous play** until the user decides to exit

## File Structure
```
📂 Project Directory
├── 📜 main.cpp                 # Entry point of the game
├── 📜 BoardGame_Classes.h       # Header file for game logic
├── 📜 BoardGame_Classes.cpp     # Implementation of game classes
├── 📜 main_Pyramid.cpp          # Pyramid Tic-Tac-Toe logic
├── 📜 main_Four_In_A_Row.cpp    # Four-in-a-row logic
├── 📜 main_5x5.cpp              # 5x5 Tic-Tac-Toe logic
├── 📜 main_word.cpp             # Word Tic-Tac-Toe logic
├── 📜 main_Numerical.cpp        # Numerical Tic-Tac-Toe logic
├── 📜 main_misere.cpp           # Misere Tic-Tac-Toe logic
├── 📜 main_4x4.cpp              # 4x4 Tic-Tac-Toe logic
├── 📜 main_Ultimate.cpp         # Ultimate Tic-Tac-Toe logic
├── 📜 main_sus.cpp              # SUS Tic-Tac-Toe logic
└── 📜 README.md                 # Project documentation
```

## Contributing
Feel free to contribute by:
- Fixing bugs
- Adding new game variations
- Improving UI and error handling

## License
This project is open-source under the **MIT License**.

## Author
[Mariam Badr - Ola Ghoneim - Menna Mohamed] - Cairo University, Faculty of Computers and Artificial Intelligence
