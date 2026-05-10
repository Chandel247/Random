#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
namespace fs=std::filesystem;

bool isExecutable(const std::string& path) {
    // 1. Check if the file exists and is a regular file
    if (!fs::exists(path) || !fs::is_regular_file(path)) {
        return false;
   }

    // 2. Check for execution permissions
    fs::perms p = fs::status(path).permissions();
    return (p & fs::perms::owner_exec) != fs::perms::none ||
          (p & fs::perms::group_exec) != fs::perms::none ||
            (p & fs::perms::others_exec) != fs::perms::none;
}

std::string in_Path(const std::string& path){
    std::vector<std::string> path_dirs;
    std::stringstream ss(std::getenv("PATH"));
    std::string path_dir;
    while (std::getline(ss, path_dir, ':')){
        path_dirs.push_back(path_dir);
    }
    for (std::string dirs:path_dirs){
        if (fs::exists(dirs) && fs::is_directory(dirs)){
            for (fs::directory_iterator next(dirs), end; next!= end; ++next){
                const fs::directory_entry& entry=*next;
                    if (entry.path().filename().string() == path && isExecutable(entry.path())){
                        return entry.path().string();
                    }
            }
        }
    }
    return "-1";
}

int main() {
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
   
    std::vector<std::string> shell_cmd={"exit","echo","type","pwd"};
    while (true){
        std::cout << "$ ";

        std::string cmd;
        std::getline(std::cin, cmd);

        std::string command=cmd.substr(0,cmd.find(' '));
        std::string parameters;

        const std::size_t parameterIndex=cmd.find(' ')+1;
        if (parameterIndex != std::string::npos){
            parameters=cmd.substr(cmd.find(' ')+1);
        }
        
        if (command=="exit"){
            break;
        }
        else if (command=="echo"){
            std::cout<<parameters<<'\n';
        }
        else if (command=="type"){
            bool found=false;
            if (std::find(shell_cmd.begin(), shell_cmd.end(), parameters)!=shell_cmd.end()){
                std::cout<<parameters<<" is a shell builtin"<<std::endl;
                found=true;
            }
            if (!found){
                std::string path_name=in_Path(parameters);
                if (path_name!="-1"){
                    std::cout<<parameters<<" is "<<path_name<<std::endl;
                    found=true;
                }
                if (!found) std::cout<<parameters<<": not found"<<std::endl;
            }
        }
        else if (command=="pwd"){
            std::cout<<fs::current_path().string()<<std::endl;
        }
        else{
            std::string path_name=in_Path(command);
            if (path_name!="-1"){
                std::system(cmd.c_str());
            }
            else {
                std::cout<<command<<": command not found"<<std::endl;
            }
        }
    }
}
