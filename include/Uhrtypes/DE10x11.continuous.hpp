#pragma once

#include "Uhrtype.hpp"

/*
 *           Layout Front
 *                COL
 *       1 X 9 8 7 6 5 4 3 2 1 0
 * ROW + - - - - - - - - - - - -
 *  0  | # E S K I S T R F Ü N F
 *  1  | Z E H N Z W A N Z I G #
 *  2  | # D R E I V I E R T E L
 *  3  | T G N A C H V O R U M #
 *  4  | # H A L B G Z W Ö L F J
 *  5  | Z W E I N S I E B E N #
 *  6  | # K D R E I R H F Ü N F
 *  7  | E L F N E U N V I E R #
 *  8  | # N A C H T Z E H N B X
 *  9  | U S E C H S F U H R Y #
 *     | # # + # + # + # + # # #
 * 
 * # - unused
 * + - minute LEDs
 */

class De10x11Continuous_t : public iUhrType {
public:
    virtual LanguageAbbreviation usedLang() override {
        return LanguageAbbreviation::DE;
    };

    //------------------------------------------------------------------------------

    virtual const bool hasDreiviertel() override { return true; }

    //------------------------------------------------------------------------------

    virtual const void getMinuteArray(uint16_t *returnArr,
                                      uint8_t col) override {
        const uint8_t realNrCols = 12;
        const uint8_t realNrRows = 11;
        // starting from bottom left corner, the first minute LED comes after 2 unused LEDs
        const uint8_t offset = 2;
        const uint16_t start = realNrCols * realNrRows - 1 - offset;

        for (uint8_t i = 0; i < 4; i++) {
            // i*2: skip every second LED
            returnArr[i] = start - (i * 2);
        }
    };

    //------------------------------------------------------------------------------

    virtual const uint16_t getFrontMatrixIndex(const uint8_t row, uint8_t col) {

        uint8_t newColsWordMatrix = colsWordMatrix();
        uint16_t numPixelsWordMatrix = rowsWordMatrix() * colsWordMatrix();

        if (G.buildTypeDef == BuildTypeDef::DoubleResM1) {
            newColsWordMatrix = 2 * colsWordMatrix() - 1;
            numPixelsWordMatrix = rowsWordMatrix() * newColsWordMatrix;
            col *= 2;
        }
        if (row % 2 != 0) {
            
            col = newColsWordMatrix - col - 1;
        }
        uint16_t returnValue = col + (row * newColsWordMatrix);

        // we got a dead LED every 11 LEDs
        returnValue += returnValue / 11;

        if (returnValue > numPixelsWordMatrix) {
            Serial.println(
                "[ERROR] getFrontMatrixIndex() returnValue out of Bounds");
        }

        return returnValue;
    };

    //------------------------------------------------------------------------------

    void show(FrontWord word) override {
        switch (word) {

        case FrontWord::es_ist:
            setFrontMatrixWord(0, 9, 10);
            setFrontMatrixWord(0, 5, 7);
            break;

        case FrontWord::nach:
        case FrontWord::v_nach:
            setFrontMatrixWord(3, 5, 8);
            break;

        case FrontWord::vor:
        case FrontWord::v_vor:
            setFrontMatrixWord(3, 2, 4);
            break;

        case FrontWord::viertel:
            setFrontMatrixWord(2, 0, 6);
            break;

        case FrontWord::dreiviertel:
            setFrontMatrixWord(2, 0, 10);
            break;

        case FrontWord::min_5:
            setFrontMatrixWord(0, 0, 3);
            break;

        case FrontWord::min_10:
            setFrontMatrixWord(1, 7, 10);
            break;

        case FrontWord::min_20:
            setFrontMatrixWord(1, 0, 6);
            break;

        case FrontWord::halb:
            setFrontMatrixWord(4, 7, 10);
            break;

        case FrontWord::eins:
            setFrontMatrixWord(5, 5, 8);
            break;

        case FrontWord::uhr:
            setFrontMatrixWord(9, 1, 3);
            break;

        case FrontWord::hour_1:
            setFrontMatrixWord(5, 6, 8);
            break;

        case FrontWord::hour_2:
            setFrontMatrixWord(5, 7, 10);
            break;

        case FrontWord::hour_3:
            setFrontMatrixWord(6, 6, 9);
            break;

        case FrontWord::hour_4:
            setFrontMatrixWord(7, 0, 3);
            break;

        case FrontWord::hour_5:
            setFrontMatrixWord(6, 0, 3);
            break;

        case FrontWord::hour_6:
            setFrontMatrixWord(9, 5, 9);
            break;

        case FrontWord::hour_7:
            setFrontMatrixWord(5, 0, 5);
            break;

        case FrontWord::hour_8:
            setFrontMatrixWord(8, 6, 9);
            break;

        case FrontWord::hour_9:
            setFrontMatrixWord(7, 4, 7);
            break;

        case FrontWord::hour_10:
            setFrontMatrixWord(8, 2, 5);
            break;

        case FrontWord::hour_11:
            setFrontMatrixWord(7, 8, 10);
            break;

        case FrontWord::hour_12:
            setFrontMatrixWord(4, 1, 5);
            break;

        default:
            break;
        };
    };
};

De10x11Continuous_t _de10x11Continuous;