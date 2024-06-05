/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** keycode
*/

#ifndef KEYCODE_H_
    #define KEYCODE_H_
    #include "SFML/Graphics.h"

static const sfKeyCode all_key_codes[] = {
    sfKeyUnknown, sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG,
    sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO, sfKeyP,
    sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY,
    sfKeyZ, sfKeyNum0, sfKeyNum1, sfKeyNum2, sfKeyNum3, sfKeyNum4, sfKeyNum5,
    sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9, sfKeyEscape, sfKeyLControl,
    sfKeyLShift, sfKeyLAlt, sfKeyLSystem, sfKeyRControl, sfKeyRShift,
    sfKeyRAlt, sfKeyRSystem, sfKeyMenu, sfKeyLBracket, sfKeyRBracket,
    sfKeySemiColon, sfKeyComma, sfKeyPeriod, sfKeyQuote, sfKeySlash,
    sfKeyBackSlash, sfKeyTilde, sfKeyEqual, sfKeyDash, sfKeySpace,
    sfKeyReturn, sfKeyBack, sfKeyTab, sfKeyPageUp, sfKeyPageDown,
    sfKeyEnd, sfKeyHome, sfKeyInsert, sfKeyDelete, sfKeyAdd, sfKeySubtract,
    sfKeyMultiply, sfKeyDivide, sfKeyLeft, sfKeyRight, sfKeyUp, sfKeyDown,
    sfKeyNumpad0, sfKeyNumpad1, sfKeyNumpad2, sfKeyNumpad3, sfKeyNumpad4,
    sfKeyNumpad5, sfKeyNumpad6, sfKeyNumpad7, sfKeyNumpad8, sfKeyNumpad9,
    sfKeyF1, sfKeyF2, sfKeyF3, sfKeyF4, sfKeyF5, sfKeyF6, sfKeyF7, sfKeyF8,
    sfKeyF9, sfKeyF10, sfKeyF11, sfKeyF12, sfKeyF13, sfKeyF14, sfKeyF15,
    sfKeyPause,
};

static const char *key_letters[] = {
    "\0", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "esc", "ctl", "sft",
    "alt", "win", "ctl", "sft", "alt", "win", "mnu", "{", "}", ";", ",",
    ".", "\"", "/", "\\", "~", "=", "_", "spc", "ret", "bck", "tab",
    "pgu", "pgd", "end", "hom", "ins", "del", "add", "sub", "mul", "div",
    "<-", "->", "^", "dwn", "0", "1", "2", "3", "4", "5", "6", "7", "8",
    "9", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10",
    "F11", "F12", "F13", "F14", "F15", "pse",
};
    #define NUM_KEY_CODES (sizeof(all_key_codes) / sizeof(sfKeyCode))
    #define NUM_KEY_CHAR (sizeof(key_letters) / sizeof(key_letters[0]))
#endif /* !KEYCODE_H_ */
