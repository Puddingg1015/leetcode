char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char *out = malloc(sizeof(char) * (wordsSize + 1));
    for (int i = 0; i < wordsSize; i++) {
        char *word = words[i];
        int weight = 0;
        for (int j = 0; word[j] != '\0'; j++) weight += weights[word[j] - 'a'];
        *(out + i) = (char) (25 - weight % 26) + 'a';
    }
    out[wordsSize] = '\0';
    return out;
}