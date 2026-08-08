 #include <iostream>
#include <cstring> // Include for strlen
using namespace std;

int main() {
    int a[6] = {11, 22, 33, 44, 55, 66};
    int *ptr = a;
    ptr++; // Moves to the second element (22)
    
    cout << "Your outputs for integer array are:" << endl;
    cout << *ptr << endl;           // 22: Value at current pointer
    cout << *ptr++ << endl;         // 22: Value at current pointer, then increment pointer (points to 33)
    cout << *++ptr << endl;         // 44: Pointer increments first (points to 44), then dereferences
    cout << (*ptr)++ << endl;       // 44: Value at current pointer (44), then increments the value (becomes 45)
    cout << ++*ptr << endl;         // 46: Increments the value at the current pointer (45 -> 46)
    cout << *(ptr - 3) << endl;     // 11: Moves 3 positions back (points to 11), then dereferences
    cout << *ptr - 2 << endl;       // 44: Current value (46) - 2 = 44
    cout << a[3] << endl;           // 44: Direct access to the 4th element of the array
    cout << ptr[1] << endl;         // 55: Pointer arithmetic: *(ptr + 1) = 55
    cout << *ptr << endl;           // 46: Current value at pointer

    // Character Array
    char text[] = "This is an easy exam...";
    char *ptr1, *ptr2;
    int len = strlen(text); // Length of string
    ptr1 = text;            // Points to the beginning of the string
    ptr2 = text + len - 1;  // Points to the last character

    cout << "\nYour outputs for character array are:" << endl;
    cout << ptr1 << endl;             // "This is an easy exam...": Prints the string starting at ptr1
    cout << ptr2 << endl;             // '.': Points to the last character ('.')
    cout << (char)++*ptr1 << endl;    // 'U': Increments the first character ('T' -> 'U'), then prints it
    cout << ptr1 << endl;             // "Uhis is an easy exam...": Prints string starting at updated ptr1
    cout << ptr1 + 8 << endl;         // "s an easy exam...": Pointer arithmetic (ptr1 + 8)
    cout << *text - 1 << endl;        // 84 - 1 = 83: ASCII value of 'U' (84) minus 1
    ptr1 += 5;                        // Moves ptr1 to the 6th character ('i')
    ptr2 -= 6;                        // Moves ptr2 back 6 characters
    cout << ptr1 << endl;             // "is an easy exam...": String starting at updated ptr1
    cout << ptr2 << endl;             // "asy exam...": String starting at updated ptr2
    cout << ptr1[2] << endl;          // ' ': The 3rd character from ptr1 ('is an ...')
    cout << *(ptr2 + 1) << endl;      // 's': The next character after ptr2 ('s' from "asy...")

    return 0;
}

