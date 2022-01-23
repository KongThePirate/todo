# todo
Simple command line todo for Linux (just like the other 3000 of these)

# dependencies
- g++ or any other c++ compiler

# setup
Standard makefile procedure

`make` to compile it

`make install` to install the file to /usr/bin (you'll need root privileges so it run with sudo/doas)

`make clean` to remove any binaries in the source folder and residual data (this will clear all your todo lists)

`make uninstall` to uninstall from /usr/bin (you'll need root privileges again)

# commands
Current commands:
- `add`    - Adds a task item to the list. Example: `todo add "Buy groceries"`
- `list`   - Displays all tasks
- `remove` - Removes a given task. Example: `todo remove 1`
- `clear`  - Clears the list of tasks
