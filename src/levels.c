#include "levels.h"

char level_answers[num_of_levels][10][10] = {
{ //level 0 (tutorial)
    "          ",
    "   ART R  ",
    "    O  O  ",
    "  RAT  A  ",
    "       S  ",
    " O S SAT  ",
    " A T O    ",
    " T A R    ",
    "   R T    ",
    "          "
}, { //level 1
    "          ",
    "      NO  ",
    "          ",
    "    O     ",
    "  OWN     ",
    "   O      ",
    "   NOW    ",
    "          ",
    "          ",
    "          "
}, { //level 2
    "          ",
    "          ",
    "    E     ",
    "    A     ",
    "   ERA    ",
    "     R    ",
    "     E    ",
    "          ",
    "          ",
    "          "
}, { //level 3
    "          ",
    "          ",
    "          ",
    "    A     ",
    "    TAP   ",
    "      A   ",
    "    APT   ",
    "          ",
    "          ",
    "          "
}, { // level 4
    "          ",
    "   A      ",
    "   I      ",
    " FAR      ",
    " A    F   ",
    " I    I   ",
    " R    R   ",
    "          ",
    "          ",
    "          "
}, { //level 5
    "          ",
    "          ",
    "  P       ",
    "  A       ",
    "  RAP     ",
    "    ARK   ",
    "    R     ",
    "    K     ",
    "          ",
    "          "
}, { //level 6
    "          ",
    "   CAR    ",
    "     ACT  ",
    "   CAT    ",
    "          ",
    "  C   A   ",
    "  A   T   ",
    "  R       ",
    "  TAR     ",
    "          "
}, { //level 7
    "          ",
    "    DENT  ",
    "      E   ",
    "  T   T   ",
    "  END     ",
    "  N E     ",
    "    N     ",
    "          ",
    "  TEND    ",
    "          "
}, { //level 8
    "          ",
    "   BAT    ",
    "   E A  A ",
    "   A BE T ",
    " BET    E ",
    "      T   ",
    "   BATE E ",
    "      A A ",
    " BETA   T ",
    "          "
}, { //level 9
    "          ",
    "   BARN   ",
    "   A      ",
    "   RAN    ",
    " B   A    ",
    " R   BAN  ",
    " A        ",
    " N    BRA ",
    "          ",
    "          "
}, { //level 10
    "          ",
    "          ",
    " SIGH     ",
    " I  I     ",
    " THIS  H  ",
    "   T   I  ",
    "   SIGHT  ",
    "          ",
    "          ",
    "          "
}, { // level 11
    "          ",
    "   CONE   ",
    "   L O    ",
    "   O   O  ",
    " LONE  N  ",
    "   E   C  ",
    "     ONE  ",
    " CON      ",
    "          ",
    "          "
}, { //level 12
    "          ",
    " DOC  COD ",
    "   O  O   ",
    " C U  L   ",
    " L LOUD   ",
    " O D      ",
    " U        ",
    " DUO      ",
    "          ",
    "          "
}, { //level 13
    "          ",
    " BAND  L  ",
    " L A   A  ",
    " A BAN N  ",
    " N     D  ",
    " D   B    ",
    "   L A  B ",
    "   A L  A ",
    "   B D  D ",
    "          "
}, { //level 14
    "          ",
    "   HEAL   ",
    " SEA L    ",
    " E SHE S  ",
    " A     A  ",
    " LEASH L  ",
    "   S   E  ",
    "   H      ",
    "          ",
    "          "
}, { //level 15
    "          ",
    " H  THINK ",
    " I  H   I ",
    " T TIN  N ",
    "    N     ",
    " I     H  ",
    " N     I  ",
    " KIT   N  ",
    "       T  ",
    "          "
}, { //level 16
    "          ",
    " LAW      ",
    "   A      ",
    "  CRAWL   ",
    "  A       ",
    " ARC   R  ",
    "   L   A  ",
    "   A   W  ",
    "   W      ",
    "          "
}, { //level 17
    "          ",
    "          ",
    "     WAS  ",
    " SAW   W  ",
    " W ARM A  ",
    " A R A R  ",
    " M M RAM  ",
    "          ",
    "          ",
    "          "
}, { //level 18
    "          ",
    " LED      ",
    "   U      ",
    " D GLUE   ",
    " U  U     ",
    " E  GLUED ",
    "        U ",
    "        E ",
    "        L ",
    "          "
}, { //level 19
    "          ",
    " I SATIN  ",
    " T T A    ",
    "  SAINT   ",
    "   I  I A ",
    " SIN  N N ",
    "  T   SIT ",
    "  S    N  ",
    "   AN     ",
    "          "
}, { //level 20
    "          ",
    "    P     ",
    "  DYE     ",
    "  E TYPED ",
    "  P     U ",
    " DUTY YEP ",
    "  T U E E ",
    "  Y PUT   ",
    "          ",
    "          "
}, { //level 21
    "          ",
    "    M     ",
    "    O  M  ",
    "    SCOUT ",
    " COST  S  ",
    " U   COTS ",
    " T    U U ",
    "   CUSTOM ",
    "          ",
    "          "
}, { //level 22
    "          ",
    " U  PLEA  ",
    " P  A     ",
    "    LEAP  ",
    "   P Q    ",
    " PLAQUE   ",
    " E L A    ",
    " APE L    ",
    "          ",
    "          "
}, { //level 23
    "          ",
    "          ",
    "   E      ",
    "  EXOTIC  ",
    "   I O I  ",
    " COT X T  ",
    "     ICE  ",
    "     C    ",
    "          ",
    "          "
}, { //level 24 (final)
    "          ",
    "    FIVE  ",
    "  F I E   ",
    " RIFE R R ",
    "  R R IVY ",
    " VERY F E ",
    "      Y   ",
    "          ",
    "          ",
    "          "
}};

char solved_answers[10][10] = {
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          "
};

char level_letters[num_of_levels][7] = {"OSART", "ONW", "RAE", "TPA", "AFIR",
                                        "PRKA", "CATR", "DNTE", "BATE", "RNAB",
                                        "GHIST", "LNCOE", "CDLUO", "ALDNB", "HLSAE",
                                        "HNKIT", "ACLRW", "AMRSW", "GDLEU", "AINST",
                                        "PDUEYT", "UCSMOT", "QAPUEL", "CITOEX",
                                        "YIEVRF"};