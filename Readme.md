# MyTop

MyTop is a lightweight system monitoring tool inspired by the `top` command. It provides real-time information about system processes, memory usage, CPU load, and other essential metrics in a user-friendly terminal interface.

## Features

- **Process Monitoring**: Displays detailed information about running processes, including PID, user, priority, nice value, and command.
- **System Metrics**:
  - Memory usage (total, free, used, and cached).
  - CPU usage statistics.
  - Load averages.
  - Uptime and number of users.
- **Task States**: Tracks the number of tasks in various states (running, sleeping, stopped, zombie).
- **Customizable Output**: Highlights key metrics for better readability using bold formatting.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Nielsen-ls/B-PSU-100-MPL-1-1-mytop.git
   cd B-PSU-100-MPL-1-1-mytop
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./my_top
   ```

## Usage

- **Start the program**: Run `./my_top` in your terminal.
- **Quit the program**: Press `q` to exit.
- **Refresh rate**: The display refreshes every 3 seconds by default.

## File Structure

- **Source Files**:
  - `my_getuser.c`: Retrieves the number of logged-in users.
  - `my_getuptime.c`: Calculates system uptime.
  - `my_getpriority.c` and `my_getnice.c`: Fetch process priority and nice values.
  - `my_getnbtask.c`: Counts the number of tasks and their states.
  - `my_getmemused.c`: Calculates used memory.
  - `my_getloadavg.c`: Reads system load averages.
  - `my_getcommand.c`: Extracts the command name of a process.
  - `my_checkstate.c`: Determines the state of a process.
  - `make_filepath.c`: Constructs file paths for `/proc` entries.
  - `get_taskinfo.c`: Gathers and displays task information.
  - `header.c`: Displays the header section of the interface.
  - `bold.c`: Handles bold formatting for numeric values.
  - `hour.c`: Displays the current time.
  - `isfile.c`: Checks if a file exists and is regular.
- **Header File**:
  - `include/my.h`: Contains all function prototypes and type definitions.
- **Makefile**: Automates the build process.

## Dependencies

- **Libraries**:
  - `ncurses`: Used for terminal-based UI rendering.
- **System Requirements**:
  - Linux-based operating system (relies on `/proc` filesystem).

## Acknowledgments

- Inspired by the `top` command-line utility.
- Developed as part of the EPITECH 2024 curriculum.