int numberOfSpecialChars(char* word) {
    int count = 0;
    for (char base = 'a'; base <= 'z'; base++) {
        bool lower = false;
        bool upper = false;
        bool valid = true;
        for (int i = 0; word[i] != '\0'; i++) {
            char c = word[i];
            if (c == base) {
                if (upper) {
                    valid = false;
                    break;
                }
                lower = true;
            } else if (c == ('A' + base - 'a')) {
                if (!lower) {
                    valid = false;
                    break;
                }   
                upper = true;
            }
        }
        if (valid && upper && lower) {
            count++;
        }       
    }
    return count;
}