#include <stdio.h>
#include <assert.h>

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

const int MAX_COLORPAIR_NAME_CHARS = 16;

typedef struct {
    const char* majorColor;
    const char* minorColor;
} ColorPair;

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair color_Pair;
    color_Pair.majorColor = MajorColorNames[(pairNumber / numberOfMinorColors)];
    color_Pair.minorColor = MinorColorNames[(pairNumber % numberOfMinorColors)];
    return colorPair;
}


int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void testNumberToPair(int pairNumber,
    const char* expectedMajor,
    const char* expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);      
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            testNumberToPair(i * 5 + j,  majorColor[i], minorColor[i]);
        }
    }
    return i * j;
    
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
