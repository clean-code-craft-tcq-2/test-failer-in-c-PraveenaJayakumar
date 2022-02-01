#include <stdio.h>
#include <assert.h>
#include "Color_Pair_Basic_Info.h"

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

unsigned int colorCode_order = 0;

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair color_Pair;
    color_Pair.majorColor = MajorColorNames[(pairNumber / numberOfMinorColors)];
    color_Pair.minorColor = MinorColorNames[(pairNumber % numberOfMinorColors)];
    return color_Pair;
}


void testNumberToPair(int pairNumber,
    const char* expectedMajor,
    const char* expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);      
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", colorCode_order , majorColor[i], minorColor[j]);
            testNumberToPair(colorCode_order,  majorColor[i], minorColor[j]);
            colorCode_order++;
        }
    }
   
    
}

int main() {
    printColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
