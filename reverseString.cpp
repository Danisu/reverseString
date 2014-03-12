#include <iostream>
#include <malloc/malloc.h>
using namespace std;

//Macro to swap the value
//^= is a Bitwise XOR
//Check the bottom of the code for complete information about SWP
#define SWP(x,y) {x^=y; y^=x; x^=y;}

//Reverse string declaration
void reverseStg(char *);

int main(int argc, char ** argv){
    char aString[] = "ABCDEFGH";    //Character string
    char *c = aString;    //pointer to the character string
    reverseStg(c);     //Function call to reverse the string
    cout << aString << endl;     //Print the final result
    return 0;
}


void reverseStg(char * c){
    size_t s = std::strlen(c);
    unsigned int length = (unsigned int)s;
    length--; //c pointer begins at 0; therefore end of string is length - 1
    for (int i = 0; i <= length/2 + 1; i++) {
        SWP(c[i], c[length]);
        length--;
    }
}


//SWP MACRO explanation
/*
 **Alphabet A in binary is 01000001 <- x
 **Alphabet H in binary is 01001000 <- y
 ** x^=y is x = x ^ y and the result is 00001001
 ** Then
 ** y^=x is y = y ^ x and the result is 01000001, which is alphabet A
 ** Then
 ** x^=y is x = x ^ y and the result is 01001000, which is alphabet B
 **
 **
 ** Reference table for exclusive OR (^)
 **Truth table:
 ** A   B   A^B
 ** -----------
 ** 1   1   0
 ** 1   0   1
 ** 0   1   1
 ** 0   0   0
 */
