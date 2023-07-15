#pragma once

#include "Uhrtype.hpp"

/*
 *           Layout Front
 *                COL
 *       X 9 8 7 6 5 4 3 2 1 0
 * ROW + - - - - - - - - - - -
 *  0  | H E T L I S H N U W S
 *  1  | T W I N T I G T I E N
 *  2  | V I J F B Y K W A R T
 *  3  | V O O R P M O V E R U
 *  4  | H A L F I T W E E N N
 *  5  | A C H T D R I E Z E S
 *  6  | Z E V E N E G E N T O
 *  7  | T W A A L F A T I E N
 *  8  | V I E R V I J F E L F
 *  9  | U U R A G E W E E S T
 */

class NL10x11_t : public iUhrType {
public:
    virtual LanguageAbbreviation usedLang() override {
        return LanguageAbbreviation::NL;
    };

    //------------------------------------------------------------------------------

    virtual const bool hasMinuteInWords() { return true; }

    //------------------------------------------------------------------------------

    void show(FrontWord word) override {
        switch (word) {

        case FrontWord::es_ist:
            setFrontMatrixWord(0, 8, 10);
            setFrontMatrixWord(0, 5, 6);
            break;

        case FrontWord::nach:
        case FrontWord::v_nach:
            setFrontMatrixWord(3, 1, 4);
            break;

        case FrontWord::vor:
        case FrontWord::v_vor:
            setFrontMatrixWord(3, 7, 10);
            break;

        case FrontWord::viertel:
            setFrontMatrixWord(2, 0, 4);
            break;

        case FrontWord::m_fuenf:
            setFrontMatrixWord(2, 7, 10);
            break;

        case FrontWord::m_zehn:
            setFrontMatrixWord(1, 0, 3);
            break;

        case FrontWord::m_zwanzig:
            setFrontMatrixWord(1, 4, 10);
            break;

        case FrontWord::halb:
            setFrontMatrixWord(4, 7, 10);
            break;

        case FrontWord::h_ein:
            setFrontMatrixWord(4, 1, 3);
            break;

        case FrontWord::uhr:
            setFrontMatrixWord(9, 8, 10);
            break;

        case FrontWord::h_zwei:
            setFrontMatrixWord(4, 2, 5);
            break;

        case FrontWord::h_drei:
            setFrontMatrixWord(5, 3, 6);
            break;

        case FrontWord::h_vier:
            setFrontMatrixWord(8, 7, 10);
            break;

        case FrontWord::h_fuenf:
            setFrontMatrixWord(8, 3, 6);
            break;

        case FrontWord::h_sechs:
            setFrontMatrixWord(5, 0, 2);
            break;

        case FrontWord::h_sieben:
            setFrontMatrixWord(6, 6, 10);
            break;

        case FrontWord::h_acht:
            setFrontMatrixWord(5, 7, 10);
            break;

        case FrontWord::h_neun:
            setFrontMatrixWord(6, 2, 6);
            break;

        case FrontWord::h_zehn:
            setFrontMatrixWord(7, 0, 3);
            break;

        case FrontWord::h_elf:
            setFrontMatrixWord(8, 0, 2);
            break;

        case FrontWord::h_zwoelf:
            setFrontMatrixWord(7, 5, 10);
            break;

        case FrontWord::nur:
            // Nu
            setFrontMatrixWord(0, 2, 3);
            break;

        case FrontWord::gewesen:
            // Geweest
            setFrontMatrixWord(9, 0, 6);
            break;

        default:
            break;
        };
    };
};

NL10x11_t _nl10x11;