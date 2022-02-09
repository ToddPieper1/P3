#include <iostream>
using namespace std;

int main()
{
    //Data field, we don't need to initialize them to empty/0, but it makes me more comfortable doing so
    string URL, scheme, authority, path = "";
    int beginning, end = 0;

    //Ask the user for input
    cout << "Enter your URL: ";
    cin >> URL;

    //Since the scheme is always a part of the input, and it ends at the colon, we take the substring of the URl from start
    //to the index position of the only colon + 1 because ".substr" works in that its lower limit is where it starts,
    //and it's upper limit "n" simply counts that many indexes after, and since indexes start at 0, taking the index of
    //the colon and adding 1 will count us the correct amount of characters for the substring
    scheme = URL.substr(0, URL.find(":")+1);

    //beginning is the index for the start of the authority marked always by a double backslash
    beginning = URL.find("//");

    //We can then use beginning as the starting position for the end since we need to find the first single backslash
    // after we locate the initial double backslash. We use beginning + 2 since the index for beginning is at the star of the
    // double backslash and we want to begin the search after it
    end = URL.find("/", beginning+2 );

    //Make sure to take the difference between end and beginning, I already explained how the ".substr" works
    authority = URL.substr(beginning, end-beginning);

    //Everything from the end onwards is the path, by default "n" for substr is the rest of the string.
    path = URL.substr(end);

    cout <<"Scheme: " << scheme << "\nAuthority: " << authority << "\nPath: " << path << "\n";
}
