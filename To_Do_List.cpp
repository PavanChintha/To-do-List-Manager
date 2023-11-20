#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Task {
public:
    Task(string description, string due_date) {
        this->description = description;
        this->due_date = due_date;
        this->completed = false;
    }

    void mark_completed() {
        this->completed = true;
    }

    void mark_pending() {
        this->completed = false;
    }

    bool is_completed() {
        return this->completed;
    }

    string get_description() {
        return this->description;
    }

    string get_due_date() {
        return this->due_date;
    }

private:
    string description;
    string due_date;
    bool completed;
};

class ToDoList {
public:
    void add_task(Task task) {
        tasks.push_back(task);
    }

    void delete_task(int index) {
        tasks.erase(tasks.begin() + index);
    }

    void mark_task_completed(int index) {
        tasks[index].mark_completed();
    }

    void mark_task_pending(int index) {
        tasks[index].mark_pending();
    }

    void view_all_tasks() {
        cout << "All Tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].get_description() << " - ";
            if (tasks[i].is_completed()) {
                cout << "Completed";
            } else {
                cout << "Pending";
            }
            cout << ", Due: " << tasks[i].get_due_date() << endl;
        }
    }

    void view_completed_tasks() {
        cout << "Completed Tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].is_completed()) {
                cout << i + 1 << ". " << tasks[i].get_description() << ", Due: " << tasks[i].get_due_date() << endl;
            }
        }
    }

    void view_pending_tasks() {
        cout << "Pending Tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            if (!tasks[i].is_completed()) {
                cout << i + 1 << ". " << tasks[i].get_description() << ", Due: " << tasks[i].get_due_date() << endl;
            }
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    ToDoList todo_list;

    while (true) {
        cout << "What would you like to do?" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. Mark a task as completed" << endl;
        cout << "3. Mark a task as pending" << endl;
        cout << "4. Delete a task" << endl;
        cout << "5. View all tasks" << endl;
        cout << "6. View completed tasks" << endl;
        cout << "7. View pending tasks" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string description, due_date;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter due date (YYYY-MM-DD): ";
                cin >> due_date;
                Task task(description, due_date);
                todo_list.add_task(task);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2: {
                int index;
                cout << "Enter task index: ";
                cin >> index;
                todo_list.mark_task_completed(index - 1);
                cout << "Task marked as completed!" << endl;
                break;
            }
            case 3: {
                int index;
                cout << "Enter task index: ";
                cin >> index;
                todo_list.mark_task_pending(index - 1);
                cout << "Task marked as pending!" << endl;
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index: ";
                cin >> index;
                todo_list.delete_task(index - 1);
                cout << "Task deleted successfully!" << endl;
                break;
            }
            case 5: {
                todo_list.view_all_tasks();
                break;
            }
            case 6: {
                todo_list.view_completed_tasks();
                break;
            }
            case 7: {
                todo_list.view_pending_tasks();
                break;
            }
            case 8: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}
