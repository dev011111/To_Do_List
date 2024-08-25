#include <iostream>
#include <cstring>

using namespace std;

const int MAX_TASKS = 10;
const int MAX_DESCRIPTION_LENGTH = 50;

struct Task {
    char description[MAX_DESCRIPTION_LENGTH];
    bool completed;
};

void addTask(Task tasks[], int &taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full. Cannot add more tasks." << endl;
        return;
    }
    cout << "Enter the task description: ";
    cin.ignore(); 
    cin.getline(tasks[taskCount].description, MAX_DESCRIPTION_LENGTH);
    tasks[taskCount].completed = false;
    taskCount++;
    cout << "Task added successfully!" << endl;
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to display." << endl;
        return;
    }
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
    }
}

void markTaskCompleted(Task tasks[], int taskCount) {
    viewTasks(tasks, taskCount);
    if (taskCount == 0) return;

    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber <= 0 || taskNumber > taskCount) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
}

void removeTask(Task tasks[], int &taskCount) {
    viewTasks(tasks, taskCount);
    if (taskCount == 0) return;

    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber <= 0 || taskNumber > taskCount) {
        cout << "Invalid task number!" << endl;
    } else {
    	
        for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully!" << endl;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
