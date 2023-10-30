#include <iostream>
#include <vector>
#include <string>

using namespace std; 

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& taskList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < taskList.size(); i++) {
            cout << "[" << (i + 1) << "] ";
            if (taskList[i].completed) {
                cout << "[Completed] ";
            } else {
                cout << "[Pending]   ";
            }
            cout << taskList[i].description << endl;
        }
    }
}

void markTaskCompleted(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].completed = true;
        cout << "Task marked as completed: " << taskList[taskIndex].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        cout << "Task removed: " << taskList[taskIndex].description << endl;
        taskList.erase(taskList.begin() + taskIndex);
    } 
    else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout<<"-----------MENU-------------"<<endl;
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice (1-5): ";
        cout<<"-----------------------------"<<endl;
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            string description;
            cout << "Enter the task description: ";
            cin.ignore();
            getline(cin, description);
            addTask(taskList, description);
        } 
        else if (choice == 2) {
            viewTasks(taskList);
        } 
        else if (choice == 3) {
            int taskIndex;
            cout << "Enter the task index to mark as completed: ";
            cin >> taskIndex;
            markTaskCompleted(taskList, taskIndex - 1); 
        } 
        else if (choice == 4) {
            int taskIndex;
            cout << "Enter the task index to remove: ";
            cin >> taskIndex;
            removeTask(taskList, taskIndex - 1); 
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
        }
    }

    return 0;
}
