#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly.
    Example call:
    char buffer[1024];
    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int j = 0;

    while(*y){
        *(x + j) = *(y++);
        j++;
    }


}

/*
    Searches the input string `str` for the first instance of the
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.
    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while(*str != '\0') {
        if(*str == c){
            break;
        }
        str++;
    }
    if(*str == '\0') return NULL;
    return str;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`.
    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int i = 0;
    int j = 0;
    int h = 0;
    char *haystackHead;
    haystackHead = haystack;
    while(*haystack != *needle){
        if(*haystack == *needle){
            while(*(haystack + i) == *(needle + j)) {
                printf("%c", *(haystack + i));
                i++;
                j++;
            }
            i = 0;
            j = 0;
        }
        *haystack++;
    }
    while(*(haystackHead + h) != '\0') {
        if(*(haystackHead + h) == *needle) break;
        //printf("%c\n", *(haystackHead + h));
        h++;
    }
    h++;
    //printf("%c\n", *(haystackHead + h ));
    if(*(haystackHead + h) == '\0') return NULL;
    return haystack;
}

#ifndef TESTING
int main(void)
{
    printf("Hello World");
    char *hello = "Hello";
    char *world = "world";
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif