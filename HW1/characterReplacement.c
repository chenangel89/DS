int characterReplacement(char * s, int k){
    int max_freq = 0, max_len = 0, start = 0, len = strlen(s);
    int freq[26] = {0};
    
    for (int end = 0; end < len; end++) {
        freq[s[end] - 'A']++;
        max_freq = (freq[s[end] - 'A'] > max_freq) ? freq[s[end] - 'A'] : max_freq;
        while (end - start + 1 - max_freq > k) {
            freq[s[start] - 'A']--;
            start++;
        }
        max_len = (end - start + 1 > max_len) ? end - start + 1 : max_len;
    }
    
    return max_len;
}
