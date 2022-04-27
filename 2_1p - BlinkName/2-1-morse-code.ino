#include <unordered_map>
#include <string>
#include <cctype>

int led = D7;

// Durations are in milliseconds. Timings source: http://students.cs.ucl.ac.uk/schoolslab/projects/PY2/introduction.html
const int DOT_DURATION = 100;
const int DASH_DURATION = DOT_DURATION * 3;
const int PAUSE_DURATION = DOT_DURATION;
const int LETTER_PAUSE_DURATION = DOT_DURATION * 3;
const int WORD_PAUSE_DURATION = DOT_DURATION * 7;

std::unordered_map<char, std::string> characterToMorseCodeMappings;

void setup() {
    pinMode(led, OUTPUT);
    
    // Stores the morse code for every letter and number into a hashmap 
    characterToMorseCodeMappings['a'] = ".-";
    characterToMorseCodeMappings['b'] = "-...";
    characterToMorseCodeMappings['c'] = "-.-.";
    characterToMorseCodeMappings['d'] = "-..";
    characterToMorseCodeMappings['e'] = ".";
    characterToMorseCodeMappings['f'] = "..-.";
    characterToMorseCodeMappings['g'] = "--.";
    characterToMorseCodeMappings['h'] = "....";
    characterToMorseCodeMappings['i'] = "..";
    characterToMorseCodeMappings['j'] = ".---";
    characterToMorseCodeMappings['k'] = "-.-";
    characterToMorseCodeMappings['l'] = ".-..";
    characterToMorseCodeMappings['m'] = "--";
    characterToMorseCodeMappings['n'] = "-.";
    characterToMorseCodeMappings['o'] = "---";
    characterToMorseCodeMappings['p'] = ".--.";
    characterToMorseCodeMappings['q'] = "--.-";
    characterToMorseCodeMappings['r'] = ".-.";
    characterToMorseCodeMappings['s'] = "...";
    characterToMorseCodeMappings['t'] = "-";
    characterToMorseCodeMappings['u'] = "..-";
    characterToMorseCodeMappings['v'] = "...-";
    characterToMorseCodeMappings['w'] = ".--";
    characterToMorseCodeMappings['x'] = "-..-";
    characterToMorseCodeMappings['y'] = "-.--";
    characterToMorseCodeMappings['z'] = "--..";
    characterToMorseCodeMappings['1'] = ".----";
    characterToMorseCodeMappings['2'] = "..---";
    characterToMorseCodeMappings['3'] = "...--";
    characterToMorseCodeMappings['4'] = "....-";
    characterToMorseCodeMappings['5'] = ".....";
    characterToMorseCodeMappings['6'] = "-....";
    characterToMorseCodeMappings['7'] = "--...";
    characterToMorseCodeMappings['8'] = "---..";
    characterToMorseCodeMappings['9'] = "----.";
    characterToMorseCodeMappings['0'] = "-----";
}

void flashDot() {
    digitalWrite(led, HIGH);
    delay(DOT_DURATION);
    digitalWrite(led, LOW);
    delay(PAUSE_DURATION);
}

void flashDash() {
    digitalWrite(led, HIGH);
    delay(DASH_DURATION);
    digitalWrite(led, LOW);
    delay(PAUSE_DURATION);
}

void flashCharacter(char character) {
    character = std::tolower(character);
    // Get the morse code sequence for the character
    std::string flashSequence = characterToMorseCodeMappings[character];
    
    // Flash the morse code sequence on the Argon's LED
    for (int i = 0; i < flashSequence.length(); i++) {
        if (flashSequence[i] == '.') {
            flashDot();
        }
        else if (flashSequence[i] == '-') {
            flashDash();
        }
    }
    
    // Pause for some time before flashing the next character
    delay(LETTER_PAUSE_DURATION - PAUSE_DURATION);
}

void flashWord(std::string word) {
    // Flashes the morse code sequence for every character in the word
    for (int i = 0; i < word.length(); i++) {
        flashCharacter(word[i]);
    }
    
    // Pause for some time before flashing the next word
    delay(WORD_PAUSE_DURATION - LETTER_PAUSE_DURATION);
}

void loop() {
    flashWord("mel");
}