/**
 * @brief Converte una stringa in intero (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − riconoscendo l'eventuale (singolo) carattere del segno,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data
 * (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non
 * trova nessuna cifra valida (e in tal caso il valore all'indirizzo r non è
 * significativo). Altrimenti restituisce 1, e scrive all'indirizzo r il numero
 * intero rappresentato nella stringa nella base data. Non si accorge
 * dell'eventuale overflow (restituendo in questo caso un risultato scorretto).
 */

char touppercase(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 32;
  }
  return c;
}

char *sanitize(char *s, int *size_ptr) {
  int i = 0;

  while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
    i++;
  }

  char sign = '+';
  if (s[i] == '+' || s[i] == '-') {
    sign = s[i];
    i++;

    if (s[i] == '+' || s[i] == '-') {
      *size_ptr = 0;
      return NULL;
    }
  } else if (s[i] == '.' || s[i] == ',') {
    *size_ptr = 0;
    return NULL;
  }

  int start = i;
  int size = 0;
  bool ok = true;
  while (s[i] != '\0' && ok) {
    if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') ||
        (s[i] >= 'a' && s[i] <= 'z')) {
      size++;
      i++;
    } else {
      ok = false;
    }
  }

  *size_ptr = size + 1;
  char *outstr = (char *)malloc(size + 2);
  if (!outstr) {
    *size_ptr = 0;
    return NULL;
  }

  int pos = 0;
  outstr[pos++] = sign;

  for (int j = 0; j < size; j++) {
    char c = s[start + j];
    outstr[pos++] = touppercase(c);
  }

  outstr[pos] = '\0';
  return outstr;
}

int stoub(char *s, unsigned short b, int *r) {
  int size;
  char *sanitized = sanitize(s, &size);

  if (b < 2 || b > 36) {
    if (sanitized)
      free(sanitized);
    return 0;
  }

  if (!size || size == 1) {
    free(sanitized);
    return 0;
  }

  int result = 0;
  bool valid_digit = false;
  bool ok = true;

  for (int i = 1; sanitized[i] != '\0' && ok; i++) {
    char c = sanitized[i];
    int digit = 0;
    bool valid = true;

    if (c >= '0' && c <= '9') {
      digit = c - '0';
    } else if (c >= 'A' && c <= 'Z') {
      digit = c - 'A' + 10;
    } else {
      valid = false;
    }

    if (valid) {
      if (digit < b) {
        result = result * b + digit;
        valid_digit = true;
      } else {
        ok = false;
      }
    } else {
      ok = false;
    }
  }

  if (!valid_digit) {
    free(sanitized);
    return 0;
  }

  if (sanitized[0] == '-') {
    result = -result;
  }

  *r = result;
  free(sanitized);
  return 1;
}
