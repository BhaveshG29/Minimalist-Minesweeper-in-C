# Mine Sweeper Game

A terminal-based Minesweeper game implemented in C with a modular architecture, persistent scoring system, and interactive game-play with Unicode emoji support.

## 📋 Features

- **10×10 Game Board**: Navigate a grid-based minefield with strategic game-play
- **Dynamic Bomb Placement**: Randomly generated bomb locations for each game
- **Scoring System**:
  - 10 points for revealing empty cells
  - 100 bonus points for finding the hidden cherry 🍒
  - Instant loss upon revealing a bomb 💣
- **Persistent High Score Tracking**: Scores saved to scores.dat for leaderboard functionality
- **Hint System**: Reveal adjacent mine counts to help with strategic decision-making
- **Replay Option**: Play multiple games without restarting the application
- **UTF-8 Emoji Interface**: Visual game board with emoji symbols (💣🍒🍀●)
- **Modular C Architecture**: Clean separation of concerns across multiple compilation units
- **Build Automation**: Makefile for easy compilation and execution

## 🎮 How to Play

### Compilation

```bash
# Navigate to the codes folder
cd minesweeper/codes

# Compile the project
make

# Or rebuild from scratch
make rebuild
```

### Running the Game

```bash
# Run the compiled executable (from codes folder)
make run

# Or directly execute
./main
```

### Gameplay

1. **View the Board**: The initial screen displays:
   - Current highest score ever achieved
   - Game symbols and their meanings
   - The 10×10 minefield (all cells hidden initially)

2. **Make Your Move**: Enter row and column numbers (1-10 for each)
   - Example: `5 7`

3. **Understanding Symbols**:
   - **Leaf** (🍀): Covered/unrevealed cell (default appearance)
   - **Dot** (●): Revealed empty cell (+10 points)
   - **Cherry** (🍒): Hidden cherry bonus cell (+100 points)
   - **Bomb** (💣): Mine cell - reveals on your move → Game Over

4. **Using the Hint System**:
   - Press Red Dots reveal there are adjacent mines around a specific cell
   - Each hint provides strategic information about nearby bombs
   - Hints help you make safer decisions in the game


5. **Replay Option**:
   - After game ends (win or loss), choose to play again without exiting
   - Your high score persists across games
   - Reset the board and start a new game instantly

6. **Winning Conditions**:
   - Reveal all non-bomb, non-cherry cells to maximize your score
   - Find the cherry for bonus points
   - Avoid all bombs

7. **Losing Condition**: Reveal any bomb cell

## 📁 Project Structure

```
minesweeper/
├── codes/
│   ├── main.c              # Entry point and main game loop
│   ├── game.c              # Core game logic and bomb placement
│   ├── display.c           # UI rendering and visual output
│   ├── board.c             # Board state management
│   ├── scores.c            # Scoring and persistence logic
│   └── Makefile            # Build configuration
├── libs/
│   ├── game.h              # Game function declarations
│   ├── display.h           # Display function declarations
│   ├── board.h             # Board structure definitions
│   └── scores.h            # Score management declarations
├── README.md               # This file
└── scores.dat              # Persistent high score storage
```

## 🔧 Technical Stack

- **Language**: C (C11 standard)
- **Build System**: Make
- **Compiler**: GCC with flags `-Wall -Wextra -std=c11`
- **Character Encoding**: UTF-8 for emoji support
- **File I/O**: Binary file operations for score persistence

## 📊 Game Mechanics

### Scoring Algorithm

- **Base Score**: Maximum possible = 1090 points
  - 100 empty cells × 10 points = 1000 points
  - 1 cherry × 100 points = 100 points
- **Bomb Count**: Configurable (10-50 bombs randomly placed)
- **Score Calculation**: `max_possible = 1090 - (10 × number_of_bombs)`

### Board State Values

- **0**: Leaf (unrevealed, default)
- **1**: Dot (revealed empty cell)
- **2**: Bomb (mine - game over on reveal)
- **3**: Cherry (bonus cell)

### Hint System Mechanics

- **Hint Activation**: Players can request hints during gameplay
- **Information Provided**: Adjacent mine count around specified cell
- **Strategic Value**: Helps players identify safe and risky zones
- **Usage**: Useful for difficult decision points in the game

### Replay System Mechanics

- **Game State Reset**: Board and cells reset for new game
- **Score Persistence**: High score retained across games
- **Continuous Play**: No need to restart the application
- **Session Management**: Player can quit or play again after each game

## 🎯 Core Functions

| Module | Key Functions | Purpose |
|--------|--------------|---------|
| game.c | `equalizing_arr()` | Initialize board with empty cells |
| | `placing_bombs()` | Random bomb and cherry placement |
| | `player_input()` | Capture and validate user input |
| | `get_hint()` | Calculate and display adjacent mine count |
| board.c | `initial_Board()` | Set up display board |
| | `update_Board()` | Update cell state after reveal |
| scores.c | `update_score()` | Increment score based on cell type |
| | `max()` | Retrieve highest score from file |
| | `save_score()` | Persist game score to disk |
| display.c | `initial_display()` | Show intro and legend |
| | `display()` | Render current game state |
| | `display_hint()` | Show hint information |

## 📝 Compilation Options

From the `codes/` directory:

```bash
make all       # Compile project (default)
make run       # Compile and run
make clean     # Remove compiled files
make rebuild   # Clean and recompile
```

## 💾 Data Persistence

- **Score File**: `../scores.dat` (located in root minesweeper directory)
- **Format**: Text-based integer storage
- **Feature**: Automatically created on first run if missing

## 🐛 Known Considerations

- Board size is fixed at 10×10 (hardcoded)
- Bomb count ranges from 10-50 based on game configuration
- Platform-specific: Uses `system("clear")` for Unix/Linux (Windows compatibility can be added)
- Input should be numeric values between 1-10 for rows and columns
- Header files are included from `../libs/` directory path
- Hints reveal mine counts but do not automatically clear cells

## 🚀 Future Enhancement Ideas

- **Difficulty Levels**: 5×5, 10×10, 20×20 board options
- **Leaderboard Display**: Show top 10 scores at startup
- **Hint Limits**: Configurable maximum hints per game
- **Replay Statistics**: Track games played and win rate
- **Cross-Platform Support**: Windows (cls) and Unix (clear) compatibility
- **Undo Feature**: Allow players to undo their last move
- **Timer Mode**: Challenges with time limits

## 📌 Requirements

- C11 compiler (GCC recommended)
- Unix/Linux/macOS environment (or Windows with WSL)
- Make build tool
- Terminal with UTF-8 support for emoji display

## 📄 License

This project is created for educational and portfolio purposes.

## ✨ Highlights for Portfolio

- ✅ Modular C architecture with separate compilation units
- ✅ Organized directory structure (libs/ and codes/ separation)
- ✅ File I/O and persistent data management
- ✅ Game state management and event loop implementation
- ✅ Dynamic memory considerations and array manipulation
- ✅ UTF-8 character encoding in C applications
- ✅ Professional build system with Makefile
- ✅ Clean code organization with header guards
- ✅ Hint system implementation with strategic gameplay
- ✅ Replay system for enhanced user experience

## 🎓 Learning Outcomes

This project demonstrates proficiency in:

- Systems programming in C
- Modular code design and organization
- File I/O operations and data persistence
- Game loop implementation and session management
- Random number generation
- Input validation and error handling
- Build automation with Make
- Professional project structure
- Feature-rich game development
- User experience enhancement through replay and hint systems
