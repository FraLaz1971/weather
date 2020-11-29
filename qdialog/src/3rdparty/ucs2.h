/****************************************************************************
** $Id: ucs2.h,v 1.2 2007/03/19 13:34:56 sukiyazov_sa Exp $
**
** Definition of const char * to QString (and backward) convertion helper
** functions and macros
**
** Created : 950419
**
** Copyright (C) 206-2007 Sergey A. Sukiyazov.  All rights reserved.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact sukiyazov@mail.ru if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/
#ifndef __UCS2_H__
#define __UCS2_H__

namespace Ucs2 {
    enum Char {
        /* . */                decimalpoint = 0x002e,     /* FULL STOP */
        /* < */                   leftcaret = 0x003c,     /* LESS-THAN SIGN */
        /* > */                  rightcaret = 0x003e,     /* GREATER-THAN SIGN */
        /* _ */                    underbar = 0x005f,     /* LOW LINE */
        /* ¯ */                     overbar = 0x00af,     /* MACRON */

        /*   */                      space  = 0x0020,     /* SPACE  */
        /* ! */                      exclam = 0x0021,     /* EXCLAM */
        /* " */                    quotedbl = 0x0022,     /* QUOTEDBL */
        /* # */                  numbersign = 0x0023,     /* NUMBERSIGN */
        /* $ */                      dollar = 0x0024,     /* DOLLAR */
        /* % */                     percent = 0x0025,     /* PERCENT */
        /* & */                   ampersand = 0x0026,     /* AMPERSAND */
        /* ' */                  apostrophe = 0x0027,     /* APOSTROPHE */
        /* ( */                   parenleft = 0x0028,     /* PARENT LEFT */
        /* ) */                  parenright = 0x0029,     /* PARENT RIGHT */
        /* * */                    asterisk = 0x002a,     /* ASTERISK */
        /* + */                        plus = 0x002b,     /* PLUS */
        /* , */                       comma = 0x002c,     /* COMMA */
        /* - */                       minus = 0x002d,     /* MINUS */
        /* . */                      period = 0x002e,     /* PERIOD */
        /* / */                       slash = 0x002f,     /* SLASH */
        /* 0 */                     Digit_0 = 0x0030,     /* ASCII DIGGIT 0 */
        /* 1 */                     Digit_1 = 0x0031,     /* ASCII DIGGIT 1 */
        /* 2 */                     Digit_2 = 0x0032,     /* ASCII DIGGIT 2 */
        /* 3 */                     Digit_3 = 0x0033,     /* ASCII DIGGIT 3 */
        /* 4 */                     Digit_4 = 0x0034,     /* ASCII DIGGIT 4 */
        /* 5 */                     Digit_5 = 0x0035,     /* ASCII DIGGIT 5 */
        /* 6 */                     Digit_6 = 0x0036,     /* ASCII DIGGIT 6 */
        /* 7 */                     Digit_7 = 0x0037,     /* ASCII DIGGIT 7 */
        /* 8 */                     Digit_8 = 0x0038,     /* ASCII DIGGIT 8 */
        /* 9 */                     Digit_9 = 0x0039,     /* ASCII DIGGIT 9 */
        /* : */                       colon = 0x003a,     /* COLON */
        /* ; */                   semicolon = 0x003b,     /* SEMICOLON */
        /* < */                        less = 0x003c,     /* LESS */
        /* = */                       equal = 0x003d,     /* EQUAL */
        /* > */                     greater = 0x003e,     /* GREATER */
        /* ? */                    question = 0x003f,     /* QUESTION */
        /* @ */                          at = 0x0040,     /* AT */
        /* A */                           A = 0x0041,     /* ASCII CAPITAL LETTER A */
        /* B */                           B = 0x0042,     /* ASCII CAPITAL LETTER B */
        /* C */                           C = 0x0043,     /* ASCII CAPITAL LETTER C */
        /* D */                           D = 0x0044,     /* ASCII CAPITAL LETTER D */
        /* E */                           E = 0x0045,     /* ASCII CAPITAL LETTER E */
        /* F */                           F = 0x0046,     /* ASCII CAPITAL LETTER F */
        /* G */                           G = 0x0047,     /* ASCII CAPITAL LETTER G */
        /* H */                           H = 0x0048,     /* ASCII CAPITAL LETTER H */
        /* I */                           I = 0x0049,     /* ASCII CAPITAL LETTER I */
        /* J */                           J = 0x004a,     /* ASCII CAPITAL LETTER J */
        /* K */                           K = 0x004b,     /* ASCII CAPITAL LETTER K */
        /* L */                           L = 0x004c,     /* ASCII CAPITAL LETTER L */
        /* M */                           M = 0x004d,     /* ASCII CAPITAL LETTER M */
        /* N */                           N = 0x004e,     /* ASCII CAPITAL LETTER N */
        /* O */                           O = 0x004f,     /* ASCII CAPITAL LETTER O */
        /* P */                           P = 0x0050,     /* ASCII CAPITAL LETTER P */
        /* Q */                           Q = 0x0051,     /* ASCII CAPITAL LETTER Q */
        /* R */                           R = 0x0052,     /* ASCII CAPITAL LETTER R */
        /* S */                           S = 0x0053,     /* ASCII CAPITAL LETTER S */
        /* T */                           T = 0x0054,     /* ASCII CAPITAL LETTER T */
        /* U */                           U = 0x0055,     /* ASCII CAPITAL LETTER U */
        /* V */                           V = 0x0056,     /* ASCII CAPITAL LETTER V */
        /* W */                           W = 0x0057,     /* ASCII CAPITAL LETTER W */
        /* X */                           X = 0x0058,     /* ASCII CAPITAL LETTER X */
        /* Y */                           Y = 0x0059,     /* ASCII CAPITAL LETTER Y */
        /* Z */                           Z = 0x005a,     /* ASCII CAPITAL LETTER Z */
        /* [ */                 bracketleft = 0x005b,     /* BRACKET LEFT */
        /* \ */                   backslash = 0x005c,     /* BACK SLASH */
        /* ] */                bracketright = 0x005d,     /* BRACKET RIGHT */
        /* ^ */                Ascii_circum = 0x005e,     /* CIRCUM */
        /* _ */                  underscore = 0x005f,     /* UNDERSCORE */
        /* ` */                       grave = 0x0060,     /* GRAVE */
        /* a */                           a = 0x0061,     /* ASCII SMALL LETTER A */
        /* b */                           b = 0x0062,     /* ASCII SMALL LETTER B */
        /* c */                           c = 0x0063,     /* ASCII SMALL LETTER C */
        /* d */                           d = 0x0064,     /* ASCII SMALL LETTER D */
        /* e */                           e = 0x0065,     /* ASCII SMALL LETTER E */
        /* f */                           f = 0x0066,     /* ASCII SMALL LETTER F */
        /* g */                           g = 0x0067,     /* ASCII SMALL LETTER G */
        /* h */                           h = 0x0068,     /* ASCII SMALL LETTER H */
        /* i */                           i = 0x0069,     /* ASCII SMALL LETTER I */
        /* j */                           j = 0x006a,     /* ASCII SMALL LETTER J */
        /* k */                           k = 0x006b,     /* ASCII SMALL LETTER K */
        /* l */                           l = 0x006c,     /* ASCII SMALL LETTER L */
        /* m */                           m = 0x006d,     /* ASCII SMALL LETTER M */
        /* n */                           n = 0x006e,     /* ASCII SMALL LETTER N */
        /* o */                           o = 0x006f,     /* ASCII SMALL LETTER O */
        /* p */                           p = 0x0070,     /* ASCII SMALL LETTER P */
        /* q */                           q = 0x0071,     /* ASCII SMALL LETTER Q */
        /* r */                           r = 0x0072,     /* ASCII SMALL LETTER R */
        /* s */                           s = 0x0073,     /* ASCII SMALL LETTER S */
        /* t */                           t = 0x0074,     /* ASCII SMALL LETTER T */
        /* u */                           u = 0x0075,     /* ASCII SMALL LETTER U */
        /* v */                           v = 0x0076,     /* ASCII SMALL LETTER V */
        /* w */                           w = 0x0077,     /* ASCII SMALL LETTER W */
        /* x */                           x = 0x0078,     /* ASCII SMALL LETTER X */
        /* y */                           y = 0x0079,     /* ASCII SMALL LETTER Y */
        /* z */                           z = 0x007a,     /* ASCII SMALL LETTER Z */
        /* { */                   braceleft = 0x007b,     /* BRACE LEFT */
        /* | */                         bar = 0x007c,     /* BAR */
        /* } */                  braceright = 0x007d,     /* BRACE RIGHT */
        /* ~ */                 Ascii_tilde = 0x007e,     /* TILDE */
        /*  */                   endoffile = 0x007f,     /* ASCII LETTER  */

        /* Ā */                     Amacron = 0x0100,     /* LATIN CAPITAL LETTER A WITH MACRON */
        /* ā */                     amacron = 0x0101,     /* LATIN SMALL LETTER A WITH MACRON */
        /* Ă */                      Abreve = 0x0102,     /* LATIN CAPITAL LETTER A WITH BREVE */
        /* ă */                      abreve = 0x0103,     /* LATIN SMALL LETTER A WITH BREVE */
        /* Ą */                     Aogonek = 0x0104,     /* LATIN CAPITAL LETTER A WITH OGONEK */
        /* ą */                     aogonek = 0x0105,     /* LATIN SMALL LETTER A WITH OGONEK */
        /* Ć */                      Cacute = 0x0106,     /* LATIN CAPITAL LETTER C WITH ACUTE */
        /* ć */                      cacute = 0x0107,     /* LATIN SMALL LETTER C WITH ACUTE */
        /* Ĉ */                 Ccircumflex = 0x0108,     /* LATIN CAPITAL LETTER C WITH CIRCUMFLEX */
        /* ĉ */                 ccircumflex = 0x0109,     /* LATIN SMALL LETTER C WITH CIRCUMFLEX */
        /* Ċ */                   Cabovedot = 0x010a,     /* LATIN CAPITAL LETTER C WITH DOT ABOVE */
        /* ċ */                   cabovedot = 0x010b,     /* LATIN SMALL LETTER C WITH DOT ABOVE */
        /* Č */                      Ccaron = 0x010c,     /* LATIN CAPITAL LETTER C WITH CARON */
        /* č */                      ccaron = 0x010d,     /* LATIN SMALL LETTER C WITH CARON */
        /* Ď */                      Dcaron = 0x010e,     /* LATIN CAPITAL LETTER D WITH CARON */
        /* ď */                      dcaron = 0x010f,     /* LATIN SMALL LETTER D WITH CARON */
        /* Đ */                     Dstroke = 0x0110,     /* LATIN CAPITAL LETTER D WITH STROKE */
        /* đ */                     dstroke = 0x0111,     /* LATIN SMALL LETTER D WITH STROKE */
        /* Ē */                     Emacron = 0x0112,     /* LATIN CAPITAL LETTER E WITH MACRON */
        /* ē */                     emacron = 0x0113,     /* LATIN SMALL LETTER E WITH MACRON */
        /* Ė */                   Eabovedot = 0x0116,     /* LATIN CAPITAL LETTER E WITH DOT ABOVE */
        /* ė */                   eabovedot = 0x0117,     /* LATIN SMALL LETTER E WITH DOT ABOVE */
        /* Ę */                     Eogonek = 0x0118,     /* LATIN CAPITAL LETTER E WITH OGONEK */
        /* ę */                     eogonek = 0x0119,     /* LATIN SMALL LETTER E WITH OGONEK */
        /* Ě */                      Ecaron = 0x011a,     /* LATIN CAPITAL LETTER E WITH CARON */
        /* ě */                      ecaron = 0x011b,     /* LATIN SMALL LETTER E WITH CARON */
        /* Ĝ */                 Gcircumflex = 0x011c,     /* LATIN CAPITAL LETTER G WITH CIRCUMFLEX */
        /* ĝ */                 gcircumflex = 0x011d,     /* LATIN SMALL LETTER G WITH CIRCUMFLEX */
        /* Ğ */                      Gbreve = 0x011e,     /* LATIN CAPITAL LETTER G WITH BREVE */
        /* ğ */                      gbreve = 0x011f,     /* LATIN SMALL LETTER G WITH BREVE */
        /* Ġ */                   Gabovedot = 0x0120,     /* LATIN CAPITAL LETTER G WITH DOT ABOVE */
        /* ġ */                   gabovedot = 0x0121,     /* LATIN SMALL LETTER G WITH DOT ABOVE */
        /* Ģ */                    Gcedilla = 0x0122,     /* LATIN CAPITAL LETTER G WITH CEDILLA */
        /* ģ */                    gcedilla = 0x0123,     /* LATIN SMALL LETTER G WITH CEDILLA */
        /* Ĥ */                 Hcircumflex = 0x0124,     /* LATIN CAPITAL LETTER H WITH CIRCUMFLEX */
        /* ĥ */                 hcircumflex = 0x0125,     /* LATIN SMALL LETTER H WITH CIRCUMFLEX */
        /* Ħ */                     Hstroke = 0x0126,     /* LATIN CAPITAL LETTER H WITH STROKE */
        /* ħ */                     hstroke = 0x0127,     /* LATIN SMALL LETTER H WITH STROKE */
        /* Ĩ */                      Itilde = 0x0128,     /* LATIN CAPITAL LETTER I WITH TILDE */
        /* ĩ */                      itilde = 0x0129,     /* LATIN SMALL LETTER I WITH TILDE */
        /* Ī */                     Imacron = 0x012a,     /* LATIN CAPITAL LETTER I WITH MACRON */
        /* ī */                     imacron = 0x012b,     /* LATIN SMALL LETTER I WITH MACRON */
        /* Į */                     Iogonek = 0x012e,     /* LATIN CAPITAL LETTER I WITH OGONEK */
        /* į */                     iogonek = 0x012f,     /* LATIN SMALL LETTER I WITH OGONEK */
        /* İ */                   Iabovedot = 0x0130,     /* LATIN CAPITAL LETTER I WITH DOT ABOVE */
        /* ı */                    idotless = 0x0131,     /* LATIN SMALL LETTER DOTLESS I */
        /* Ĵ */                 Jcircumflex = 0x0134,     /* LATIN CAPITAL LETTER J WITH CIRCUMFLEX */
        /* ĵ */                 jcircumflex = 0x0135,     /* LATIN SMALL LETTER J WITH CIRCUMFLEX */
        /* Ķ */                    Kcedilla = 0x0136,     /* LATIN CAPITAL LETTER K WITH CEDILLA */
        /* ķ */                    kcedilla = 0x0137,     /* LATIN SMALL LETTER K WITH CEDILLA */
        /* ĸ */                         kra = 0x0138,     /* LATIN SMALL LETTER KRA */
        /* Ĺ */                      Lacute = 0x0139,     /* LATIN CAPITAL LETTER L WITH ACUTE */
        /* ĺ */                      lacute = 0x013a,     /* LATIN SMALL LETTER L WITH ACUTE */
        /* Ļ */                    Lcedilla = 0x013b,     /* LATIN CAPITAL LETTER L WITH CEDILLA */
        /* ļ */                    lcedilla = 0x013c,     /* LATIN SMALL LETTER L WITH CEDILLA */
        /* Ľ */                      Lcaron = 0x013d,     /* LATIN CAPITAL LETTER L WITH CARON */
        /* ľ */                      lcaron = 0x013e,     /* LATIN SMALL LETTER L WITH CARON */
        /* Ł */                     Lstroke = 0x0141,     /* LATIN CAPITAL LETTER L WITH STROKE */
        /* ł */                     lstroke = 0x0142,     /* LATIN SMALL LETTER L WITH STROKE */
        /* Ń */                      Nacute = 0x0143,     /* LATIN CAPITAL LETTER N WITH ACUTE */
        /* ń */                      nacute = 0x0144,     /* LATIN SMALL LETTER N WITH ACUTE */
        /* Ņ */                    Ncedilla = 0x0145,     /* LATIN CAPITAL LETTER N WITH CEDILLA */
        /* ņ */                    ncedilla = 0x0146,     /* LATIN SMALL LETTER N WITH CEDILLA */
        /* Ň */                      Ncaron = 0x0147,     /* LATIN CAPITAL LETTER N WITH CARON */
        /* ň */                      ncaron = 0x0148,     /* LATIN SMALL LETTER N WITH CARON */
        /* Ŋ */                         ENG = 0x014a,     /* LATIN CAPITAL LETTER ENG */
        /* ŋ */                         eng = 0x014b,     /* LATIN SMALL LETTER ENG */
        /* Ō */                     Omacron = 0x014c,     /* LATIN CAPITAL LETTER O WITH MACRON */
        /* ō */                     omacron = 0x014d,     /* LATIN SMALL LETTER O WITH MACRON */
        /* Ő */                Odoubleacute = 0x0150,     /* LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
        /* ő */                odoubleacute = 0x0151,     /* LATIN SMALL LETTER O WITH DOUBLE ACUTE */
        /* Œ */                          OE = 0x0152,     /* LATIN CAPITAL LIGATURE OE */
        /* œ */                          oe = 0x0153,     /* LATIN SMALL LIGATURE OE */
        /* Ŕ */                      Racute = 0x0154,     /* LATIN CAPITAL LETTER R WITH ACUTE */
        /* ŕ */                      racute = 0x0155,     /* LATIN SMALL LETTER R WITH ACUTE */
        /* Ŗ */                    Rcedilla = 0x0156,     /* LATIN CAPITAL LETTER R WITH CEDILLA */
        /* ŗ */                    rcedilla = 0x0157,     /* LATIN SMALL LETTER R WITH CEDILLA */
        /* Ř */                      Rcaron = 0x0158,     /* LATIN CAPITAL LETTER R WITH CARON */
        /* ř */                      rcaron = 0x0159,     /* LATIN SMALL LETTER R WITH CARON */
        /* Ś */                      Sacute = 0x015a,     /* LATIN CAPITAL LETTER S WITH ACUTE */
        /* ś */                      sacute = 0x015b,     /* LATIN SMALL LETTER S WITH ACUTE */
        /* Ŝ */                 Scircumflex = 0x015c,     /* LATIN CAPITAL LETTER S WITH CIRCUMFLEX */
        /* ŝ */                 scircumflex = 0x015d,     /* LATIN SMALL LETTER S WITH CIRCUMFLEX */
        /* Ş */                    Scedilla = 0x015e,     /* LATIN CAPITAL LETTER S WITH CEDILLA */
        /* ş */                    scedilla = 0x015f,     /* LATIN SMALL LETTER S WITH CEDILLA */
        /* Š */                      Scaron = 0x0160,     /* LATIN CAPITAL LETTER S WITH CARON */
        /* š */                      scaron = 0x0161,     /* LATIN SMALL LETTER S WITH CARON */
        /* Ţ */                    Tcedilla = 0x0162,     /* LATIN CAPITAL LETTER T WITH CEDILLA */
        /* ţ */                    tcedilla = 0x0163,     /* LATIN SMALL LETTER T WITH CEDILLA */
        /* Ť */                      Tcaron = 0x0164,     /* LATIN CAPITAL LETTER T WITH CARON */
        /* ť */                      tcaron = 0x0165,     /* LATIN SMALL LETTER T WITH CARON */
        /* Ŧ */                      Tslash = 0x0166,     /* LATIN CAPITAL LETTER T WITH STROKE */
        /* ŧ */                      tslash = 0x0167,     /* LATIN SMALL LETTER T WITH STROKE */
        /* Ũ */                      Utilde = 0x0168,     /* LATIN CAPITAL LETTER U WITH TILDE */
        /* ũ */                      utilde = 0x0169,     /* LATIN SMALL LETTER U WITH TILDE */
        /* Ū */                     Umacron = 0x016a,     /* LATIN CAPITAL LETTER U WITH MACRON */
        /* ū */                     umacron = 0x016b,     /* LATIN SMALL LETTER U WITH MACRON */
        /* Ŭ */                      Ubreve = 0x016c,     /* LATIN CAPITAL LETTER U WITH BREVE */
        /* ŭ */                      ubreve = 0x016d,     /* LATIN SMALL LETTER U WITH BREVE */
        /* Ů */                       Uring = 0x016e,     /* LATIN CAPITAL LETTER U WITH RING ABOVE */
        /* ů */                       uring = 0x016f,     /* LATIN SMALL LETTER U WITH RING ABOVE */
        /* Ű */                Udoubleacute = 0x0170,     /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
        /* ű */                udoubleacute = 0x0171,     /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
        /* Ų */                     Uogonek = 0x0172,     /* LATIN CAPITAL LETTER U WITH OGONEK */
        /* ų */                     uogonek = 0x0173,     /* LATIN SMALL LETTER U WITH OGONEK */
        /* Ÿ */                  Ydiaeresis = 0x0178,     /* LATIN CAPITAL LETTER Y WITH DIAERESIS */
        /* Ź */                      Zacute = 0x0179,     /* LATIN CAPITAL LETTER Z WITH ACUTE */
        /* ź */                      zacute = 0x017a,     /* LATIN SMALL LETTER Z WITH ACUTE */
        /* Ż */                   Zabovedot = 0x017b,     /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
        /* ż */                   zabovedot = 0x017c,     /* LATIN SMALL LETTER Z WITH DOT ABOVE */
        /* Ž */                      Zcaron = 0x017d,     /* LATIN CAPITAL LETTER Z WITH CARON */
        /* ž */                      zcaron = 0x017e,     /* LATIN SMALL LETTER Z WITH CARON */
        /* ƒ */                    function = 0x0192,     /* LATIN SMALL LETTER F WITH HOOK */
        /* ˇ */                       caron = 0x02c7,     /* CARON */
        /* ˘ */                       breve = 0x02d8,     /* BREVE */
        /* ˙ */                    abovedot = 0x02d9,     /* DOT ABOVE */
        /* ˛ */                      ogonek = 0x02db,     /* OGONEK */
        /* ˝ */                 doubleacute = 0x02dd,     /* DOUBLE ACUTE ACCENT */

        /* ΅ */        Greek_accentdieresis = 0x0385,  /* GREEK DIALYTIKA TONOS */
        /* Ά */           Greek_ALPHAaccent = 0x0386,  /* GREEK CAPITAL LETTER ALPHA WITH TONOS */
        /* Έ */         Greek_EPSILONaccent = 0x0388,  /* GREEK CAPITAL LETTER EPSILON WITH TONOS */
        /* Ή */             Greek_ETAaccent = 0x0389,  /* GREEK CAPITAL LETTER ETA WITH TONOS */
        /* Ί */            Greek_IOTAaccent = 0x038a,  /* GREEK CAPITAL LETTER IOTA WITH TONOS */
        /* Ό */         Greek_OMICRONaccent = 0x038c,  /* GREEK CAPITAL LETTER OMICRON WITH TONOS */
        /* Ύ */         Greek_UPSILONaccent = 0x038e,  /* GREEK CAPITAL LETTER UPSILON WITH TONOS */
        /* Ώ */           Greek_OMEGAaccent = 0x038f,  /* GREEK CAPITAL LETTER OMEGA WITH TONOS */
        /* ΐ */    Greek_iotaaccentdieresis = 0x0390,  /* GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS */
        /* Α */                 Greek_ALPHA = 0x0391,  /* GREEK CAPITAL LETTER ALPHA */
        /* Β */                  Greek_BETA = 0x0392,  /* GREEK CAPITAL LETTER BETA */
        /* Γ */                 Greek_GAMMA = 0x0393,  /* GREEK CAPITAL LETTER GAMMA */
        /* Δ */                 Greek_DELTA = 0x0394,  /* GREEK CAPITAL LETTER DELTA */
        /* Ε */               Greek_EPSILON = 0x0395,  /* GREEK CAPITAL LETTER EPSILON */
        /* Ζ */                  Greek_ZETA = 0x0396,  /* GREEK CAPITAL LETTER ZETA */
        /* Η */                   Greek_ETA = 0x0397,  /* GREEK CAPITAL LETTER ETA */
        /* Θ */                 Greek_THETA = 0x0398,  /* GREEK CAPITAL LETTER THETA */
        /* Ι */                  Greek_IOTA = 0x0399,  /* GREEK CAPITAL LETTER IOTA */
        /* Κ */                 Greek_KAPPA = 0x039a,  /* GREEK CAPITAL LETTER KAPPA */
        /* Λ */                Greek_LAMBDA = 0x039b,  /* GREEK CAPITAL LETTER LAMDA */
        /* Μ */                    Greek_MU = 0x039c,  /* GREEK CAPITAL LETTER MU */
        /* Ν */                    Greek_NU = 0x039d,  /* GREEK CAPITAL LETTER NU */
        /* Ξ */                    Greek_XI = 0x039e,  /* GREEK CAPITAL LETTER XI */
        /* Ο */               Greek_OMICRON = 0x039f,  /* GREEK CAPITAL LETTER OMICRON */
        /* Π */                    Greek_PI = 0x03a0,  /* GREEK CAPITAL LETTER PI */
        /* Ρ */                   Greek_RHO = 0x03a1,  /* GREEK CAPITAL LETTER RHO */
        /* Σ */                 Greek_SIGMA = 0x03a3,  /* GREEK CAPITAL LETTER SIGMA */
        /* Τ */                   Greek_TAU = 0x03a4,  /* GREEK CAPITAL LETTER TAU */
        /* Υ */               Greek_UPSILON = 0x03a5,  /* GREEK CAPITAL LETTER UPSILON */
        /* Φ */                   Greek_PHI = 0x03a6,  /* GREEK CAPITAL LETTER PHI */
        /* Χ */                   Greek_CHI = 0x03a7,  /* GREEK CAPITAL LETTER CHI */
        /* Ψ */                   Greek_PSI = 0x03a8,  /* GREEK CAPITAL LETTER PSI */
        /* Ω */                 Greek_OMEGA = 0x03a9,  /* GREEK CAPITAL LETTER OMEGA */
        /* Ϊ */          Greek_IOTAdieresis = 0x03aa,  /* GREEK CAPITAL LETTER IOTA WITH DIALYTIKA */
        /* Ϋ */       Greek_UPSILONdieresis = 0x03ab,  /* GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA */
        /* ά */           Greek_alphaaccent = 0x03ac,  /* GREEK SMALL LETTER ALPHA WITH TONOS */
        /* έ */         Greek_epsilonaccent = 0x03ad,  /* GREEK SMALL LETTER EPSILON WITH TONOS */
        /* ή */             Greek_etaaccent = 0x03ae,  /* GREEK SMALL LETTER ETA WITH TONOS */
        /* ί */            Greek_iotaaccent = 0x03af,  /* GREEK SMALL LETTER IOTA WITH TONOS */
        /* ΰ */ Greek_upsilonaccentdieresis = 0x03b0,  /* GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS */
        /* α */                 Greek_alpha = 0x03b1,  /* GREEK SMALL LETTER ALPHA */
        /* β */                  Greek_beta = 0x03b2,  /* GREEK SMALL LETTER BETA */
        /* γ */                 Greek_gamma = 0x03b3,  /* GREEK SMALL LETTER GAMMA */
        /* δ */                 Greek_delta = 0x03b4,  /* GREEK SMALL LETTER DELTA */
        /* ε */               Greek_epsilon = 0x03b5,  /* GREEK SMALL LETTER EPSILON */
        /* ζ */                  Greek_zeta = 0x03b6,  /* GREEK SMALL LETTER ZETA */
        /* η */                   Greek_eta = 0x03b7,  /* GREEK SMALL LETTER ETA */
        /* θ */                 Greek_theta = 0x03b8,  /* GREEK SMALL LETTER THETA */
        /* ι */                  Greek_iota = 0x03b9,  /* GREEK SMALL LETTER IOTA */
        /* κ */                 Greek_kappa = 0x03ba,  /* GREEK SMALL LETTER KAPPA */
        /* λ */                Greek_lambda = 0x03bb,  /* GREEK SMALL LETTER LAMDA */
        /* μ */                    Greek_mu = 0x03bc,  /* GREEK SMALL LETTER MU */
        /* ν */                    Greek_nu = 0x03bd,  /* GREEK SMALL LETTER NU */
        /* ξ */                    Greek_xi = 0x03be,  /* GREEK SMALL LETTER XI */
        /* ο */               Greek_omicron = 0x03bf,  /* GREEK SMALL LETTER OMICRON */
        /* π */                    Greek_pi = 0x03c0,  /* GREEK SMALL LETTER PI */
        /* ρ */                   Greek_rho = 0x03c1,  /* GREEK SMALL LETTER RHO */
        /* ς */       Greek_finalsmallsigma = 0x03c2,  /* GREEK SMALL LETTER FINAL SIGMA */
        /* σ */                 Greek_sigma = 0x03c3,  /* GREEK SMALL LETTER SIGMA */
        /* τ */                   Greek_tau = 0x03c4,  /* GREEK SMALL LETTER TAU */
        /* υ */               Greek_upsilon = 0x03c5,  /* GREEK SMALL LETTER UPSILON */
        /* φ */                   Greek_phi = 0x03c6,  /* GREEK SMALL LETTER PHI */
        /* χ */                   Greek_chi = 0x03c7,  /* GREEK SMALL LETTER CHI */
        /* ψ */                   Greek_psi = 0x03c8,  /* GREEK SMALL LETTER PSI */
        /* ω */                 Greek_omega = 0x03c9,  /* GREEK SMALL LETTER OMEGA */
        /* ϊ */          Greek_iotadieresis = 0x03ca,  /* GREEK SMALL LETTER IOTA WITH DIALYTIKA */
        /* ϋ */       Greek_upsilondieresis = 0x03cb,  /* GREEK SMALL LETTER UPSILON WITH DIALYTIKA */
        /* ό */         Greek_omicronaccent = 0x03cc,  /* GREEK SMALL LETTER OMICRON WITH TONOS */
        /* ύ */         Greek_upsilonaccent = 0x03cd,  /* GREEK SMALL LETTER UPSILON WITH TONOS */
        /* ώ */           Greek_omegaaccent = 0x03ce,  /* GREEK SMALL LETTER OMEGA WITH TONOS */

        /* Ё */                 Cyrillic_IO = 0x0401,     /* CYRILLIC CAPITAL LETTER IO */
        /* Ђ */                 Serbian_DJE = 0x0402,     /* CYRILLIC CAPITAL LETTER DJE */
        /* Ѓ */               Macedonia_GJE = 0x0403,     /* CYRILLIC CAPITAL LETTER GJE */
        /* Є */                Ukrainian_IE = 0x0404,     /* CYRILLIC CAPITAL LETTER UKRAINIAN IE */
        /* Ѕ */               Macedonia_DSE = 0x0405,     /* CYRILLIC CAPITAL LETTER DZE */
        /* І */                 Ukrainian_I = 0x0406,     /* CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I */
        /* Ї */                Ukrainian_YI = 0x0407,     /* CYRILLIC CAPITAL LETTER YI */
        /* Ј */                 Cyrillic_JE = 0x0408,     /* CYRILLIC CAPITAL LETTER JE */
        /* Љ */                Cyrillic_LJE = 0x0409,     /* CYRILLIC CAPITAL LETTER LJE */
        /* Њ */                Cyrillic_NJE = 0x040a,     /* CYRILLIC CAPITAL LETTER NJE */
        /* Ћ */                Serbian_TSHE = 0x040b,     /* CYRILLIC CAPITAL LETTER TSHE */
        /* Ќ */               Macedonia_KJE = 0x040c,     /* CYRILLIC CAPITAL LETTER KJE */
        /* Ў */         Byelorussian_SHORTU = 0x040e,     /* CYRILLIC CAPITAL LETTER SHORT U */
        /* Џ */               Cyrillic_DZHE = 0x040f,     /* CYRILLIC CAPITAL LETTER DZHE */
        /* А */                  Cyrillic_A = 0x0410,     /* CYRILLIC CAPITAL LETTER A */
        /* Б */                 Cyrillic_BE = 0x0411,     /* CYRILLIC CAPITAL LETTER BE */
        /* В */                 Cyrillic_VE = 0x0412,     /* CYRILLIC CAPITAL LETTER VE */
        /* Г */                Cyrillic_GHE = 0x0413,     /* CYRILLIC CAPITAL LETTER GHE */
        /* Д */                 Cyrillic_DE = 0x0414,     /* CYRILLIC CAPITAL LETTER DE */
        /* Е */                 Cyrillic_IE = 0x0415,     /* CYRILLIC CAPITAL LETTER IE */
        /* Ж */                Cyrillic_ZHE = 0x0416,     /* CYRILLIC CAPITAL LETTER ZHE */
        /* З */                 Cyrillic_ZE = 0x0417,     /* CYRILLIC CAPITAL LETTER ZE */
        /* И */                  Cyrillic_I = 0x0418,     /* CYRILLIC CAPITAL LETTER I */
        /* Й */             Cyrillic_SHORTI = 0x0419,     /* CYRILLIC CAPITAL LETTER SHORT I */
        /* К */                 Cyrillic_KA = 0x041a,     /* CYRILLIC CAPITAL LETTER KA */
        /* Л */                 Cyrillic_EL = 0x041b,     /* CYRILLIC CAPITAL LETTER EL */
        /* М */                 Cyrillic_EM = 0x041c,     /* CYRILLIC CAPITAL LETTER EM */
        /* Н */                 Cyrillic_EN = 0x041d,     /* CYRILLIC CAPITAL LETTER EN */
        /* О */                  Cyrillic_O = 0x041e,     /* CYRILLIC CAPITAL LETTER O */
        /* П */                 Cyrillic_PE = 0x041f,     /* CYRILLIC CAPITAL LETTER PE */
        /* Р */                 Cyrillic_ER = 0x0420,     /* CYRILLIC CAPITAL LETTER ER */
        /* С */                 Cyrillic_ES = 0x0421,     /* CYRILLIC CAPITAL LETTER ES */
        /* Т */                 Cyrillic_TE = 0x0422,     /* CYRILLIC CAPITAL LETTER TE */
        /* У */                  Cyrillic_U = 0x0423,     /* CYRILLIC CAPITAL LETTER U */
        /* Ф */                 Cyrillic_EF = 0x0424,     /* CYRILLIC CAPITAL LETTER EF */
        /* Х */                 Cyrillic_HA = 0x0425,     /* CYRILLIC CAPITAL LETTER HA */
        /* Ц */                Cyrillic_TSE = 0x0426,     /* CYRILLIC CAPITAL LETTER TSE */
        /* Ч */                Cyrillic_CHE = 0x0427,     /* CYRILLIC CAPITAL LETTER CHE */
        /* Ш */                Cyrillic_SHA = 0x0428,     /* CYRILLIC CAPITAL LETTER SHA */
        /* Щ */              Cyrillic_SHCHA = 0x0429,     /* CYRILLIC CAPITAL LETTER SHCHA */
        /* Ъ */           Cyrillic_HARDSIGN = 0x042a,     /* CYRILLIC CAPITAL LETTER HARD SIGN */
        /* Ы */               Cyrillic_YERU = 0x042b,     /* CYRILLIC CAPITAL LETTER YERU */
        /* Ь */           Cyrillic_SOFTSIGN = 0x042c,     /* CYRILLIC CAPITAL LETTER SOFT SIGN */
        /* Э */                  Cyrillic_E = 0x042d,     /* CYRILLIC CAPITAL LETTER E */
        /* Ю */                 Cyrillic_YU = 0x042e,     /* CYRILLIC CAPITAL LETTER YU */
        /* Я */                 Cyrillic_YA = 0x042f,     /* CYRILLIC CAPITAL LETTER YA */
        /* а */                  Cyrillic_a = 0x0430,     /* CYRILLIC SMALL LETTER A */
        /* б */                 Cyrillic_be = 0x0431,     /* CYRILLIC SMALL LETTER BE */
        /* в */                 Cyrillic_ve = 0x0432,     /* CYRILLIC SMALL LETTER VE */
        /* г */                Cyrillic_ghe = 0x0433,     /* CYRILLIC SMALL LETTER GHE */
        /* д */                 Cyrillic_de = 0x0434,     /* CYRILLIC SMALL LETTER DE */
        /* е */                 Cyrillic_ie = 0x0435,     /* CYRILLIC SMALL LETTER IE */
        /* ж */                Cyrillic_zhe = 0x0436,     /* CYRILLIC SMALL LETTER ZHE */
        /* з */                 Cyrillic_ze = 0x0437,     /* CYRILLIC SMALL LETTER ZE */
        /* и */                  Cyrillic_i = 0x0438,     /* CYRILLIC SMALL LETTER I */
        /* й */             Cyrillic_shorti = 0x0439,     /* CYRILLIC SMALL LETTER SHORT I */
        /* к */                 Cyrillic_ka = 0x043a,     /* CYRILLIC SMALL LETTER KA */
        /* л */                 Cyrillic_el = 0x043b,     /* CYRILLIC SMALL LETTER EL */
        /* м */                 Cyrillic_em = 0x043c,     /* CYRILLIC SMALL LETTER EM */
        /* н */                 Cyrillic_en = 0x043d,     /* CYRILLIC SMALL LETTER EN */
        /* о */                  Cyrillic_o = 0x043e,     /* CYRILLIC SMALL LETTER O */
        /* п */                 Cyrillic_pe = 0x043f,     /* CYRILLIC SMALL LETTER PE */
        /* р */                 Cyrillic_er = 0x0440,     /* CYRILLIC SMALL LETTER ER */
        /* с */                 Cyrillic_es = 0x0441,     /* CYRILLIC SMALL LETTER ES */
        /* т */                 Cyrillic_te = 0x0442,     /* CYRILLIC SMALL LETTER TE */
        /* у */                  Cyrillic_u = 0x0443,     /* CYRILLIC SMALL LETTER U */
        /* ф */                 Cyrillic_ef = 0x0444,     /* CYRILLIC SMALL LETTER EF */
        /* х */                 Cyrillic_ha = 0x0445,     /* CYRILLIC SMALL LETTER HA */
        /* ц */                Cyrillic_tse = 0x0446,     /* CYRILLIC SMALL LETTER TSE */
        /* ч */                Cyrillic_che = 0x0447,     /* CYRILLIC SMALL LETTER CHE */
        /* ш */                Cyrillic_sha = 0x0448,     /* CYRILLIC SMALL LETTER SHA */
        /* щ */              Cyrillic_shcha = 0x0449,     /* CYRILLIC SMALL LETTER SHCHA */
        /* ъ */           Cyrillic_hardsign = 0x044a,     /* CYRILLIC SMALL LETTER HARD SIGN */
        /* ы */               Cyrillic_yeru = 0x044b,     /* CYRILLIC SMALL LETTER YERU */
        /* ь */           Cyrillic_softsign = 0x044c,     /* CYRILLIC SMALL LETTER SOFT SIGN */
        /* э */                  Cyrillic_e = 0x044d,     /* CYRILLIC SMALL LETTER E */
        /* ю */                 Cyrillic_yu = 0x044e,     /* CYRILLIC SMALL LETTER YU */
        /* я */                 Cyrillic_ya = 0x044f,     /* CYRILLIC SMALL LETTER YA */
        /* ё */                 Cyrillic_io = 0x0451,     /* CYRILLIC SMALL LETTER IO */
        /* ђ */                 Serbian_dje = 0x0452,     /* CYRILLIC SMALL LETTER DJE */
        /* ѓ */               Macedonia_gje = 0x0453,     /* CYRILLIC SMALL LETTER GJE */
        /* є */                Ukrainian_ie = 0x0454,     /* CYRILLIC SMALL LETTER UKRAINIAN IE */
        /* ѕ */               Macedonia_dse = 0x0455,     /* CYRILLIC SMALL LETTER DZE */
        /* і */                 Ukrainian_i = 0x0456,     /* CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I */
        /* ї */                Ukrainian_yi = 0x0457,     /* CYRILLIC SMALL LETTER YI */
        /* ј */                 Cyrillic_je = 0x0458,     /* CYRILLIC SMALL LETTER JE */
        /* љ */                Cyrillic_lje = 0x0459,     /* CYRILLIC SMALL LETTER LJE */
        /* њ */                Cyrillic_nje = 0x045a,     /* CYRILLIC SMALL LETTER NJE */
        /* ћ */                Serbian_tshe = 0x045b,     /* CYRILLIC SMALL LETTER TSHE */
        /* ќ */               Macedonia_kje = 0x045c,     /* CYRILLIC SMALL LETTER KJE */
        /* ў */         Byelorussian_shortu = 0x045e,     /* CYRILLIC SMALL LETTER SHORT U */
        /* џ */               Cyrillic_dzhe = 0x045f,     /* CYRILLIC SMALL LETTER DZHE */
    };
};

#if 0
+static struct {
+  unsigned short keysym;
+  unsigned short ucs;
+} yxapp_unicode_to_keysym_tab[] = {
+  { 0x0ce0, 0x05d0 }, /*                hebrew_aleph א HEBREW LETTER ALEF */
+  { 0x0ce1, 0x05d1 }, /*                  hebrew_bet ב HEBREW LETTER BET */
+  { 0x0ce2, 0x05d2 }, /*                hebrew_gimel ג HEBREW LETTER GIMEL */
+  { 0x0ce3, 0x05d3 }, /*                hebrew_dalet ד HEBREW LETTER DALET */
+  { 0x0ce4, 0x05d4 }, /*                   hebrew_he ה HEBREW LETTER HE */
+  { 0x0ce5, 0x05d5 }, /*                  hebrew_waw ו HEBREW LETTER VAV */
+  { 0x0ce6, 0x05d6 }, /*                 hebrew_zain ז HEBREW LETTER ZAYIN */
+  { 0x0ce7, 0x05d7 }, /*                 hebrew_chet ח HEBREW LETTER HET */
+  { 0x0ce8, 0x05d8 }, /*                  hebrew_tet ט HEBREW LETTER TET */
+  { 0x0ce9, 0x05d9 }, /*                  hebrew_yod י HEBREW LETTER YOD */
+  { 0x0cea, 0x05da }, /*            hebrew_finalkaph ך HEBREW LETTER FINAL KAF */
+  { 0x0ceb, 0x05db }, /*                 hebrew_kaph כ HEBREW LETTER KAF */
+  { 0x0cec, 0x05dc }, /*                hebrew_lamed ל HEBREW LETTER LAMED */
+  { 0x0ced, 0x05dd }, /*             hebrew_finalmem ם HEBREW LETTER FINAL MEM */
+  { 0x0cee, 0x05de }, /*                  hebrew_mem מ HEBREW LETTER MEM */
+  { 0x0cef, 0x05df }, /*             hebrew_finalnun ן HEBREW LETTER FINAL NUN */
+  { 0x0cf0, 0x05e0 }, /*                  hebrew_nun נ HEBREW LETTER NUN */
+  { 0x0cf1, 0x05e1 }, /*               hebrew_samech ס HEBREW LETTER SAMEKH */
+  { 0x0cf2, 0x05e2 }, /*                 hebrew_ayin ע HEBREW LETTER AYIN */
+  { 0x0cf3, 0x05e3 }, /*              hebrew_finalpe ף HEBREW LETTER FINAL PE */
+  { 0x0cf4, 0x05e4 }, /*                   hebrew_pe פ HEBREW LETTER PE */
+  { 0x0cf5, 0x05e5 }, /*            hebrew_finalzade ץ HEBREW LETTER FINAL TSADI */
+  { 0x0cf6, 0x05e6 }, /*                 hebrew_zade צ HEBREW LETTER TSADI */
+  { 0x0cf7, 0x05e7 }, /*                 hebrew_qoph ק HEBREW LETTER QOF */
+  { 0x0cf8, 0x05e8 }, /*                 hebrew_resh ר HEBREW LETTER RESH */
+  { 0x0cf9, 0x05e9 }, /*                 hebrew_shin ש HEBREW LETTER SHIN */
+  { 0x0cfa, 0x05ea }, /*                  hebrew_taw ת HEBREW LETTER TAV */
+  { 0x05ac, 0x060c }, /*                Arabic_comma ، ARABIC COMMA */
+  { 0x05bb, 0x061b }, /*            Arabic_semicolon ؛ ARABIC SEMICOLON */
+  { 0x05bf, 0x061f }, /*        Arabic_question_mark ؟ ARABIC QUESTION MARK */
+  { 0x05c1, 0x0621 }, /*                Arabic_hamza ء ARABIC LETTER HAMZA */
+  { 0x05c2, 0x0622 }, /*          Arabic_maddaonalef آ ARABIC LETTER ALEF WITH MADDA ABOVE */
+  { 0x05c3, 0x0623 }, /*          Arabic_hamzaonalef أ ARABIC LETTER ALEF WITH HAMZA ABOVE */
+  { 0x05c4, 0x0624 }, /*           Arabic_hamzaonwaw ؤ ARABIC LETTER WAW WITH HAMZA ABOVE */
+  { 0x05c5, 0x0625 }, /*       Arabic_hamzaunderalef إ ARABIC LETTER ALEF WITH HAMZA BELOW */
+  { 0x05c6, 0x0626 }, /*           Arabic_hamzaonyeh ئ ARABIC LETTER YEH WITH HAMZA ABOVE */
+  { 0x05c7, 0x0627 }, /*                 Arabic_alef ا ARABIC LETTER ALEF */
+  { 0x05c8, 0x0628 }, /*                  Arabic_beh ب ARABIC LETTER BEH */
+  { 0x05c9, 0x0629 }, /*           Arabic_tehmarbuta ة ARABIC LETTER TEH MARBUTA */
+  { 0x05ca, 0x062a }, /*                  Arabic_teh ت ARABIC LETTER TEH */
+  { 0x05cb, 0x062b }, /*                 Arabic_theh ث ARABIC LETTER THEH */
+  { 0x05cc, 0x062c }, /*                 Arabic_jeem ج ARABIC LETTER JEEM */
+  { 0x05cd, 0x062d }, /*                  Arabic_hah ح ARABIC LETTER HAH */
+  { 0x05ce, 0x062e }, /*                 Arabic_khah خ ARABIC LETTER KHAH */
+  { 0x05cf, 0x062f }, /*                  Arabic_dal د ARABIC LETTER DAL */
+  { 0x05d0, 0x0630 }, /*                 Arabic_thal ذ ARABIC LETTER THAL */
+  { 0x05d1, 0x0631 }, /*                   Arabic_ra ر ARABIC LETTER REH */
+  { 0x05d2, 0x0632 }, /*                 Arabic_zain ز ARABIC LETTER ZAIN */
+  { 0x05d3, 0x0633 }, /*                 Arabic_seen س ARABIC LETTER SEEN */
+  { 0x05d4, 0x0634 }, /*                Arabic_sheen ش ARABIC LETTER SHEEN */
+  { 0x05d5, 0x0635 }, /*                  Arabic_sad ص ARABIC LETTER SAD */
+  { 0x05d6, 0x0636 }, /*                  Arabic_dad ض ARABIC LETTER DAD */
+  { 0x05d7, 0x0637 }, /*                  Arabic_tah ط ARABIC LETTER TAH */
+  { 0x05d8, 0x0638 }, /*                  Arabic_zah ظ ARABIC LETTER ZAH */
+  { 0x05d9, 0x0639 }, /*                  Arabic_ain ع ARABIC LETTER AIN */
+  { 0x05da, 0x063a }, /*                Arabic_ghain غ ARABIC LETTER GHAIN */
+  { 0x05e0, 0x0640 }, /*              Arabic_tatweel ـ ARABIC TATWEEL */
+  { 0x05e1, 0x0641 }, /*                  Arabic_feh ف ARABIC LETTER FEH */
+  { 0x05e2, 0x0642 }, /*                  Arabic_qaf ق ARABIC LETTER QAF */
+  { 0x05e3, 0x0643 }, /*                  Arabic_kaf ك ARABIC LETTER KAF */
+  { 0x05e4, 0x0644 }, /*                  Arabic_lam ل ARABIC LETTER LAM */
+  { 0x05e5, 0x0645 }, /*                 Arabic_meem م ARABIC LETTER MEEM */
+  { 0x05e6, 0x0646 }, /*                 Arabic_noon ن ARABIC LETTER NOON */
+  { 0x05e7, 0x0647 }, /*                   Arabic_ha ه ARABIC LETTER HEH */
+  { 0x05e8, 0x0648 }, /*                  Arabic_waw و ARABIC LETTER WAW */
+  { 0x05e9, 0x0649 }, /*          Arabic_alefmaksura ى ARABIC LETTER ALEF MAKSURA */
+  { 0x05ea, 0x064a }, /*                  Arabic_yeh ي ARABIC LETTER YEH */
+  { 0x05eb, 0x064b }, /*             Arabic_fathatan ً ARABIC FATHATAN */
+  { 0x05ec, 0x064c }, /*             Arabic_dammatan ٌ ARABIC DAMMATAN */
+  { 0x05ed, 0x064d }, /*             Arabic_kasratan ٍ ARABIC KASRATAN */
+  { 0x05ee, 0x064e }, /*                Arabic_fatha َ ARABIC FATHA */
+  { 0x05ef, 0x064f }, /*                Arabic_damma ُ ARABIC DAMMA */
+  { 0x05f0, 0x0650 }, /*                Arabic_kasra ِ ARABIC KASRA */
+  { 0x05f1, 0x0651 }, /*               Arabic_shadda ّ ARABIC SHADDA */
+  { 0x05f2, 0x0652 }, /*                Arabic_sukun ْ ARABIC SUKUN */
+  { 0x0da1, 0x0e01 }, /*                  Thai_kokai ก THAI CHARACTER KO KAI */
+  { 0x0da2, 0x0e02 }, /*                Thai_khokhai ข THAI CHARACTER KHO KHAI */
+  { 0x0da3, 0x0e03 }, /*               Thai_khokhuat ฃ THAI CHARACTER KHO KHUAT */
+  { 0x0da4, 0x0e04 }, /*               Thai_khokhwai ค THAI CHARACTER KHO KHWAI */
+  { 0x0da5, 0x0e05 }, /*                Thai_khokhon ฅ THAI CHARACTER KHO KHON */
+  { 0x0da6, 0x0e06 }, /*             Thai_khorakhang ฆ THAI CHARACTER KHO RAKHANG */
+  { 0x0da7, 0x0e07 }, /*                 Thai_ngongu ง THAI CHARACTER NGO NGU */
+  { 0x0da8, 0x0e08 }, /*                Thai_chochan จ THAI CHARACTER CHO CHAN */
+  { 0x0da9, 0x0e09 }, /*               Thai_choching ฉ THAI CHARACTER CHO CHING */
+  { 0x0daa, 0x0e0a }, /*               Thai_chochang ช THAI CHARACTER CHO CHANG */
+  { 0x0dab, 0x0e0b }, /*                   Thai_soso ซ THAI CHARACTER SO SO */
+  { 0x0dac, 0x0e0c }, /*                Thai_chochoe ฌ THAI CHARACTER CHO CHOE */
+  { 0x0dad, 0x0e0d }, /*                 Thai_yoying ญ THAI CHARACTER YO YING */
+  { 0x0dae, 0x0e0e }, /*                Thai_dochada ฎ THAI CHARACTER DO CHADA */
+  { 0x0daf, 0x0e0f }, /*                Thai_topatak ฏ THAI CHARACTER TO PATAK */
+  { 0x0db0, 0x0e10 }, /*                Thai_thothan ฐ THAI CHARACTER THO THAN */
+  { 0x0db1, 0x0e11 }, /*          Thai_thonangmontho ฑ THAI CHARACTER THO NANGMONTHO */
+  { 0x0db2, 0x0e12 }, /*             Thai_thophuthao ฒ THAI CHARACTER THO PHUTHAO */
+  { 0x0db3, 0x0e13 }, /*                  Thai_nonen ณ THAI CHARACTER NO NEN */
+  { 0x0db4, 0x0e14 }, /*                  Thai_dodek ด THAI CHARACTER DO DEK */
+  { 0x0db5, 0x0e15 }, /*                  Thai_totao ต THAI CHARACTER TO TAO */
+  { 0x0db6, 0x0e16 }, /*               Thai_thothung ถ THAI CHARACTER THO THUNG */
+  { 0x0db7, 0x0e17 }, /*              Thai_thothahan ท THAI CHARACTER THO THAHAN */
+  { 0x0db8, 0x0e18 }, /*               Thai_thothong ธ THAI CHARACTER THO THONG */
+  { 0x0db9, 0x0e19 }, /*                   Thai_nonu น THAI CHARACTER NO NU */
+  { 0x0dba, 0x0e1a }, /*               Thai_bobaimai บ THAI CHARACTER BO BAIMAI */
+  { 0x0dbb, 0x0e1b }, /*                  Thai_popla ป THAI CHARACTER PO PLA */
+  { 0x0dbc, 0x0e1c }, /*               Thai_phophung ผ THAI CHARACTER PHO PHUNG */
+  { 0x0dbd, 0x0e1d }, /*                   Thai_fofa ฝ THAI CHARACTER FO FA */
+  { 0x0dbe, 0x0e1e }, /*                Thai_phophan พ THAI CHARACTER PHO PHAN */
+  { 0x0dbf, 0x0e1f }, /*                  Thai_fofan ฟ THAI CHARACTER FO FAN */
+  { 0x0dc0, 0x0e20 }, /*             Thai_phosamphao ภ THAI CHARACTER PHO SAMPHAO */
+  { 0x0dc1, 0x0e21 }, /*                   Thai_moma ม THAI CHARACTER MO MA */
+  { 0x0dc2, 0x0e22 }, /*                  Thai_yoyak ย THAI CHARACTER YO YAK */
+  { 0x0dc3, 0x0e23 }, /*                  Thai_rorua ร THAI CHARACTER RO RUA */
+  { 0x0dc4, 0x0e24 }, /*                     Thai_ru ฤ THAI CHARACTER RU */
+  { 0x0dc5, 0x0e25 }, /*                 Thai_loling ล THAI CHARACTER LO LING */
+  { 0x0dc6, 0x0e26 }, /*                     Thai_lu ฦ THAI CHARACTER LU */
+  { 0x0dc7, 0x0e27 }, /*                 Thai_wowaen ว THAI CHARACTER WO WAEN */
+  { 0x0dc8, 0x0e28 }, /*                 Thai_sosala ศ THAI CHARACTER SO SALA */
+  { 0x0dc9, 0x0e29 }, /*                 Thai_sorusi ษ THAI CHARACTER SO RUSI */
+  { 0x0dca, 0x0e2a }, /*                  Thai_sosua ส THAI CHARACTER SO SUA */
+  { 0x0dcb, 0x0e2b }, /*                  Thai_hohip ห THAI CHARACTER HO HIP */
+  { 0x0dcc, 0x0e2c }, /*                Thai_lochula ฬ THAI CHARACTER LO CHULA */
+  { 0x0dcd, 0x0e2d }, /*                   Thai_oang อ THAI CHARACTER O ANG */
+  { 0x0dce, 0x0e2e }, /*               Thai_honokhuk ฮ THAI CHARACTER HO NOKHUK */
+  { 0x0dcf, 0x0e2f }, /*              Thai_paiyannoi ฯ THAI CHARACTER PAIYANNOI */
+  { 0x0dd0, 0x0e30 }, /*                  Thai_saraa ะ THAI CHARACTER SARA A */
+  { 0x0dd1, 0x0e31 }, /*             Thai_maihanakat ั THAI CHARACTER MAI HAN-AKAT */
+  { 0x0dd2, 0x0e32 }, /*                 Thai_saraaa า THAI CHARACTER SARA AA */
+  { 0x0dd3, 0x0e33 }, /*                 Thai_saraam ำ THAI CHARACTER SARA AM */
+  { 0x0dd4, 0x0e34 }, /*                  Thai_sarai ิ THAI CHARACTER SARA I */
+  { 0x0dd5, 0x0e35 }, /*                 Thai_saraii ี THAI CHARACTER SARA II */
+  { 0x0dd6, 0x0e36 }, /*                 Thai_saraue ึ THAI CHARACTER SARA UE */
+  { 0x0dd7, 0x0e37 }, /*                Thai_sarauee ื THAI CHARACTER SARA UEE */
+  { 0x0dd8, 0x0e38 }, /*                  Thai_sarau ุ THAI CHARACTER SARA U */
+  { 0x0dd9, 0x0e39 }, /*                 Thai_sarauu ู THAI CHARACTER SARA UU */
+  { 0x0dda, 0x0e3a }, /*                Thai_phinthu ฺ THAI CHARACTER PHINTHU */
+  { 0x0ddf, 0x0e3f }, /*                   Thai_baht ฿ THAI CURRENCY SYMBOL BAHT */
+  { 0x0de0, 0x0e40 }, /*                  Thai_sarae เ THAI CHARACTER SARA E */
+  { 0x0de1, 0x0e41 }, /*                 Thai_saraae แ THAI CHARACTER SARA AE */
+  { 0x0de2, 0x0e42 }, /*                  Thai_sarao โ THAI CHARACTER SARA O */
+  { 0x0de3, 0x0e43 }, /*          Thai_saraaimaimuan ใ THAI CHARACTER SARA AI MAIMUAN */
+  { 0x0de4, 0x0e44 }, /*         Thai_saraaimaimalai ไ THAI CHARACTER SARA AI MAIMALAI */
+  { 0x0de5, 0x0e45 }, /*            Thai_lakkhangyao ๅ THAI CHARACTER LAKKHANGYAO */
+  { 0x0de6, 0x0e46 }, /*               Thai_maiyamok ๆ THAI CHARACTER MAIYAMOK */
+  { 0x0de7, 0x0e47 }, /*              Thai_maitaikhu ็ THAI CHARACTER MAITAIKHU */
+  { 0x0de8, 0x0e48 }, /*                  Thai_maiek ่ THAI CHARACTER MAI EK */
+  { 0x0de9, 0x0e49 }, /*                 Thai_maitho ้ THAI CHARACTER MAI THO */
+  { 0x0dea, 0x0e4a }, /*                 Thai_maitri ๊ THAI CHARACTER MAI TRI */
+  { 0x0deb, 0x0e4b }, /*            Thai_maichattawa ๋ THAI CHARACTER MAI CHATTAWA */
+  { 0x0dec, 0x0e4c }, /*            Thai_thanthakhat ์ THAI CHARACTER THANTHAKHAT */
+  { 0x0ded, 0x0e4d }, /*               Thai_nikhahit ํ THAI CHARACTER NIKHAHIT */
+  { 0x0df0, 0x0e50 }, /*                 Thai_leksun ๐ THAI DIGIT ZERO */
+  { 0x0df1, 0x0e51 }, /*                Thai_leknung ๑ THAI DIGIT ONE */
+  { 0x0df2, 0x0e52 }, /*                Thai_leksong ๒ THAI DIGIT TWO */
+  { 0x0df3, 0x0e53 }, /*                 Thai_leksam ๓ THAI DIGIT THREE */
+  { 0x0df4, 0x0e54 }, /*                  Thai_leksi ๔ THAI DIGIT FOUR */
+  { 0x0df5, 0x0e55 }, /*                  Thai_lekha ๕ THAI DIGIT FIVE */
+  { 0x0df6, 0x0e56 }, /*                 Thai_lekhok ๖ THAI DIGIT SIX */
+  { 0x0df7, 0x0e57 }, /*                Thai_lekchet ๗ THAI DIGIT SEVEN */
+  { 0x0df8, 0x0e58 }, /*                Thai_lekpaet ๘ THAI DIGIT EIGHT */
+  { 0x0df9, 0x0e59 }, /*                 Thai_lekkao ๙ THAI DIGIT NINE */
+  { 0x0ed4, 0x11a8 }, /*             Hangul_J_Kiyeog ᆨ HANGUL JONGSEONG KIYEOK */
+  { 0x0ed5, 0x11a9 }, /*        Hangul_J_SsangKiyeog ᆩ HANGUL JONGSEONG SSANGKIYEOK */
+  { 0x0ed6, 0x11aa }, /*         Hangul_J_KiyeogSios ᆪ HANGUL JONGSEONG KIYEOK-SIOS */
+  { 0x0ed7, 0x11ab }, /*              Hangul_J_Nieun ᆫ HANGUL JONGSEONG NIEUN */
+  { 0x0ed8, 0x11ac }, /*         Hangul_J_NieunJieuj ᆬ HANGUL JONGSEONG NIEUN-CIEUC */
+  { 0x0ed9, 0x11ad }, /*         Hangul_J_NieunHieuh ᆭ HANGUL JONGSEONG NIEUN-HIEUH */
+  { 0x0eda, 0x11ae }, /*             Hangul_J_Dikeud ᆮ HANGUL JONGSEONG TIKEUT */
+  { 0x0edb, 0x11af }, /*              Hangul_J_Rieul ᆯ HANGUL JONGSEONG RIEUL */
+  { 0x0edc, 0x11b0 }, /*        Hangul_J_RieulKiyeog ᆰ HANGUL JONGSEONG RIEUL-KIYEOK */
+  { 0x0edd, 0x11b1 }, /*         Hangul_J_RieulMieum ᆱ HANGUL JONGSEONG RIEUL-MIEUM */
+  { 0x0ede, 0x11b2 }, /*         Hangul_J_RieulPieub ᆲ HANGUL JONGSEONG RIEUL-PIEUP */
+  { 0x0edf, 0x11b3 }, /*          Hangul_J_RieulSios ᆳ HANGUL JONGSEONG RIEUL-SIOS */
+  { 0x0ee0, 0x11b4 }, /*         Hangul_J_RieulTieut ᆴ HANGUL JONGSEONG RIEUL-THIEUTH */
+  { 0x0ee1, 0x11b5 }, /*        Hangul_J_RieulPhieuf ᆵ HANGUL JONGSEONG RIEUL-PHIEUPH */
+  { 0x0ee2, 0x11b6 }, /*         Hangul_J_RieulHieuh ᆶ HANGUL JONGSEONG RIEUL-HIEUH */
+  { 0x0ee3, 0x11b7 }, /*              Hangul_J_Mieum ᆷ HANGUL JONGSEONG MIEUM */
+  { 0x0ee4, 0x11b8 }, /*              Hangul_J_Pieub ᆸ HANGUL JONGSEONG PIEUP */
+  { 0x0ee5, 0x11b9 }, /*          Hangul_J_PieubSios ᆹ HANGUL JONGSEONG PIEUP-SIOS */
+  { 0x0ee6, 0x11ba }, /*               Hangul_J_Sios ᆺ HANGUL JONGSEONG SIOS */
+  { 0x0ee7, 0x11bb }, /*          Hangul_J_SsangSios ᆻ HANGUL JONGSEONG SSANGSIOS */
+  { 0x0ee8, 0x11bc }, /*              Hangul_J_Ieung ᆼ HANGUL JONGSEONG IEUNG */
+  { 0x0ee9, 0x11bd }, /*              Hangul_J_Jieuj ᆽ HANGUL JONGSEONG CIEUC */
+  { 0x0eea, 0x11be }, /*              Hangul_J_Cieuc ᆾ HANGUL JONGSEONG CHIEUCH */
+  { 0x0eeb, 0x11bf }, /*             Hangul_J_Khieuq ᆿ HANGUL JONGSEONG KHIEUKH */
+  { 0x0eec, 0x11c0 }, /*              Hangul_J_Tieut ᇀ HANGUL JONGSEONG THIEUTH */
+  { 0x0eed, 0x11c1 }, /*             Hangul_J_Phieuf ᇁ HANGUL JONGSEONG PHIEUPH */
+  { 0x0eee, 0x11c2 }, /*              Hangul_J_Hieuh ᇂ HANGUL JONGSEONG HIEUH */
+  { 0x0ef8, 0x11eb }, /*            Hangul_J_PanSios ᇫ HANGUL JONGSEONG PANSIOS */
+  { 0x0efa, 0x11f9 }, /*        Hangul_J_YeorinHieuh ᇹ HANGUL JONGSEONG YEORINHIEUH */
+  { 0x0aa2, 0x2002 }, /*                     enspace   EN SPACE */
+  { 0x0aa1, 0x2003 }, /*                     emspace   EM SPACE */
+  { 0x0aa3, 0x2004 }, /*                    em3space   THREE-PER-EM SPACE */
+  { 0x0aa4, 0x2005 }, /*                    em4space   FOUR-PER-EM SPACE */
+  { 0x0aa5, 0x2007 }, /*                  digitspace   FIGURE SPACE */
+  { 0x0aa6, 0x2008 }, /*                  punctspace   PUNCTUATION SPACE */
+  { 0x0aa7, 0x2009 }, /*                   thinspace   THIN SPACE */
+  { 0x0aa8, 0x200a }, /*                   hairspace   HAIR SPACE */
+  { 0x0abb, 0x2012 }, /*                     figdash ‒ FIGURE DASH */
+  { 0x0aaa, 0x2013 }, /*                      endash – EN DASH */
+  { 0x0aa9, 0x2014 }, /*                      emdash — EM DASH */
+  { 0x07af, 0x2015 }, /*              Greek_horizbar ― HORIZONTAL BAR */
+  { 0x0cdf, 0x2017 }, /*        hebrew_doublelowline ‗ DOUBLE LOW LINE */
+  { 0x0ad0, 0x2018 }, /*         leftsinglequotemark ‘ LEFT SINGLE QUOTATION MARK */
+  { 0x0ad1, 0x2019 }, /*        rightsinglequotemark ’ RIGHT SINGLE QUOTATION MARK */
+  { 0x0afd, 0x201a }, /*          singlelowquotemark ‚ SINGLE LOW-9 QUOTATION MARK */
+  { 0x0ad2, 0x201c }, /*         leftdoublequotemark “ LEFT DOUBLE QUOTATION MARK */
+  { 0x0ad3, 0x201d }, /*        rightdoublequotemark ” RIGHT DOUBLE QUOTATION MARK */
+  { 0x0afe, 0x201e }, /*          doublelowquotemark „ DOUBLE LOW-9 QUOTATION MARK */
+  { 0x0af1, 0x2020 }, /*                      dagger † DAGGER */
+  { 0x0af2, 0x2021 }, /*                doubledagger ‡ DOUBLE DAGGER */
+  { 0x0ae6, 0x2022 }, /*          enfilledcircbullet • BULLET */
+  { 0x0aae, 0x2026 }, /*                    ellipsis … HORIZONTAL ELLIPSIS */
+  { 0x0ad6, 0x2032 }, /*                     minutes ′ PRIME */
+  { 0x0ad7, 0x2033 }, /*                     seconds ″ DOUBLE PRIME */
+  { 0x0afc, 0x2038 }, /*                       caret ‸ CARET */
+  { 0x047e, 0x203e }, /*                    overline ‾ OVERLINE */
+  { 0x20a0, 0x20a0 }, /*                     EcuSign ₠ EURO-CURRENCY SIGN */
+  { 0x20a1, 0x20a1 }, /*                   ColonSign ₡ COLON SIGN */
+  { 0x20a2, 0x20a2 }, /*                CruzeiroSign ₢ CRUZEIRO SIGN */
+  { 0x20a3, 0x20a3 }, /*                  FFrancSign ₣ FRENCH FRANC SIGN */
+  { 0x20a4, 0x20a4 }, /*                    LiraSign ₤ LIRA SIGN */
+  { 0x20a5, 0x20a5 }, /*                    MillSign ₥ MILL SIGN */
+  { 0x20a6, 0x20a6 }, /*                   NairaSign ₦ NAIRA SIGN */
+  { 0x20a7, 0x20a7 }, /*                  PesetaSign ₧ PESETA SIGN */
+  { 0x20a8, 0x20a8 }, /*                   RupeeSign ₨ RUPEE SIGN */
+  { 0x0eff, 0x20a9 }, /*                  Korean_Won ₩ WON SIGN */
+  { 0x20a9, 0x20a9 }, /*                     WonSign ₩ WON SIGN */
+  { 0x20aa, 0x20aa }, /*               NewSheqelSign ₪ NEW SHEQEL SIGN */
+  { 0x20ab, 0x20ab }, /*                    DongSign ₫ DONG SIGN */
+  { 0x20ac, 0x20ac }, /*                    EuroSign € EURO SIGN */
+  { 0x0ab8, 0x2105 }, /*                      careof ℅ CARE OF */
+  { 0x06b0, 0x2116 }, /*                  numerosign № NUMERO SIGN */
+  { 0x0afb, 0x2117 }, /*         phonographcopyright ℗ SOUND RECORDING COPYRIGHT */
+  { 0x0ad4, 0x211e }, /*                prescription ℞ PRESCRIPTION TAKE */
+  { 0x0ac9, 0x2122 }, /*                   trademark ™ TRADE MARK SIGN */
+  { 0x0ab0, 0x2153 }, /*                    onethird ⅓ VULGAR FRACTION ONE THIRD */
+  { 0x0ab1, 0x2154 }, /*                   twothirds ⅔ VULGAR FRACTION TWO THIRDS */
+  { 0x0ab2, 0x2155 }, /*                    onefifth ⅕ VULGAR FRACTION ONE FIFTH */
+  { 0x0ab3, 0x2156 }, /*                   twofifths ⅖ VULGAR FRACTION TWO FIFTHS */
+  { 0x0ab4, 0x2157 }, /*                 threefifths ⅗ VULGAR FRACTION THREE FIFTHS */
+  { 0x0ab5, 0x2158 }, /*                  fourfifths ⅘ VULGAR FRACTION FOUR FIFTHS */
+  { 0x0ab6, 0x2159 }, /*                    onesixth ⅙ VULGAR FRACTION ONE SIXTH */
+  { 0x0ab7, 0x215a }, /*                  fivesixths ⅚ VULGAR FRACTION FIVE SIXTHS */
+  { 0x0ac3, 0x215b }, /*                   oneeighth ⅛ VULGAR FRACTION ONE EIGHTH */
+  { 0x0ac4, 0x215c }, /*                threeeighths ⅜ VULGAR FRACTION THREE EIGHTHS */
+  { 0x0ac5, 0x215d }, /*                 fiveeighths ⅝ VULGAR FRACTION FIVE EIGHTHS */
+  { 0x0ac6, 0x215e }, /*                seveneighths ⅞ VULGAR FRACTION SEVEN EIGHTHS */
+  { 0x08fb, 0x2190 }, /*                   leftarrow ← LEFTWARDS ARROW */
+  { 0x08fc, 0x2191 }, /*                     uparrow ↑ UPWARDS ARROW */
+  { 0x08fd, 0x2192 }, /*                  rightarrow → RIGHTWARDS ARROW */
+  { 0x08fe, 0x2193 }, /*                   downarrow ↓ DOWNWARDS ARROW */
+  { 0x08ce, 0x21d2 }, /*                     implies ⇒ RIGHTWARDS DOUBLE ARROW */
+  { 0x08cd, 0x21d4 }, /*                    ifonlyif ⇔ LEFT RIGHT DOUBLE ARROW */
+  { 0x08ef, 0x2202 }, /*           partialderivative ∂ PARTIAL DIFFERENTIAL */
+  { 0x08c5, 0x2207 }, /*                       nabla ∇ NABLA */
+  { 0x0bca, 0x2218 }, /*                         jot ∘ RING OPERATOR */
+  { 0x08d6, 0x221a }, /*                     radical √ SQUARE ROOT */
+  { 0x08c1, 0x221d }, /*                   variation ∝ PROPORTIONAL TO */
+  { 0x08c2, 0x221e }, /*                    infinity ∞ INFINITY */
+  { 0x08de, 0x2227 }, /*                  logicaland ∧ LOGICAL AND */
+  { 0x0ba9, 0x2227 }, /*                     upcaret ∧ LOGICAL AND */
+  { 0x08df, 0x2228 }, /*                   logicalor ∨ LOGICAL OR */
+  { 0x0ba8, 0x2228 }, /*                   downcaret ∨ LOGICAL OR */
+  { 0x08dc, 0x2229 }, /*                intersection ∩ INTERSECTION */
+  { 0x0bc3, 0x2229 }, /*                      upshoe ∩ INTERSECTION */
+  { 0x08dd, 0x222a }, /*                       union ∪ UNION */
+  { 0x0bd6, 0x222a }, /*                    downshoe ∪ UNION */
+  { 0x08bf, 0x222b }, /*                    integral ∫ INTEGRAL */
+  { 0x08c0, 0x2234 }, /*                   therefore ∴ THEREFORE */
+  { 0x08c8, 0x2245 }, /*                 approximate ≅ APPROXIMATELY EQUAL TO */
+  { 0x08bd, 0x2260 }, /*                    notequal ≠ NOT EQUAL TO */
+  { 0x08cf, 0x2261 }, /*                   identical ≡ IDENTICAL TO */
+  { 0x08bc, 0x2264 }, /*               lessthanequal ≤ LESS-THAN OR EQUAL TO */
+  { 0x08be, 0x2265 }, /*            greaterthanequal ≥ GREATER-THAN OR EQUAL TO */
+  { 0x08da, 0x2282 }, /*                  includedin ⊂ SUBSET OF */
+  { 0x0bda, 0x2282 }, /*                    leftshoe ⊂ SUBSET OF */
+  { 0x08db, 0x2283 }, /*                    includes ⊃ SUPERSET OF */
+  { 0x0bd8, 0x2283 }, /*                   rightshoe ⊃ SUPERSET OF */
+  { 0x0bfc, 0x22a2 }, /*                   righttack ⊢ RIGHT TACK */
+  { 0x0bdc, 0x22a3 }, /*                    lefttack ⊣ LEFT TACK */
+  { 0x0bc2, 0x22a4 }, /*                    downtack ⊤ DOWN TACK */
+  { 0x0bce, 0x22a5 }, /*                      uptack ⊥ UP TACK */
+  { 0x0bd3, 0x2308 }, /*                     upstile ⌈ LEFT CEILING */
+  { 0x0bc4, 0x230a }, /*                   downstile ⌊ LEFT FLOOR */
+  { 0x0afa, 0x2315 }, /*           telephonerecorder ⌕ TELEPHONE RECORDER */
+  { 0x08a4, 0x2320 }, /*                 topintegral ⌠ TOP HALF INTEGRAL */
+  { 0x08a5, 0x2321 }, /*                 botintegral ⌡ BOTTOM HALF INTEGRAL */
+  { 0x0abc, 0x2329 }, /*            leftanglebracket 〈 LEFT-POINTING ANGLE BRACKET */
+  { 0x0abe, 0x232a }, /*           rightanglebracket 〉 RIGHT-POINTING ANGLE BRACKET */
+  { 0x0bcc, 0x2395 }, /*                        quad ⎕ APL FUNCTIONAL SYMBOL QUAD (Unicode 3.0) */
+  { 0x09e2, 0x2409 }, /*                          ht ␉ SYMBOL FOR HORIZONTAL TABULATION */
+  { 0x09e5, 0x240a }, /*                          lf ␊ SYMBOL FOR LINE FEED */
+  { 0x09e9, 0x240b }, /*                          vt ␋ SYMBOL FOR VERTICAL TABULATION */
+  { 0x09e3, 0x240c }, /*                          ff ␌ SYMBOL FOR FORM FEED */
+  { 0x09e4, 0x240d }, /*                          cr ␍ SYMBOL FOR CARRIAGE RETURN */
+  { 0x09df, 0x2422 }, /*                       blank ␢ BLANK SYMBOL */
+  { 0x09e8, 0x2424 }, /*                          nl ␤ SYMBOL FOR NEWLINE */
+  { 0x09f1, 0x2500 }, /*              horizlinescan5 ─ BOX DRAWINGS LIGHT HORIZONTAL */
+  { 0x08a6, 0x2502 }, /*               vertconnector │ BOX DRAWINGS LIGHT VERTICAL */
+  { 0x09f8, 0x2502 }, /*                     vertbar │ BOX DRAWINGS LIGHT VERTICAL */
+  { 0x09ec, 0x250c }, /*                upleftcorner ┌ BOX DRAWINGS LIGHT DOWN AND RIGHT */
+  { 0x09eb, 0x2510 }, /*               uprightcorner ┐ BOX DRAWINGS LIGHT DOWN AND LEFT */
+  { 0x09ed, 0x2514 }, /*               lowleftcorner └ BOX DRAWINGS LIGHT UP AND RIGHT */
+  { 0x09ea, 0x2518 }, /*              lowrightcorner ┘ BOX DRAWINGS LIGHT UP AND LEFT */
+  { 0x09f4, 0x251c }, /*                       leftt ├ BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
+  { 0x09f5, 0x2524 }, /*                      rightt ┤ BOX DRAWINGS LIGHT VERTICAL AND LEFT */
+  { 0x09f7, 0x252c }, /*                        topt ┬ BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
+  { 0x09f6, 0x2534 }, /*                        bott ┴ BOX DRAWINGS LIGHT UP AND HORIZONTAL */
+  { 0x09ee, 0x253c }, /*               crossinglines ┼ BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
+  { 0x09e1, 0x2592 }, /*                checkerboard ▒ MEDIUM SHADE */
+  { 0x0adf, 0x25a0 }, /*                emfilledrect ■ BLACK SQUARE */
+  { 0x0acf, 0x25a1 }, /*             emopenrectangle □ WHITE SQUARE */
+  { 0x0ae7, 0x25aa }, /*            enfilledsqbullet ▪ BLACK SMALL SQUARE */
+  { 0x0ae1, 0x25ab }, /*          enopensquarebullet ▫ WHITE SMALL SQUARE */
+  { 0x0adb, 0x25ac }, /*            filledrectbullet ▬ BLACK RECTANGLE */
+  { 0x0ae2, 0x25ad }, /*              openrectbullet ▭ WHITE RECTANGLE */
+  { 0x0ae8, 0x25b2 }, /*           filledtribulletup ▲ BLACK UP-POINTING TRIANGLE */
+  { 0x0ae3, 0x25b3 }, /*             opentribulletup △ WHITE UP-POINTING TRIANGLE */
+  { 0x0add, 0x25b6 }, /*        filledrighttribullet ▶ BLACK RIGHT-POINTING TRIANGLE */
+  { 0x0acd, 0x25b7 }, /*           rightopentriangle ▷ WHITE RIGHT-POINTING TRIANGLE */
+  { 0x0ae9, 0x25bc }, /*         filledtribulletdown ▼ BLACK DOWN-POINTING TRIANGLE */
+  { 0x0ae4, 0x25bd }, /*           opentribulletdown ▽ WHITE DOWN-POINTING TRIANGLE */
+  { 0x0adc, 0x25c0 }, /*         filledlefttribullet ◀ BLACK LEFT-POINTING TRIANGLE */
+  { 0x0acc, 0x25c1 }, /*            leftopentriangle ◁ WHITE LEFT-POINTING TRIANGLE */
+  { 0x09e0, 0x25c6 }, /*                soliddiamond ◆ BLACK DIAMOND */
+  { 0x0ace, 0x25cb }, /*                emopencircle ○ WHITE CIRCLE */
+  { 0x0bcf, 0x25cb }, /*                      circle ○ WHITE CIRCLE */
+  { 0x0ade, 0x25cf }, /*              emfilledcircle ● BLACK CIRCLE */
+  { 0x0ae0, 0x25e6 }, /*            enopencircbullet ◦ WHITE BULLET */
+  { 0x0ae5, 0x2606 }, /*                    openstar ☆ WHITE STAR */
+  { 0x0af9, 0x260e }, /*                   telephone ☎ BLACK TELEPHONE */
+  { 0x0aca, 0x2613 }, /*               signaturemark ☓ SALTIRE */
+  { 0x0aea, 0x261c }, /*                 leftpointer ☜ WHITE LEFT POINTING INDEX */
+  { 0x0aeb, 0x261e }, /*                rightpointer ☞ WHITE RIGHT POINTING INDEX */
+  { 0x0af8, 0x2640 }, /*                femalesymbol ♀ FEMALE SIGN */
+  { 0x0af7, 0x2642 }, /*                  malesymbol ♂ MALE SIGN */
+  { 0x0aec, 0x2663 }, /*                        club ♣ BLACK CLUB SUIT */
+  { 0x0aee, 0x2665 }, /*                       heart ♥ BLACK HEART SUIT */
+  { 0x0aed, 0x2666 }, /*                     diamond ♦ BLACK DIAMOND SUIT */
+  { 0x0af6, 0x266d }, /*                 musicalflat ♭ MUSIC FLAT SIGN */
+  { 0x0af5, 0x266f }, /*                musicalsharp ♯ MUSIC SHARP SIGN */
+  { 0x0af3, 0x2713 }, /*                   checkmark ✓ CHECK MARK */
+  { 0x0af4, 0x2717 }, /*                 ballotcross ✗ BALLOT X */
+  { 0x0ad9, 0x271d }, /*                  latincross ✝ LATIN CROSS */
+  { 0x0af0, 0x2720 }, /*                maltesecross ✠ MALTESE CROSS */
+  { 0x04a4, 0x3001 }, /*                  kana_comma 、 IDEOGRAPHIC COMMA */
+  { 0x04a1, 0x3002 }, /*               kana_fullstop 。 IDEOGRAPHIC FULL STOP */
+  { 0x04a2, 0x300c }, /*         kana_openingbracket 「 LEFT CORNER BRACKET */
+  { 0x04a3, 0x300d }, /*         kana_closingbracket 」 RIGHT CORNER BRACKET */
+  { 0x04de, 0x309b }, /*                 voicedsound ゛ KATAKANA-HIRAGANA VOICED SOUND MARK */
+  { 0x04df, 0x309c }, /*             semivoicedsound ゜ KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK */
+  { 0x04a7, 0x30a1 }, /*                      kana_a ァ KATAKANA LETTER SMALL A */
+  { 0x04b1, 0x30a2 }, /*                      kana_A ア KATAKANA LETTER A */
+  { 0x04a8, 0x30a3 }, /*                      kana_i ィ KATAKANA LETTER SMALL I */
+  { 0x04b2, 0x30a4 }, /*                      kana_I イ KATAKANA LETTER I */
+  { 0x04a9, 0x30a5 }, /*                      kana_u ゥ KATAKANA LETTER SMALL U */
+  { 0x04b3, 0x30a6 }, /*                      kana_U ウ KATAKANA LETTER U */
+  { 0x04aa, 0x30a7 }, /*                      kana_e ェ KATAKANA LETTER SMALL E */
+  { 0x04b4, 0x30a8 }, /*                      kana_E エ KATAKANA LETTER E */
+  { 0x04ab, 0x30a9 }, /*                      kana_o ォ KATAKANA LETTER SMALL O */
+  { 0x04b5, 0x30aa }, /*                      kana_O オ KATAKANA LETTER O */
+  { 0x04b6, 0x30ab }, /*                     kana_KA カ KATAKANA LETTER KA */
+  { 0x04b7, 0x30ad }, /*                     kana_KI キ KATAKANA LETTER KI */
+  { 0x04b8, 0x30af }, /*                     kana_KU ク KATAKANA LETTER KU */
+  { 0x04b9, 0x30b1 }, /*                     kana_KE ケ KATAKANA LETTER KE */
+  { 0x04ba, 0x30b3 }, /*                     kana_KO コ KATAKANA LETTER KO */
+  { 0x04bb, 0x30b5 }, /*                     kana_SA サ KATAKANA LETTER SA */
+  { 0x04bc, 0x30b7 }, /*                    kana_SHI シ KATAKANA LETTER SI */
+  { 0x04bd, 0x30b9 }, /*                     kana_SU ス KATAKANA LETTER SU */
+  { 0x04be, 0x30bb }, /*                     kana_SE セ KATAKANA LETTER SE */
+  { 0x04bf, 0x30bd }, /*                     kana_SO ソ KATAKANA LETTER SO */
+  { 0x04c0, 0x30bf }, /*                     kana_TA タ KATAKANA LETTER TA */
+  { 0x04c1, 0x30c1 }, /*                    kana_CHI チ KATAKANA LETTER TI */
+  { 0x04af, 0x30c3 }, /*                    kana_tsu ッ KATAKANA LETTER SMALL TU */
+  { 0x04c2, 0x30c4 }, /*                    kana_TSU ツ KATAKANA LETTER TU */
+  { 0x04c3, 0x30c6 }, /*                     kana_TE テ KATAKANA LETTER TE */
+  { 0x04c4, 0x30c8 }, /*                     kana_TO ト KATAKANA LETTER TO */
+  { 0x04c5, 0x30ca }, /*                     kana_NA ナ KATAKANA LETTER NA */
+  { 0x04c6, 0x30cb }, /*                     kana_NI ニ KATAKANA LETTER NI */
+  { 0x04c7, 0x30cc }, /*                     kana_NU ヌ KATAKANA LETTER NU */
+  { 0x04c8, 0x30cd }, /*                     kana_NE ネ KATAKANA LETTER NE */
+  { 0x04c9, 0x30ce }, /*                     kana_NO ノ KATAKANA LETTER NO */
+  { 0x04ca, 0x30cf }, /*                     kana_HA ハ KATAKANA LETTER HA */
+  { 0x04cb, 0x30d2 }, /*                     kana_HI ヒ KATAKANA LETTER HI */
+  { 0x04cc, 0x30d5 }, /*                     kana_FU フ KATAKANA LETTER HU */
+  { 0x04cd, 0x30d8 }, /*                     kana_HE ヘ KATAKANA LETTER HE */
+  { 0x04ce, 0x30db }, /*                     kana_HO ホ KATAKANA LETTER HO */
+  { 0x04cf, 0x30de }, /*                     kana_MA マ KATAKANA LETTER MA */
+  { 0x04d0, 0x30df }, /*                     kana_MI ミ KATAKANA LETTER MI */
+  { 0x04d1, 0x30e0 }, /*                     kana_MU ム KATAKANA LETTER MU */
+  { 0x04d2, 0x30e1 }, /*                     kana_ME メ KATAKANA LETTER ME */
+  { 0x04d3, 0x30e2 }, /*                     kana_MO モ KATAKANA LETTER MO */
+  { 0x04ac, 0x30e3 }, /*                     kana_ya ャ KATAKANA LETTER SMALL YA */
+  { 0x04d4, 0x30e4 }, /*                     kana_YA ヤ KATAKANA LETTER YA */
+  { 0x04ad, 0x30e5 }, /*                     kana_yu ュ KATAKANA LETTER SMALL YU */
+  { 0x04d5, 0x30e6 }, /*                     kana_YU ユ KATAKANA LETTER YU */
+  { 0x04ae, 0x30e7 }, /*                     kana_yo ョ KATAKANA LETTER SMALL YO */
+  { 0x04d6, 0x30e8 }, /*                     kana_YO ヨ KATAKANA LETTER YO */
+  { 0x04d7, 0x30e9 }, /*                     kana_RA ラ KATAKANA LETTER RA */
+  { 0x04d8, 0x30ea }, /*                     kana_RI リ KATAKANA LETTER RI */
+  { 0x04d9, 0x30eb }, /*                     kana_RU ル KATAKANA LETTER RU */
+  { 0x04da, 0x30ec }, /*                     kana_RE レ KATAKANA LETTER RE */
+  { 0x04db, 0x30ed }, /*                     kana_RO ロ KATAKANA LETTER RO */
+  { 0x04dc, 0x30ef }, /*                     kana_WA ワ KATAKANA LETTER WA */
+  { 0x04a6, 0x30f2 }, /*                     kana_WO ヲ KATAKANA LETTER WO */
+  { 0x04dd, 0x30f3 }, /*                      kana_N ン KATAKANA LETTER N */
+  { 0x04a5, 0x30fb }, /*            kana_conjunctive ・ KATAKANA MIDDLE DOT */
+  { 0x04b0, 0x30fc }, /*              prolongedsound ー KATAKANA-HIRAGANA PROLONGED SOUND MARK */
+  { 0x0ea1, 0x3131 }, /*               Hangul_Kiyeog ㄱ HANGUL LETTER KIYEOK */
+  { 0x0ea2, 0x3132 }, /*          Hangul_SsangKiyeog ㄲ HANGUL LETTER SSANGKIYEOK */
+  { 0x0ea3, 0x3133 }, /*           Hangul_KiyeogSios ㄳ HANGUL LETTER KIYEOK-SIOS */
+  { 0x0ea4, 0x3134 }, /*                Hangul_Nieun ㄴ HANGUL LETTER NIEUN */
+  { 0x0ea5, 0x3135 }, /*           Hangul_NieunJieuj ㄵ HANGUL LETTER NIEUN-CIEUC */
+  { 0x0ea6, 0x3136 }, /*           Hangul_NieunHieuh ㄶ HANGUL LETTER NIEUN-HIEUH */
+  { 0x0ea7, 0x3137 }, /*               Hangul_Dikeud ㄷ HANGUL LETTER TIKEUT */
+  { 0x0ea8, 0x3138 }, /*          Hangul_SsangDikeud ㄸ HANGUL LETTER SSANGTIKEUT */
+  { 0x0ea9, 0x3139 }, /*                Hangul_Rieul ㄹ HANGUL LETTER RIEUL */
+  { 0x0eaa, 0x313a }, /*          Hangul_RieulKiyeog ㄺ HANGUL LETTER RIEUL-KIYEOK */
+  { 0x0eab, 0x313b }, /*           Hangul_RieulMieum ㄻ HANGUL LETTER RIEUL-MIEUM */
+  { 0x0eac, 0x313c }, /*           Hangul_RieulPieub ㄼ HANGUL LETTER RIEUL-PIEUP */
+  { 0x0ead, 0x313d }, /*            Hangul_RieulSios ㄽ HANGUL LETTER RIEUL-SIOS */
+  { 0x0eae, 0x313e }, /*           Hangul_RieulTieut ㄾ HANGUL LETTER RIEUL-THIEUTH */
+  { 0x0eaf, 0x313f }, /*          Hangul_RieulPhieuf ㄿ HANGUL LETTER RIEUL-PHIEUPH */
+  { 0x0eb0, 0x3140 }, /*           Hangul_RieulHieuh ㅀ HANGUL LETTER RIEUL-HIEUH */
+  { 0x0eb1, 0x3141 }, /*                Hangul_Mieum ㅁ HANGUL LETTER MIEUM */
+  { 0x0eb2, 0x3142 }, /*                Hangul_Pieub ㅂ HANGUL LETTER PIEUP */
+  { 0x0eb3, 0x3143 }, /*           Hangul_SsangPieub ㅃ HANGUL LETTER SSANGPIEUP */
+  { 0x0eb4, 0x3144 }, /*            Hangul_PieubSios ㅄ HANGUL LETTER PIEUP-SIOS */
+  { 0x0eb5, 0x3145 }, /*                 Hangul_Sios ㅅ HANGUL LETTER SIOS */
+  { 0x0eb6, 0x3146 }, /*            Hangul_SsangSios ㅆ HANGUL LETTER SSANGSIOS */
+  { 0x0eb7, 0x3147 }, /*                Hangul_Ieung ㅇ HANGUL LETTER IEUNG */
+  { 0x0eb8, 0x3148 }, /*                Hangul_Jieuj ㅈ HANGUL LETTER CIEUC */
+  { 0x0eb9, 0x3149 }, /*           Hangul_SsangJieuj ㅉ HANGUL LETTER SSANGCIEUC */
+  { 0x0eba, 0x314a }, /*                Hangul_Cieuc ㅊ HANGUL LETTER CHIEUCH */
+  { 0x0ebb, 0x314b }, /*               Hangul_Khieuq ㅋ HANGUL LETTER KHIEUKH */
+  { 0x0ebc, 0x314c }, /*                Hangul_Tieut ㅌ HANGUL LETTER THIEUTH */
+  { 0x0ebd, 0x314d }, /*               Hangul_Phieuf ㅍ HANGUL LETTER PHIEUPH */
+  { 0x0ebe, 0x314e }, /*                Hangul_Hieuh ㅎ HANGUL LETTER HIEUH */
+  { 0x0ebf, 0x314f }, /*                    Hangul_A ㅏ HANGUL LETTER A */
+  { 0x0ec0, 0x3150 }, /*                   Hangul_AE ㅐ HANGUL LETTER AE */
+  { 0x0ec1, 0x3151 }, /*                   Hangul_YA ㅑ HANGUL LETTER YA */
+  { 0x0ec2, 0x3152 }, /*                  Hangul_YAE ㅒ HANGUL LETTER YAE */
+  { 0x0ec3, 0x3153 }, /*                   Hangul_EO ㅓ HANGUL LETTER EO */
+  { 0x0ec4, 0x3154 }, /*                    Hangul_E ㅔ HANGUL LETTER E */
+  { 0x0ec5, 0x3155 }, /*                  Hangul_YEO ㅕ HANGUL LETTER YEO */
+  { 0x0ec6, 0x3156 }, /*                   Hangul_YE ㅖ HANGUL LETTER YE */
+  { 0x0ec7, 0x3157 }, /*                    Hangul_O ㅗ HANGUL LETTER O */
+  { 0x0ec8, 0x3158 }, /*                   Hangul_WA ㅘ HANGUL LETTER WA */
+  { 0x0ec9, 0x3159 }, /*                  Hangul_WAE ㅙ HANGUL LETTER WAE */
+  { 0x0eca, 0x315a }, /*                   Hangul_OE ㅚ HANGUL LETTER OE */
+  { 0x0ecb, 0x315b }, /*                   Hangul_YO ㅛ HANGUL LETTER YO */
+  { 0x0ecc, 0x315c }, /*                    Hangul_U ㅜ HANGUL LETTER U */
+  { 0x0ecd, 0x315d }, /*                  Hangul_WEO ㅝ HANGUL LETTER WEO */
+  { 0x0ece, 0x315e }, /*                   Hangul_WE ㅞ HANGUL LETTER WE */
+  { 0x0ecf, 0x315f }, /*                   Hangul_WI ㅟ HANGUL LETTER WI */
+  { 0x0ed0, 0x3160 }, /*                   Hangul_YU ㅠ HANGUL LETTER YU */
+  { 0x0ed1, 0x3161 }, /*                   Hangul_EU ㅡ HANGUL LETTER EU */
+  { 0x0ed2, 0x3162 }, /*                   Hangul_YI ㅢ HANGUL LETTER YI */
+  { 0x0ed3, 0x3163 }, /*                    Hangul_I ㅣ HANGUL LETTER I */
+  { 0x0eef, 0x316d }, /*     Hangul_RieulYeorinHieuh ㅭ HANGUL LETTER RIEUL-YEORINHIEUH */
+  { 0x0ef0, 0x3171 }, /*    Hangul_SunkyeongeumMieum ㅱ HANGUL LETTER KAPYEOUNMIEUM */
+  { 0x0ef1, 0x3178 }, /*    Hangul_SunkyeongeumPieub ㅸ HANGUL LETTER KAPYEOUNPIEUP */
+  { 0x0ef2, 0x317f }, /*              Hangul_PanSios ㅿ HANGUL LETTER PANSIOS */
+  { 0x0ef4, 0x3184 }, /*   Hangul_SunkyeongeumPhieuf ㆄ HANGUL LETTER KAPYEOUNPHIEUPH */
+  { 0x0ef5, 0x3186 }, /*          Hangul_YeorinHieuh ㆆ HANGUL LETTER YEORINHIEUH */
+  { 0x0ef6, 0x318d }, /*                Hangul_AraeA ㆍ HANGUL LETTER ARAEA */
+  { 0x0ef7, 0x318e }, /*               Hangul_AraeAE ㆎ HANGUL LETTER ARAEAE */
+};
+
 #endif

#endif // __UCS2_H__

