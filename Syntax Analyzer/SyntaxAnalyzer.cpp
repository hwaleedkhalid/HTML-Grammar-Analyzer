#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

char *Look_Ahead = NULL;

// Function Prototypes
void S();
void StartingTag();
void CloseTag();
void ExternalCSS();
void InlineCSS();
void Property();
void Value();
void Attribute();
void Content();
void StartingWithAttribute();
void DocType();
void S1();
void S2();
void S3();
void S4();
void E1();
void E2();
void E3();
void E4();
void comb();
void comb1();
void comb2();
void I1();
void I2();
void I3();
void I4();
void P1();
void P2();
void Val1();
void Val2();
void Atr1();
void Atr2();
void Atr3();
void Atr4();
void Atr5();
void Cnt1();
void Cnt2();
void ST1();
void ST2();
void DOC1();
void Var1();
void Var2();
void Var3();
void Match(char OP);
bool isSL(char c);
bool isCL(char c);
bool isDigit(char c);
bool isAN(char c);
bool isHex(char c);
bool isSp_Char(char c);

int main() {
    char Input[100], Choice = 'Y';
    bool Check = false;

    do {
        // Ask for input and ensure it's not empty
        do {
            cout << "\n\nEnter The Input: ";
            cin.getline(Input, 100);

            if (Input[0] == '\0') {  // If input is empty
                cout << "\n\nSyntax Error!!!\nUnexpected Empty Input. Please enter a valid input.\n";
            }
        } while (Input[0] == '\0');  // Keep asking until valid input is given

        Look_Ahead = Input;

        try {
            S();  // Parse the input
            cout << "\n\tInput Is Valid." << endl;
        } catch (const std::string& msg) { 
            cout << msg << endl;  // Print specific error message
        } catch (...) {
            cout << "\n\nAn Unknown Error Occurred!" << endl;
        }

        cout << "\n\nDo You Want To Verify Another Input? (Y/N): ";
        cin >> Choice;

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Check = true;

    } while (Choice == 'y' || Choice == 'Y');

    return 0;
}




void Match(char OP) {
    
    
    if (*Look_Ahead == OP)
    {
        Look_Ahead++;
    }
    else if (*Look_Ahead == '\0')
    {
        throw "\n\nSyntax Error!!!\nUnexpected End Of Input. Expected '" + string(1, OP) + "'.";
    } else {
        throw "\n\nSyntax Error!!!\nExpected '" + string(1, OP) + "' But Found '" + string(1, *Look_Ahead) + "'";
    }
}


void S()
{
    if (*Look_Ahead == '<')
    {
        if (*(Look_Ahead + 1) == '/')
        {
            CloseTag();
        }
        else if (*(Look_Ahead + 1) == '!')
        {
            DocType();
        }
        else
        {
            StartingTag();
        }
    }
    else if (isSL(*Look_Ahead))
    {
        while(islower(*Look_Ahead))
        {
            Match(*Look_Ahead);
        }
        if (*(Look_Ahead) == '=' && (*(Look_Ahead +1) == '"'))
        {
            if(isupper(*Look_Ahead+2))
            {
                InlineCSS();
            }
            else if(islower(*Look_Ahead+2))
            {
                Attribute();
            }
            else if(*(Look_Ahead+2) == '.'  || (*(Look_Ahead+2) == '#'))
            {
                ExternalCSS();
            }
        }
        else
        {
            cout << "Syntax Error\n!!!!Unexpected Input" << endl;
        }
    }
    else if (*Look_Ahead == '#')
    {
        Value();
    }
    else if (isupper(*Look_Ahead))
    {
        if(islower(*(Look_Ahead + 1)))
        {
            Value();
        }
        else if(isupper(*(Look_Ahead + 1)))
        {
            Property();
        }
        
    }
    else
    {
        throw "\n\nSyntax Error!!!\nUnexpected Character '" + string(1, *Look_Ahead) + "' Found.";
    }
}


void StartingTag()
{
    Match('<');
    S1();
    if(isspace(*Look_Ahead))
    {
        Match(' ');
        ST1();
    }
    else
    {
        Match('>');
        cout << "\nValid Starting Tag without attributes"; // Display the tag
        if(isalpha(*Look_Ahead) && isalpha(*(Look_Ahead+1)))
        {
            Content();
        }
    }
}

void CloseTag()
{
    Match('<');
    Match('/');
    S1();
    Match('>');
    cout << "\nValid Closing Tag"; // Display the tag
}

void ExternalCSS()
{
    //Match(*Look_Ahead);
    E2();
    cout << "\nValid ExternalCSS Tag"; // Display the tag
}

void InlineCSS()
{
    I2();
    cout << "\nValid InlineCSS Tag"; // Display the tag
}

void Property()
{
    if(isupper(*Look_Ahead) && isupper(*(Look_Ahead+1)))
    {
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        P1();
        cout << "\nValid Property Tag"; // Display the tag
    }
    
}

void Value() {
    if (isCL(*Look_Ahead))
    {
        Match(*Look_Ahead);
        if(islower(*Look_Ahead) && islower(*(Look_Ahead+1)))
        {
            Match(*Look_Ahead);
            Match(*Look_Ahead);
            Val1();
        }
    }
    else if
    (*Look_Ahead == '#')
    {
        Match('#');
        Val2();  // Now handles hexadecimal color codes
    }
    else
    {
        throw "\n\nSyntax Error!!!\nExpected CL or '#' But Found '" + string(1, *Look_Ahead) + "'.";
    }
    cout << "\nValid Value Tag"; // Display the tag
    
}




void Attribute()
{
    //Match(*Look_Ahead);
    cout<<"a";
    Atr1();
    cout << "\nValid Attribute Tag";
}

void Content()
{
    //StartingTag();
    Cnt1();
    CloseTag();
    cout << "\nValid Contant Tag";
}

void StartingWithAttribute()
{
    Match('<');
    S1();
    ST1();
    cout << "\nValid Starting Tag with Attributes";
}

void DocType()
{
    Match('<');
    Match('!');
    DOC1();
    Match('>');
}

void S1()
{
    // If the first character after '<' is a lowercase letter (start of a tag name)
    if (isSL(*Look_Ahead)) {
        // Consume the first character of the tag name
        Match(*Look_Ahead);
        if(islower(*Look_Ahead))
        {
            Match(*Look_Ahead);
            // After the first letter of the tag name, continue consuming alphanumeric characters
            while (islower(*Look_Ahead))
            {
                Match(*Look_Ahead);
            }
        }
        else if(isDigit(*Look_Ahead))
        {
            Match(*Look_Ahead);
        }
        else
        ;
      
    }
    else
    {
        throw "\n\nSyntax Error!!!\nExpected tag name (SL) But Found '" + string(1, *Look_Ahead) + "'.";
    }
}


void S2() {
    Match(' ');
    S4();
}

void S3() {
    Match(' ');
    Match(*Look_Ahead);
}

void S4() {
    if (isSL(*Look_Ahead)) {
        S2();
    }
}

void E2() {
    Match('=');
    Match('"');
    E3();
}

void E3() {
    if (*Look_Ahead == '#')
    {
        Match('#');
        E4();
        Match('"');
    }
    else if (*Look_Ahead == '.')
    {
        Match('.');
        E4();
        Match('"');
    }
    else
    {
        throw "\n\nSyntax Error!!!\nExpected '#' or '.' But Found '" + string(1, *Look_Ahead) + "'.";
    }
}

void E4() {
    comb();
    comb1();
    
}

void comb() {
    if (isSL(*Look_Ahead) || isCL(*Look_Ahead)) {
        Match(*Look_Ahead);
        comb2();
    }
}

void comb1() {
    if (*Look_Ahead == '_' || isDigit(*Look_Ahead)) {
        Match(*Look_Ahead);
        comb();
    }
}

void comb2() {
    if(islower(*Look_Ahead) || isupper(*Look_Ahead))
    {
        comb();
    }
}


void I2() {
    Match('=');
    Match('"');
    I3();
    Match('"');
}


void I3() {
    Property();
    Match(':');
    Value();
    I4();
}

void I4() {
    if (*Look_Ahead == ';') {
        Match(';');
        I3();
    }
}
void P1()
{
    if (isupper(*Look_Ahead) && isupper(*(Look_Ahead+1)) && isupper(*(Look_Ahead+2)))
    {
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        P2();
    }
    else if(*Look_Ahead == '-' && (isupper(*(Look_Ahead+1)) && isupper(*(Look_Ahead+2)) && isupper(*(Look_Ahead+3)) ))
    {
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        P2();
    }
    else if(!(*Look_Ahead))
    {
        throw "\n\nSyntax Error!!!\nExpected 'CL' But Found '" + string(1, *Look_Ahead) + " for property tag'.";
    }
    else
    {
        throw "\n\nSyntax Error!!!\nExpected 'CL' But Found '" + string(1, *Look_Ahead) + " for property tag'.";
    }
    
}

void P2()
{
    if (isCL(*Look_Ahead)) {
        Match(*Look_Ahead);
        P2();
    }
}

void Val1()
{
    if (isSL(*Look_Ahead)) {
        Match(*Look_Ahead);
        Val1();
    }
}

void Val2() {
    int count = 0;
    while (count < 6) {
        if (!isHex(*Look_Ahead)) {
            throw "\n\nSyntax Error!!!\nExpected a hexadecimal character But Found '" + string(1, *Look_Ahead) + "'.";
        }
        Match(*Look_Ahead);
        count++;
    }

    // Check if there are extra characters
    if (isHex(*Look_Ahead)) {
        throw "\n\nSyntax Error!!!\nExpected exactly six hexadecimal characters after '#' But Found Extra Character '" + string(1, *Look_Ahead) + "'.";
    }
}



void Atr1() {
    if (isSL(*Look_Ahead))
    {
        Match(*Look_Ahead);
        Atr1();
    }
    else if(*Look_Ahead == '=')
    {
        Match('=');
        Match('"');
        Atr2();
        Match('"');
        cout << "\nValid Attribute tag";
    }
    else
    {
        throw "\n\nSyntax Error!!!\nExpected SL or = but found '" + string(1, *Look_Ahead) + "'.";
    }
}

void Atr2() {
    if(isSL(*Look_Ahead))
    {
        Match(*Look_Ahead);
        Atr3();
    }
    else
    {
        throw "\n\nSyntax Error!!!\nUnExpected letter ";
    }
    
    
}

void Atr3() {
    if (*Look_Ahead == '.' || *Look_Ahead == '-' || *Look_Ahead == ':' || *Look_Ahead == '\\')
    {
        Match(*Look_Ahead);
        Atr4();
    }
    else if(isSL(*Look_Ahead))
    {
        Match(*(Look_Ahead));
        Atr3();
    }
    else
    {
        throw "\n\nSyntax Error!!!\nUnExpected letter ";
    }
}

void Atr4(){
    if(islower(*(Look_Ahead)) && islower(*(Look_Ahead+1)) && islower(*(Look_Ahead+2)))
    {
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        Match(*Look_Ahead);
        Atr5();
    }
    else
    {
        throw "\n\nSyntax Error!!!\nExpected atleast 3 small letter ";
    }
}

void Atr5() {
    if (isSL(*Look_Ahead)) {
        Match(*Look_Ahead);
        Atr3();
    }
    else if(*Look_Ahead == '.' || *Look_Ahead == '-' || *Look_Ahead == ':' || *Look_Ahead == '\\')
    {
        Atr3();
    }
}

void Cnt1() {
    // Ensure the first two characters are letters (SL or CL)
    if (isSL(*Look_Ahead) || isCL(*Look_Ahead)) {
        Match(*Look_Ahead); // Match first letter
        if (isSL(*Look_Ahead) || isCL(*Look_Ahead)) {
            Match(*Look_Ahead); // Match second letter
            Cnt2(); // Continue parsing the rest of Cnt1
        } else {
            throw "\n\nSyntax Error!!!\nExpected second letter But Found '" + string(1, *Look_Ahead) + "'.";
        }
    } else {
        throw "\n\nSyntax Error!!!\nExpected first letter But Found '" + string(1, *Look_Ahead) + "'.";
    }
}


void Cnt2() {
   
    // Now continue matching the content after the two initial letters
    if (isSL(*Look_Ahead) || isCL(*Look_Ahead) || isDigit(*Look_Ahead) || isSp_Char(*Look_Ahead)) {
        Match(*Look_Ahead); // Continue matching valid content
        Cnt2(); // Continue recursively
    }
}




void ST1()
{
    Attribute();
    ST2();
    Match('>');
    cout << "\nValid Starting Tag with Attributes";
}

void ST2()
{
    if (*Look_Ahead == ' ') {
        Match(' ');
        Attribute();
        ST2();
    }
}

void DOC1() {
    Var1();  // Match 'D'
    Var2();  // Match 'O'
    Var3();  // Match 'C'
    
    // Ensure no space after 'DOC'
    if (isspace(*Look_Ahead)) {
        throw "\n\nSyntax Error!!!\nUnexpected Space After 'DOC'.";
    }
}


void Var1()
{
    if (*Look_Ahead == 'D') {
        Match(*Look_Ahead);
    } else {
        throw "\n\nSyntax Error!!!\nExpected 'D' But Found '" + string(1, *Look_Ahead) + "'.";
    }
}

void Var2() {
    if (*Look_Ahead == 'O') {
        Match(*Look_Ahead);
    } else {
        throw "\n\nSyntax Error!!!\nExpected 'O' But Found '" + string(1, *Look_Ahead) + "'.";
    }
}

void Var3()
{
    if (*Look_Ahead == 'C') {
        Match(*Look_Ahead);
    } else {
        throw "\n\nSyntax Error!!!\nExpected 'C' But Found '" + string(1, *Look_Ahead) + "'.";
    }
}

bool isSL(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool isCL(char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isAN(char c) {
    return isSL(c) || isDigit(c);
}

bool isHex(char c) {
    return (isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}


bool isSp_Char(char c) {
    return !(isSL(c) || isCL(c) || isDigit(c) || c == '<');
}
