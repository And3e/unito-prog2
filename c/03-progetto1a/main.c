/* numero negativo */
tests[0].s = "-25";
tests[0].b = 10;
tests[0].res = 1;
tests[0].num = -25;

/* numero positivo (con segno) */
tests[1].s = "+25";
tests[1].b = 10;
tests[1].res = 1;
tests[1].num = 25;

/* spazi iniziali */
tests[2].s = "   25";
tests[2].b = 10;
tests[2].res = 1;
tests[2].num = 25;

/* base fuori range */
tests[3].s = "25";
tests[3].b = 37;
tests[3].res = 0;

/* solo spazi vuoti */
tests[4].s = "    ";
tests[4].b = 10;
tests[4].res = 0;

/* conversione base 36 */
tests[5].s = "10Z";
tests[5].b = 36;
tests[5].res = 1;
tests[5].num = 1331;

/* carattere non riconosciuto dalla base */
tests[6].s = "102";
tests[6].b = 2;
tests[6].res = 1;
tests[6].num = 2;

/* boh (NO carattere speciale) */
tests[7].s = "10";
tests[7].b = 36;
tests[7].res = 1;
tests[7].num = 36;

tests[8].s = "1";
tests[8].b = 10;
tests[8].res = 1;
tests[8].num = 1;