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

## Dependencies

- **Libraries**:
  - `ncurses`: Used for terminal-based UI rendering.
- **System Requirements**:
  - Linux-based operating system (relies on `/proc` filesystem).

## Acknowledgments

- Inspired by the `top` command-line utility.
