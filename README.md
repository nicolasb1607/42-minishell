# Project Minishell

## Introduction

The existence of shells is linked to the very existence of IT. At the time, all developers agreed that communicating with a computer using aligned 1/0 switches was seriously irritating. It was only logical that they came up with the idea of creating software to communicate with a computer using interactive lines of commands in a language somewhat close to human language. Thanks to Minishell, you’ll be able to travel through time and come back to problems people faced when Windows didn’t exist.

## Common Instructions

Before diving into the project details, let's review some common instructions that apply to this project:

- **Language**: Your project must be written in C.

- **Norm Compliance**: Your project must adhere to the Norm. Norm errors, including those in bonus files/functions, will result in a score of 0.

- **Stability**: Your functions should not quit unexpectedly (e.g., segmentation fault, bus error, double free) apart from undefined behaviors. Unexpected crashes will lead to a non-functional evaluation.

- **Memory Management**: Properly free all heap allocated memory space. No leaks will be tolerated.

- **Makefile**: If required by the subject, include a Makefile to compile your source files with the flags -Wall, -Wextra, and -Werror using cc. Ensure your Makefile does not relink and includes the rules $(NAME), all, clean, fclean, and re.

- **Bonuses**: If applicable, create a bonus rule in your Makefile to include headers, libraries, or functions forbidden in the main part of the project. Store bonus code in separate _bonus.{c/h} files.

- **Libft Integration**: If permitted, integrate your libft by copying its sources and associated Makefile into a libft folder with its own Makefile. Your project’s Makefile should compile the library via its Makefile, then compile the project.

- **Testing**: Develop test programs for your project, although they won't be submitted or graded. These tests will assist in verifying your work and evaluating your peers' work during the defense.

- **Submission**: Submit your work to your assigned git repository. Deepthought may grade your work after peer evaluations, and any errors during Deepthought’s grading will halt the evaluation.
