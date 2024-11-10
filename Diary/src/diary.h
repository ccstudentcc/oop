#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

// The Diary class represents a personal diary application,
// allowing for adding, retrieving, removing, and listing diary entries.
class Diary
{
public:
    // Constructor initializes the diary by loading entries from the file.
    // @param filename: Name of the file where entries are stored.
    Diary(const std::string &filename) : filename(filename)
    {
        load();
    }

    // Destructor saves all entries back to the file when the program ends.
    ~Diary()
    {
        save();
    }

    // Adds or updates an entry for a specific date.
    // @param date: The date of the entry.
    // @param content: The content of the diary entry.
    void addEntry(const std::string &date, const std::string &content)
    {
        entries[date] = content;  // Overwrites the entry if it exists
    }

    // Retrieves the content of an entry for a specific date.
    // @param date: The date of the entry to retrieve.
    // @return: The content of the diary entry, or an empty string if not found.
    std::string getEntry(const std::string &date) const
    {
        auto it = entries.find(date);
        return it != entries.end() ? it->second : "";
    }

    // Removes an entry for a specific date.
    // @param date: The date of the entry to remove.
    // @return: True if the entry was successfully removed, false if not found.
    bool removeEntry(const std::string &date)
    {
        return entries.erase(date) > 0;
    }

    // Lists all entries within an optional date range.
    // If no range is provided, all entries are listed.
    // @param start: The starting date of the range (inclusive).
    // @param end: The ending date of the range (inclusive).
    void listEntries(const std::string &start = "", const std::string &end = "") const
    {
        bool found = false;
        for (auto it = entries.begin(); it != entries.end(); ++it)
        {
            const std::string &date = it->first;

            if ((start.empty() || date >= start) && (end.empty() || date <= end))
            {
                std::cout << date << " " << it->second << std::endl;
                found = true;
            }
        }
        if (!found)
        {
            std::cout << "No entries found in the specified range." << std::endl;
        }
    }

private:
    std::string filename;                       // File name where diary entries are stored
    std::map<std::string, std::string> entries; // Map to store entries with date as key

    // Loads entries from the file into the `entries` map.
    // Each line in the file is expected to be in the format: "date content".
    void load()
    {
        std::ifstream file(filename);
        std::string line, date, content;
        bool readingContent = false;

        // Read each line and parse date and content
        while (std::getline(file, line))
        {
            line = trim(line); // Trim leading/trailing spaces

            if (line == ".") // End of entry
            {
                if (!date.empty())
                {
                    entries[date] = content; // Store entry for the date
                }
                readingContent = false;
                content.clear();
            }
            else if (readingContent)
            {
                content += "\n" + line; // Append new line to the content
            }
            else
            {
                std::istringstream iss(line);
                std::getline(iss, date, ' ');
                date = trim(date); // Trim date
                content = line.substr(date.length());
                content = trim(content); // Trim content
                readingContent = true;
            }
        }
    }

    // Saves all entries from the `entries` map back to the file.
    // Each line in the file will be saved in the format: "date content".
    void save() const
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cerr << "Failed to open file for writing: " << filename << std::endl;
            return; // Exit if file opening fails
        }

        for (auto it = entries.begin(); it != entries.end(); ++it)
        {
            file << it->first << " " << trim(it->second) << "\n.\n";  // Save without extra spaces
        }
    }

    // Helper function to trim leading and trailing spaces from a string
    std::string trim(const std::string& str) const
    {
        size_t start = str.find_first_not_of(" \t\n\r");
        size_t end = str.find_last_not_of(" \t\n\r");
        return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
    }
};

#endif // DIARY_H

