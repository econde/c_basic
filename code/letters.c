#include <stdint.h>

char phrase1[] = "aaeaa eiee ioi oa u";
char phrase2[] = "a ee iii oooo uuuuu";
char phrase3[] = "aeiou";

#define SIZE 5

uint16_t occurrences1[SIZE];
uint16_t occurrences2[SIZE];
uint16_t occurrences3[SIZE];

int16_t find_vowel(char letter)
{
	switch (letter) {
		case 'a':
			return 0;
		case 'e':
			return 1;
		case 'i':
			return 2;
		case 'o':
			return 3;
		case 'u':
			return 4;
		default:
			return -1;
	}
}

void histogram_vowel(char phrase[], uint16_t max_letters, uint16_t occurrences[5])
{
	for (uint16_t i = 0; phrase[i] != '\0' && i < max_letters ; i++ ) {
		int16_t idx;
		if ( (idx = find_vowel(phrase[i]) ) != -1 )
			occurrences[idx]++;
	}
}

int main(void)
{
	histogram_vowel(phrase1, 18, occurrences1);
	histogram_vowel(phrase2, 15, occurrences2);
	histogram_vowel(phrase3, 5, occurrences3);
}
