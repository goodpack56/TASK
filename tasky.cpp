#include <iostream>
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

class Task {
    public:
        std::string description;
        bool completed;

        Task(std::string desc, bool comp) : description(desc), completed(comp) {}
};

int main() {
    std::vector<Task> tasks;
    int choice;
sf::Music music;
if (!music.openFromFile("GloRilla-I-LUV-HER-_feat.-T-Pain_-_Official-Music-Video_-GloRillaVEVO.wav")) { // Use .ogg or .wav for best compatibility
    std::cout << "Could not load music file!" << std::endl;
} else {
    music.setVolume(300)
    music.setLooping(true); // Optional: loop the music
    music.play();
}


    do{
        std::cout << "Welcome to Tasky - Your Task Management CLI" << std::endl;
        std::cout << "Please pick an option:" <<std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Edit a Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
    
    
        std::cin >> choice;
        std::cin.ignore();



        if (choice == 1) {
            std::string desc;
            std::cout << "Enter Task Description: ";
            std::getline(std::cin, desc);
            Task newTask(desc, false);
            tasks.push_back(newTask);
            std::cout << "Task added!" << std::endl;
}
        if (choice == 2) {
            std::cout << "Your Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description
                            << (tasks[i].completed ? " [Completed]" : " [Pending]") << std::endl;
            }
        }

        if (choice == 3) {
            int Tasknum;
            std::cout << "Enter Task Number to Mark as Completed: " << std::endl;
            std::cin >> Tasknum;   
            if (Tasknum > 0 && Tasknum <= tasks.size()) {
                tasks[Tasknum - 1].completed = true;
                std::cout << "Marked as completed!" << std::endl;
                std::cin.ignore();
            }
        
    }
        
        if (choice == 4) {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << std::endl;
            }
            int taskNum;
            std::cout << "Enter the number of the task youd like to edit" << std::endl;
            std::cin >> taskNum;
            std::cin.ignore();
            if (taskNum > 0 && taskNum <= tasks.size()) {
                std::string newDesc;
                std::cout << "Please enter the new description" << std::endl;
                std::getline(std::cin, newDesc);
                tasks[taskNum - 1].description = newDesc;
                std::cout << "Task description updated" << std::endl;
            } else {
                std::cout << "Please pick a valid Task" << std::endl;
            }
        
 
    }
    } while (choice != 5);

    std::cout << "Exiting Tasky. Goodbye!" << std::endl;
    return 0;
}
    
    


