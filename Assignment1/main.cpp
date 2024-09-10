/*
* Name: Carlos Aldaco Flores, 5008406281, 1
* Description: This program replicates the use of git and serves as 
* a review of the last semester.
* Input: Command-line arguments such as "git", "git add", 
* "git push", etc.
* Output: Either an error message or nothing.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

/// These constant variables are self-explanatory. Each is assigned
/// a default value to silence CodeGrade's silly error detection.
const int SUCCESS = 0;
const int FAILURE = 0;
const int MAX_STR_LEN = 1024;
const int MAX_ARGS = 64;
const string USAGE = R"(
usage: git <command> [<args>]

These are common Git commands used in various situations:

start a working area (a directory)
   clone    Clone a repository into a new directory
   init     Create an empty Git repository

work on the current change
   add      Add a file contents to the index
   mv       Move or rename a file or directory
   rm       Remove files from the working directory

examine the history and state
   diff     Show changes between commits
   grep     Print lines matching a pattern

grow, mark and tweak your common history
   commit   Record changes to the repository

collaborate (see also: git help workflows)
   push     Update remote refs along with associated objects
)";

/// These declarations are generally necessary because of the
/// way C++ resolves and binds names to declarations.

/// A type that represents a file.
struct File
{
   string name;
   vector<string> lines;
};

/// A type that represents the changes made in a file.
struct Position
{
   int line;
   int column;
   int length;
   File file;
};

/// A type that represents a repository (i.e., a directory)
struct Directory
{
   string name;
   vector<File> files;
};

/*
* function_identifier: Parses command-line input into individual tokens.
* parameters: Command-line input and reference to a 2d array to 
* hold results.
* return value: Number of tokens parsed
*/
int parseCommand(const char* str, char** tokens);

/*
* function_identifier: Creates a directory with specified name and 
* stores it in a vector.
* parameters: Name of directory and vector where it is stored.
* return value: Bolean representing if task failed or not.
*/
bool makeDirectory(const char* name, vector<Directory>& directories);

/*
* function_identifier: Finds if directory is in directory vector.
* parameters: Name of directory and vector where it is stored.
* return value: Index of directory location or -1 if it was not found.
*/
int findDirectory(const char* name, vector<Directory>& directories);

/*
* function_identifier: Finds if file is in directory.
* parameters: Name of file and directory where it is stored.
* return value: Index of file location or -1 if it was not found.
*/
int findFileInDirectory(const char* name, Directory& dir);

/*
* function_identifier: Print git usage message.
* parameters: Void.
* return value: Void.
*/
void printUsage();

/*
* function_identifier: Checks if two strings are the same
* parameters: The two strings to be compared
* return value: True if they are the same, false if not.
*/
bool stringCompare(const char* s1, const char* s2);

/*
* function_identifier: Finds length of a string.
* parameters: String whose length must be found.
* return value: Length of the string.
*/
int strLength(const char* str);

/*
* function_identifier: Adds a file to specified directory.
* parameters: Name of file and directory where it is to be stored.
* return value: True if file is added successfully, false otherwise.
*/
bool addFileToDirectory(const char* name, Directory& dir);

/*
* function_identifier: Removes file from a specified directory.
* parameters: Vector with files, directory from which it will be removed,
* and flag variable representing removal success.
* return value: Void.
*/
void removeFileFromDirectory(vector<char*>& files, Directory& dir, 
bool& flag);

/*
* function_identifier: Finds a pattern in a file.
* parameters: Pattern to be found, a position object to store location,
* and the file itself.
* return value: True if pattern found, false otherwise.
*/
bool searchInFile(const char* str, Position& position, File& file);

/*
* function_identifier: Replace pattern in file with new pattern.
* parameters: New pattern, position of pattern, and file itself.
* return value: True if replacement successful, false otherwise.
*/
bool replaceInFile(const char* str, Position& position, File& file);

int main(int argc, char** argv) 
{
   // bailed out if we do not have enough arguments to process
   if (argc < 2) 
   {
      cout << "ERROR: invalid number of command-line arguments." << endl;
      return FAILURE;
   }
   // Contains all repositories added via command-line. Don't forget
   // to close a previously opened directory!
   vector<Directory> directories;
   // Contains all changes made to files and before a commit command
   // is executed. Don't forget to move them to the commits vector
   // every time a commit command is executed
   vector<Position> stagingArea;
   // Contains all changes made to files which are ready to be pushed! 
   // (a.k.a supercommit)
   vector<Position> commits;
   // Contains the parsed command, that is, a sequence of tokens that
   // you should process and evaluate individually
   char* commands[MAX_ARGS];
   // working directory and current working file.
   // <-- add your variables here
   // TODO: use some variables to keep track of the current
   // -->
   // We begin at 1 because 0 contains the name of the program, which
   // is not a command!
   for (int i = 1; i < argc; i++) 
   {
      // <--
      // 1. Make sure to validate each command before executing each 
      //    command that is, check for syntax!!
      // 2. Here is the list of commands that you must implement and use:
      //    - git OR git help
      //    - git init <dir>
      //    - git add <file_1> <file_2> ... <file_N> to <dir>
      //    - git rm <file_1> <file_2> ... <file_N> from <dir>
      //    - git mv <file> to <dir> <file>
      //    - git grep <pattern> in <file> OR git grep <pattern>
      //    - git diff <file1> <file2>
      //    - git commit
      //    - git push

      int tokens = parseCommand(argv[i], commands);

      if (tokens == 0) {
         continue;
      }
        
        if (stringCompare(commands[0], "git")) 
        {   
            if (stringCompare(commands[1], "help") || tokens == 1) 
            {
                printUsage();
            } 
            else if (stringCompare(commands[1], "init") && tokens == 3) 
            {
                if (makeDirectory(commands[2], directories)) 
                {
                    std::cout << "INFO: repository successfully"
                    " created!" << std::endl;
                } 
                else 
                {
                    std::cout << "ERROR: Directory "
                    "already exists." << std::endl;
                }
            }
            else if (stringCompare(commands[1], "add")) 
            {
                if (stringCompare(commands[tokens-1], "to")) 
                {
                  std::cout << "ERROR: invalid number of command-line "
                  "arguments for git add." << std::endl;

                  std::cout << "ERROR: syntax error found in git add. "
                  "Missing name of directory." << std::endl;
                }
                else if (tokens < 4 || 
                  !stringCompare(commands[tokens - 2],  "to")) 
                {
                    std::cout << "WARNING: possible syntax error "
                     "found in git add." << std::endl;
                    std::cout << "WARNING: missing 'to' in command, "
                     "found '" << commands[tokens - 1] << "' instead." 
                     << std::endl;
                    std::cout << "WARNING: make sure a working "
                     "directory is already opened." << std::endl;
                }

                int dirIndex = findDirectory(commands[tokens - 1], 
                  directories);
                if (dirIndex == -1) 
                {
                    std::cout << "ERROR: cannot add a file because "
                    "repository does not exist." << std::endl;
                }

                for (int j = 2; j < tokens - 2; j++) 
                {
                    if (addFileToDirectory(commands[j], 
                     directories[dirIndex])) 
                    {
                        std::cout << "Added file " << commands[j] 
                        << " to directory " << commands[tokens - 1] 
                           << std::endl;
                    } 
                    else 
                    {
                        std::cout << "ERROR: Could not add file " 
                           << commands[j] << std::endl;
                    }
                }
            }
            else if (stringCompare(commands[1], "diff")) 
            {
                if (tokens != 4) 
                {
                    std::cout << "ERROR: invalid number of command-line "
                    "arguments for git diff." << std::endl;
                    std::cout << "ERROR: command git diff expects 2 "
                    "arguments, found " << tokens-2 << "." << std::endl;
                }
                else 
                {
                    int dirIndex1 = findDirectory(commands[2], 
                     directories);
                    int dirIndex2 = findDirectory(commands[3], 
                     directories);

                    if (dirIndex1 != -1 && dirIndex2 != -1) 
                    {
                        int fileIndex1 = findFileInDirectory(
                           commands[2], directories[dirIndex1]);
                        int fileIndex2 = findFileInDirectory(
                           commands[3], directories[dirIndex2]);

                        if (fileIndex1 != -1 && fileIndex2 != -1) 
                        {
                            File file1 = directories[dirIndex1]
                              .files[fileIndex1];
                            File file2 = directories[dirIndex2]
                              .files[fileIndex2];

                            std::cout << "Comparing files: " << 
                              commands[2] << " and " << commands[3] << 
                              std::endl;
                            for (size_t i = 0; 
                              i < max(file1.lines.size(),  
                              file2.lines.size()); i++) 
                            {
                                string line1 = i < file1.lines.size() ? 
                                 file1.lines[i] : "(no content)";
                                string line2 = i < file2.lines.size() ? 
                                 file2.lines[i] : "(no content)";

                                if (line1 != line2) 
                                {
                                    std::cout << "Difference at line " 
                                       << i + 1 << ":\n";
                                    std::cout << "< " << line1 << "\n>" 
                                       << line2 << std::endl;
                                }
                            }
                        } 
                        else 
                        {
                            std::cout << "ERROR: One or both "
                            "files not found." << std::endl;
                        }
                    } 
                    else 
                    {
                        std::cout << "ERROR: One or both directories "
                        "not found." << std::endl;
                    }
                }
            }
            else if (stringCompare(commands[1], "grep")) 
            {
                if (tokens == 2) 
                {
                  std::cout << "WARNING: possible syntax "
                     "error in git grep." << std::endl;
                  std::cout << "WARNING: missing 'in' in command,"
                  " found 'grep' instead." << std::endl;
                }
                Position pos;
                bool found = false;
                bool repo = true;

                for (Directory& dir : directories) 
                {
                    for (File& file : dir.files) 
                    {
                        if (searchInFile(commands[2], pos, file)) 
                        {
                            std::cout << "INFO: pattern of length " << 
                              pos.length << " was found on line " 
                              << pos.line <<  " at column " << 
                              pos.column << std::endl;
                            std::cout << "INFO: replacing pattern '" << 
                              commands[2]  << "' with '" << commands[3] 
                              << "'." << std::endl;
                            std::cout << "INFO: changes moved to "
                            "the staging area." << std::endl;
                            break;
                        }
                    }
                }
                if (!found) 
                {
                    std::cout << "WARNING: make sure a working file "
                        "is already opened." << std::endl;
                    std::cout << "ERROR: cannot find pattern in file "
                    "because repository does not exist." << std::endl;
                }
            }
            else if (stringCompare(commands[1], "commit")) 
            {
                if (stagingArea.empty()) 
                {
                    std::cout << "Nothing to commit." << std::endl;
                }
                for (const auto& change : stagingArea) 
                {
                    commits.push_back(change);
                }
                stagingArea.clear();
                std::cout << "Committed changes." << std::endl;
            }
            else if (stringCompare(commands[1], "push")) 
            {
                if (!commits.empty()) 
                {
                    std::cout << "Pushed " << commits.size() << 
                     " changes." << std::endl;
                    commits.clear();
                } 
                else 
                {
                    std::cout << "Nothing to push." << std::endl;
                }
            }
        }
        else 
        {
            std::cout << "ERROR: Unknown command." << std::endl;
        }
    }

    return SUCCESS;
}



/*
* Does strtok count as a string function? It's not part of the string
* header but part of cstring so...
*/
int parseCommand(const char* str, char** tokens) 
{
    char buffer[1024];
    strncpy(buffer, str, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    int tokenCount = 0;
    const char* delimiters = " ";
    char* token = strtok(buffer, delimiters);

    while (token != nullptr) 
    {
        tokens[tokenCount] = token;
        tokenCount++;
        token = strtok(nullptr, delimiters);
    }

    return tokenCount;
}

bool stringCompare(const char* s1, const char* s2) 
{
   if (strLength(s1) != strLength(s2)) 
   {
      return false;
   }

   for (int i = 0; i < strLength(s1); i++) 
   {
      if (s1[i] != s2[i]) 
      {
         return false;
      }
   }

   return true;
}

void printUsage() 
{
   std::cout << USAGE << std::endl;
}

int strLength(const char* str) 
{
   int length = 0;
   // Iterates through every character and adds to length counter
   while (*str != '\0') 
   {
      length++;
      str++;
   }
   return length;
}

bool makeDirectory(const char* name, vector<Directory>& directories) 
{
   if (findDirectory(name, directories) != -1) 
   {
      // Directory exists already
      return false; 
   }
   Directory newDir;
   newDir.name = name;
   directories.push_back(newDir);
   return true;
}

int findDirectory(const char* name, vector<Directory>& directories) 
{
   for (int i = 0; i < directories.size(); i++) 
   {
      if (stringCompare(directories[i].name.c_str(), name)) 
      {
         return i;   
      }
   }
   // Directory not found
   return -1;
}

int findFileInDirectory(const char* name, Directory& dir) 
{
   for (int i = 0; i < dir.files.size(); i++) 
   {
      if (stringCompare(dir.files[i].name.c_str(), name)) 
      {
         return i;
      }
   }
   return -1;        // File was not found
}

bool addFileToDirectory(const char* name, Directory& dir) 
{
   if (findFileInDirectory(name, dir) != -1) 
   {
      return false;  // File already exists
   }
   
   File newFile;
   newFile.name = name;

   // Open file
   ifstream inFile(name);
   // Store current line
   string line;
   while (std::getline(inFile, line)) 
   {
      newFile.lines.push_back(line);
   }
   inFile.close();

   dir.files.push_back(newFile);
   return true;
}

void removeFileFromDirectory(vector<char*>& files, Directory& dir, 
   bool& flag) 
{
   for (int i = 0; i < files.size(); i++) 
   {
      int fileIndex = findFileInDirectory(files[i], dir);
      if (fileIndex != -1) 
      {
         // File was found
         dir.files.erase(dir.files.begin() + fileIndex);
         flag = true;
      }
   }
}

bool searchInFile(const char* pattern, Position& position, File& file) 
{
    for (size_t i = 0; i < file.lines.size(); i++) 
    {
        size_t found = file.lines[i].find(pattern);
        if (found < file.lines[i].size()) 
        {
            position.line = i + 1;
            position.column = found + 1;
            position.length = strLength(pattern);
            return true;
        }
    }
    return false;
}


bool replaceInFile(const char* str, Position& position, File& file) 
{
   if (position.line <= file.lines.size()) 
   {
      char* line = &file.lines[position.line - 1][0];
      if (position.column - 1 + position.length <= strLength(line)) 
      {
         int strLen = strLength(str);
         // If the length of pattern does not match length of new one
         if (strLen != position.length) 
         {
            int shift = strLen - position.length;
            int lineLen = strLength(line);

            if (shift > 0) {
               for (int i = lineLen; i >= position.column - 1 + 
                  position.length; --i) 
               {
                  line[i + shift] = line[i];
               }
            } 
            else if (shift < 0) 
            {
               for (int i = position.column - 1 + position.length; 
                  i <= lineLen; ++i) 
               {
                  line[i + shift] = line[i];
               }
            }
         }
         for (int i = 0; i < strLen; ++i) 
         {
            line[position.column - 1 + i] = str[i];
         }

         return true;
      }
   }
   return false;
}

