# todo
Simple command line todo for Linux (just like the other 3000 of these)

# dependencies
- g++ or any other c++ compiler

# setup
I made a `setup.sh` file that compiles the file for you, makes some folders for data and moves the file to /usr/bin.

To run it:

`chmod +x setup.sh`

`./setup.sh`

# commands
Current commands:
- `add`    - Adds a task item to the list. Example: `todo add "Buy groceries"`
- `list`   - Displays all tasks
- `remove` - Removes a given task. Example: `todo remove 1`
- `clear`  - Clears the list of tasks
- `help`   - **Currently not available**
