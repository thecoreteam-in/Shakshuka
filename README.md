# Shakshuka C++ Desktop Productivity App

## Project Overview
Shakshuka is a C++ desktop productivity application designed to help users manage their tasks efficiently. With a user-friendly interface and powerful features, it aims to enhance productivity through effective planning and organization.

## Features
- **Task Management**: Create, update, and delete tasks. Organize tasks into lists for better management.
- **Daily Planner**: Plan your day with a built-in calendar that allows scheduling and reminders.
- **Data Security**: Ensure data privacy and security with robust encryption and user authentication measures.
- **System Tray Integration**: Access the application quickly from the system tray, minimizing distractions.
- **Auto-Save & Backup**: Automatically save your progress and create backups to prevent data loss.
- **Analytics Dashboard**: Visualize your productivity trends with an analytics dashboard that provides insights into tasks completed over time.
- **Import/Export**: Easily import tasks from other applications or export your tasks for backup and sharing.
- **Windows Autostart**: Option to launch the application automatically on Windows startup.
- **Cross-Platform Support**: Compatible with multiple operating systems, including Windows, macOS, and Linux.

## Technical Architecture
The application is built using C++ with a focus on modular design, making it easy to maintain and extend. The architecture consists of:
- **User Interface**: Built using a modern C++ GUI framework.
- **Backend Services**: Implemented in C++ to handle data management and processing.
- **Database Layer**: Integrates with SQLite for data storage.

## Build Instructions
To build the Shakshuka application, follow these steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/thecoreteam-in/Shakshuka.git
   cd Shakshuka
   ```
2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```
3. Run CMake:
   ```bash
   cmake ..
   ```
4. Compile the application:
   ```bash
   make
   ```

## Deployment Options
Shakshuka can be deployed using various methods:
- **MSIX**: Use the MSIX packaging format for seamless installation on Windows.
- **Inno Setup**: Create a Windows installer using Inno Setup for easy distribution.

## Contribution Guidelines
We welcome contributions to the Shakshuka project! Please follow these guidelines:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your branch and create a pull request.
5. Ensure that your code adheres to the project's coding standards.

Thank you for your interest in contributing to Shakshuka!