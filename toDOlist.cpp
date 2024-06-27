#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string taskName;
    string description;
    string dueDate;
    bool Status;

    Task( const string& taskName, const string& description, const string& dueDate)
        :description(description),
        dueDate(dueDate),
        Status(false)
        {}

    void markStatus() {
        Status = true;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask() {
        string  taskName, description, dueDate;
        cout<<"Enter task name:";
        getline(cin, taskName);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter due date (DD-MM-YYYY): ";
        getline(cin, dueDate);
        tasks.emplace_back(taskName, description, dueDate);
    }

    void displayTasks() {
        if(tasks.empty()){
            cout<<"Sorry, No task available ! "<<endl;
            return ;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                      << " [Due: " << tasks[i].dueDate << "]"
                      << " [Status: " << (tasks[i].Status ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskStatus() {
        int task_number;
        cout << "Enter the task number to mark as completed: ";
        cin >> task_number;
        cin.ignore(); // To ignore the newline character left by std::cin
        if (task_number > 0 && task_number <= tasks.size()) {
            tasks[task_number - 1].markStatus();
        } else {
            cout << "Invalid task number!"<<endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        cout << "-----------------To-Do List Menu-------------------";
        cout <<endl<<"1. Add Task Name";
        cout <<endl<<"2. Display Tasks";
        cout <<endl<<"3. Mark Task as Completed";
        cout <<endl<<"4. Exit";
        cout <<endl<<"Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left by std::cin

        switch (choice) {
            case 1:
                todoList.addTask();
                break;
            case 2:
                todoList.displayTasks();
                break;
            case 3:
                todoList.markTaskStatus();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
