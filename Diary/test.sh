#!/bin/bash

# Define the diary file path and log file path
DIARY_FILE="diary.txt"
LOG_FILE="log.txt"

# Ensure the diary and log files exist
touch $DIARY_FILE
touch $LOG_FILE
> $LOG_FILE # Clear the log file before starting

echo "Running diary management use cases..." | tee -a $LOG_FILE

# --- Use case 1: Add entries to the diary ---
echo "Adding entries for dates 2024-11-01, 2024-01-01, 2024-12-01, 2024-06-12, 2024-11-02, and 2024-11-03" | tee -a $LOG_FILE

# Add entries with respective dates and content
echo -e "First entry for November 1st.\n." | ./pdadd 2024-11-01 | tee -a $LOG_FILE
echo -e "First entry for January 1st.\n." | ./pdadd 2024-01-01 | tee -a $LOG_FILE
echo -e "Second entry for December 1st.\n." | ./pdadd 2024-12-01 | tee -a $LOG_FILE
echo -e "Second entry for June 12th.\n." | ./pdadd 2024-06-12 | tee -a $LOG_FILE
echo -e "Second entry for November 2nd.\n." | ./pdadd 2024-11-02 | tee -a $LOG_FILE
echo -e "Third entry for November 3rd.\n." | ./pdadd 2024-11-03 | tee -a $LOG_FILE

# --- Use case 2: List all diary entries ---
echo -e "\nListing all entries in the diary:" | tee -a $LOG_FILE
./pdlist | tee -a $LOG_FILE

# --- Use case 3: List diary entries within a date range ---
echo -e "\nListing entries from 2024-11-01 to 2024-11-03:" | tee -a $LOG_FILE
./pdlist 2024-11-01 2024-11-03 | tee -a $LOG_FILE

# --- Use case 4: Show a specific entry ---
echo -e "\nShowing entry for date 2024-06-12:" | tee -a $LOG_FILE
./pdshow 2024-06-12 | tee -a $LOG_FILE

# --- Use case 5: Update an existing entry ---
echo -e "\nUpdating entry for 2024-11-02 with new content." | tee -a $LOG_FILE
echo -e "Updated entry for November 2nd.\n." | ./pdadd 2024-11-02 | tee -a $LOG_FILE

# Verify update
echo -e "\nShowing updated entry for date 2024-11-02:" | tee -a $LOG_FILE
./pdshow 2024-11-02 | tee -a $LOG_FILE

# --- Use case 6: Remove a specific entry ---
echo -e "\nRemoving entry for 2024-11-01." | tee -a $LOG_FILE
./pdremove 2024-11-01 | tee -a $LOG_FILE

# Verify removal
echo -e "\nTrying to show entry for 2024-11-01 (should not exist):" | tee -a $LOG_FILE
./pdshow 2024-11-01 | tee -a $LOG_FILE

# List all entries after removal
echo -e "\nListing all entries after removal:" | tee -a $LOG_FILE
./pdlist | tee -a $LOG_FILE

echo -e "\nDiary management use cases completed." | tee -a $LOG_FILE
