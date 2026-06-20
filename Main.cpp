#include <iostream>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

std::string categoryFor(const std::string& extension) {
    std::map<std::string, std::string> categoryMap = {
        {".txt", "Text Files"},
        {".jpg", "Image Files"},
        {".png", "Image Files"},
        {".pdf", "PDF Files"},
        {".cpp", "C++ Source Files"},
        {".h", "Header Files"}
        {".mp3", "Audio Files"},
        {".mp4", "Video Files"},
        {".zip", "Compressed Files"}
    };
    if (categoryMap.find(extension) != categoryMap.end()) {
        return categoryMap[extension];
    } else {
        return "Unknown Category";
    }
}

int main() {
    std::string folderexample = "example_folder";

    if (!fs::exists(folderexample)) {
        fs::create_directory(folderexample);
        std::cout << "Folder created: " << folderexample << std::endl;
    } else {
        std::cout << "Folder already exists: " << folderexample << std::endl;
    }

    bool apply = true;   // false = preview only; true = actually move files

    for (const auto& entry : fs::directory_iterator(folderexample)) {
        if (!entry.is_regular_file()) continue;   // skip folders, only handle files

        std::string name = entry.path().filename().string();
        std::string extension = entry.path().extension().string();
        std::string category = categoryFor(extension);

        // build the destination: example_folder/Category/filename
        fs::path destDir = fs::path(folderexample) / category;
        fs::path destPath = destDir / name;

        std::cout << name << "  ->  " << category << "/\n";

        if (apply) {
            fs::create_directories(destDir);        // make the category folder if needed
            fs::rename(entry.path(), destPath);     // move the file into it
        }
    }

    if (!apply) {
        std::cout << "\n(Preview only. Set apply = true to actually move files.)\n";
    }

    return 0;
}