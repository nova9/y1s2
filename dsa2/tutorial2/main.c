#include <stdio.h>

char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};

char **cp[] = {c + 3, c + 2, c + 1, c};

char ***cpp = cp;

int main()
{
    printf("%s\n", **(++cpp));
    printf("%s\n", *(*(cpp+=2))+3);
    printf("%s\n", *cpp[-3]+3);
    printf("%s\n", *cpp[-1]+1);
}
