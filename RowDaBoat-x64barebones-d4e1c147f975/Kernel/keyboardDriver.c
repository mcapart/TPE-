#include <keyboardDriver.h>
#include <video_driver.h>


#define KEYS 59
#define PRESSED 1
#define RELEASED 2
#define ERRROR -1

#define L_SHFT 0x2A
#define R_SHFT 0x36
#define B_SPACE 0x0E
#define SPACE 0x39
#define CAPS_LCK 0x3A
#define ENTER 0x1C

#define IS_LETTER(c) (c >= 'a' && c <= 'z' ? 1 : 0)

#define ABS(num) (num >= 0 ? num : num * -1)

static uint8_t action(uint8_t scanCode);

static const char* pressCodes[KEYS][2] =
    {{0, 0}, {0, 0}, {"1", "!"}, {"2", "@"}, {"3", "#"}, {"4", "$"},
    {"5", "%"}, {"6", "^"}, {"7", "&"}, {"8", "*"}, {"9", "("},
    {"0", ")"}, {"-", "_"}, {"=", "+"}, {0, 0}, {0, 0}, {"q", "Q"}, 
    {"w", "W"}, {"e", "E"}, {"r", "R"}, {"t", "T"}, {"y", "Y"}, 
    {"u", "U"}, {"i", "I"}, {"o", "O"}, {"p", "P"}, {"[", "{"}, 
    {"]", "}"}, {0, 0}, {0, 0}, {"a", "A"}, {"s", "S"}, 
    {"d", "D"}, {"f", "F"}, {"g", "G"}, {"h", "H"}, {"j", "J"},
    {"k", "K"}, {"l", "L"}, {";", ":"}, {"\"", "\""}, {"`", "~"},
    {0, 0}, {"\\", "|"}, {"z", "Z"}, {"x", "X"}, {"c", "C"}, 
    {"v", "V"}, {"b", "B"}, {"n", "N"}, {"m", "M"}, {",", "<"}, 
    {".", ">"}, {"/", "?"}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

static uint8_t scanCode, currentAction, specialChars[] = {0, 0}, capsLock = 0;

int color[3] = {255, 255, 255};

void keyboard_handler(){
    if (hasKey())
    {
        scanCode = getKey();
        currentAction = action(scanCode);
        if (currentAction == PRESSED)
        {
            switch (scanCode)
            {
            case L_SHFT:
                specialChars[0] = 1;
                break;

            case R_SHFT:
                specialChars[1] = 1;
                break;

            case ENTER:
                //ncNewline();
                newLine();
                break;

            case CAPS_LCK:
                capsLock = capsLock == 1 ? 0 : 1;
                break;

            case SPACE:
               // ncPrintChar(" ");

                writeWord(" ", 1.5, color);
                break;

            case B_SPACE:
               // deletechar();
               deleteChar();
                break;

            default:
                if (pressCodes[scanCode][0])
                {
                    if (!IS_LETTER(pressCodes[scanCode][0]))
                       // ncPrintChar(pressCodes[scanCode][specialChars[0] | specialChars[1]]);
           
                       writeWord(pressCodes[scanCode][specialChars[0] | specialChars[1]],1.5, color );
                    else
                    {
                        //ncPrintChar(pressCodes[scanCode][ABS(capsLock - (specialChars[0] | specialChars[1]))]);
                        writeWord(pressCodes[scanCode][ABS(capsLock - (specialChars[0] | specialChars[1]))], 1.5 , color);
                    }
                }
            }
            
        }
        else if (currentAction == RELEASED)
            {
                switch (scanCode)
                {
                case L_SHFT | 0x80:
                    specialChars[0] = 0;
                    break;

                case R_SHFT | 0x80:
                    specialChars[1] = 0;
                    break;
                }
            }
        
    }
}

void poolingKeyboard()
{
    uint8_t scanCode, currentAction, specialChars[] = {0, 0}, capsLock=0;
    while (1)
    {
        if (hasKey())
        {
            scanCode = getKey();
            currentAction = action(scanCode);
            if (currentAction == PRESSED)
            {
                switch (scanCode)
                {
                case L_SHFT:
                    specialChars[0] = 1;
                    break;

                case R_SHFT:
                    specialChars[1] = 1;
                    break;
                case CAPS_LCK:
                    capsLock = capsLock == 1 ? 0 : 1;
                    break;
                case SPACE:
                    ncPrintChar(" ");
                    break;
                default:
                    if(pressCodes[scanCode][0]){
                        if (!IS_LETTER(pressCodes[scanCode][0]))
                            ncPrintChar(pressCodes[scanCode][specialChars[0]|specialChars[1]]);
                        else{
                            ncPrintChar(pressCodes[scanCode][ABS(capsLock - (specialChars[0] | specialChars[1]))]);
                        }
                    }
                }
            }
            else if (currentAction == RELEASED)
            {
                switch (scanCode)
                {
                case L_SHFT | 0x80:
                    specialChars[0] = 0;
                    break;

                case R_SHFT | 0x80:
                    specialChars[1] = 0;
                    break;
                }
            }
        }
    }
}

static uint8_t action(uint8_t scanCode)
{
    if (scanCode >= 0x01 && scanCode <= 0x3A)
        return PRESSED;
    else if (scanCode >= 0x81 && scanCode <= 0xBA)
        return RELEASED;

    return ERRROR;
}
