// diary.h
#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

// The Diary class represents a personal diary application,
// allowing for adding, retrieving, removing, and listing diary entries.
class Diary {
public:
    // Constructor initializes the diary by loading entries from the file.
    // @param filename: Name of the file where entries are stored.
    Diary(const std::string &filename) : filename(filename) {
        load();
    }

    // Destructor saves all entries back to the file when the program ends.
    ~Diary() {
        save(); 
    }

    // Adds or updates an entry for a specific date.
    // @param date: The date of the entry.
    // @param content: The content of the diary entry.
    void addEntry(const std::string &date, const std::string &content) {
        entries[date] = content; 
    }

    // Retrieves the content of an entry for a specific date.
    // @param date: The date of the entry to retrieve.
    // @return: The content of the diary entry, or an empty string if not found.
    std::string getEntry(const std::string &date) const {
        auto it = entries.find(date); 
        return it != entries.end() ? it->second : ""; 
    }

    // Removes an entry for a specific date.
    // @param date: The date of the entry to remove.
    // @return: True if the entry was successfully removed, false if not found.
    bool removeEntry(const std::string &date) {
        return entries.erase(date) > 0; 
    }

    // Lists all entries within an optional date range.
    // If no range is provided, all entries are listed.
    // @param start: The starting date of the range (inclusive).
    // @param end: The ending date of the range (inclusive).
    void listEntries(const std::string &start = "", const std::string &end = "") const {
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            const std::string &date = it->first;    

            
            if ((start.empty() || date >= start) && (end.empty() || date <= end)) {
                std::cout << date << std::endl;
            }
        }
    }

private:
    std::string filename;                 // File name where diary entries are stored
    std::map<std::string, std::string> entries; // Map to store entries with date as key

    // Loads entries from the file into the `entries` map.
    // Each line in the file is expected to be in the format: "date content".
    void load() {
        std::ifstream file(filename); 
        std::string line, date, content;
        
        // Read each line and parse date and content
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::getline(iss, date, ' '); 
            std::getline(iss, content);  
            entries[date] = content; 
        }
    }

    // Saves all entries from the `entries` map back to the file.
    // Each line in the file will be saved in the format: "date content".
    void save() const {
        std::ofstream file(filename);

        // Write each entry to the file
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            const std::string &date = it->first;    
            const std::string &content = it->second; 
            file << date << " " << content << std::endl; 
        }
    }
};

#endif // DIARY_H
