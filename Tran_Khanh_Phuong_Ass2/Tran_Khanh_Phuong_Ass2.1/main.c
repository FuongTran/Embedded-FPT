#include <stdio.h>

int isPalid(char str[], int length) {
	for (int i = 0; i < length / 2; i++) {
		if (str[i] != str[length - i - 1]) {
			return 0;
		}
	}
	return 1;
}

void revers_word(char str[], int lenght) {
	for (int i = 0; i < lenght; i++) {
		char temp = str[i];
		str[i] = str[lenght - i - 1];
		str[lenght - i - 1] = temp;
	}
}

int main() {

	char str[255];
	int length = 0;

	printf("Nhap chuoi (toi da 255 ky tu): ");
	while ((str[length] = getchar()) != '\n' && length < 255) {
		length++;
	}
	str[length] = '\0';

	if (isPalid(str, length)) {
		printf("chuoi doi xung\n");
	}
	else {
		revers_word(str, length);
		printf("chuoi khong phai doi xung, chuoi dao nguoc la %s\n", str);
	}

	return 0;

}