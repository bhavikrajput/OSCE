#include <stdio.h>
#include <string.h>

// Function to tokenize a command line
int tokenizeCommandLine(char command[], char *tokens[]) {
    char *currentToken;
    int tokenCount = 0;

    currentToken = strtok(command, " \t\n"); // Split by space, tab, or newline

    while (currentToken != NULL) {
        tokens[tokenCount] = currentToken;
        tokenCount++;
        currentToken = strtok(NULL, " \t\n");
    }

    return tokenCount;
}

int main() {
    char userInput[100]; // Store the user's input command
    char *commandTokens[4];   // Store tokens (command and arguments)

    // Prompt the user for a command
    printf("MyShell$ ");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove the newline character from the input
    userInput[strcspn(userInput, "\n")] = '\0';

    // Tokenize the user's command
    int tokenCount = tokenizeCommandLine(userInput, commandTokens);

    // Check if the command has the correct number of tokens and format
    if (tokenCount == 3 && strcmp(commandTokens[0], "COUNT") == 0 && strcmp(commandTokens[1], "CWL") == 0) {
        char *fileName = commandTokens[2];

        // Simulate executing the "COUNT CWL" command
        FILE *file = fopen(fileName, "r");
        if (file != NULL) {
            int characterCount = 0;
            int wordCount = 0;
            int lineCount = 0;
            int currentCharacter;
            int insideWord = 0;

            while ((currentCharacter = fgetc(file)) != EOF) {
                characterCount++;

                if (currentCharacter == ' ' || currentCharacter == '\t' || currentCharacter == '\n') {
                    if (insideWord) {
                        wordCount++;
                        insideWord = 0;
                    }
                    if (currentCharacter == '\n') {
                        lineCount++;
                    }
                } else {
                    insideWord = 1;
                }
            }

            if (insideWord) {
                wordCount++;
            }

            // Display the results
            printf("Number of characters: %d\n", characterCount);
            printf("Number of words: %d\n", wordCount);
            printf("Number of lines: %d\n", lineCount);

            fclose(file);
        } else {
            printf("Error: Unable to open the file.\n");
        }
    } else {
        printf("Invalid command format. Use 'COUNT CWL <filename>'.\n");
    }

    return 0;
}
