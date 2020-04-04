#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream in;
    in.open("test.txt");
    if (!in) {
        cout << "Error" << endl;
        exit(1);
    }
 
    char data[1024] = "";
    char buffer[1024] = "";
 
    char *first;
    char *second;
 
    while (!in.eof()) {
        in.getline(data, sizeof(in));
 
        first = strchr(data, '"');
 
        while (first != NULL)
        {
            second = strchr(first + 1, '"');
            if (second != NULL) {
                int size = strlen(data);
                int firstIndex = size - strlen(first);
                int secondIndex = size - strlen(second);
                int length = secondIndex - firstIndex + 1;
 
                strncpy(buffer, data + firstIndex, length);
                buffer[length] = '\0';
 
                cout << buffer << endl;
 
                first = strchr(second + 1, '"');
            }
            else break;
        }
 
    }
 
    in.close();
 
    return 0;
}

