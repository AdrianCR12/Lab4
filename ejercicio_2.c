#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_palabra 100

void limpiarPalabra(char *destino, const char *origen) {
	int j = 0;
	for (int i = 0; origen[i] != '\0'; i++) {
		if (isalnum(origen[i])) {
			destino[j++] = tolower(origen[i]);
		}
	}
	destino[j] = '\0';
}

int esPalindromo(const char *palabra) {
	int len = strlen(palabra);
	for (int i = 0; i < len / 2; i++) {
		if (palabra[i] != palabra[len - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	FILE *archivo = fopen("input.txt", "r");
	if (archivo == NULL){
		perror("No se pudo abrir el archivo");
		return 1;
	}

	char palabraOriginal[max_palabra];
	char palabraLimpia[max_palabra];
	char palindromoMasLargo[max_palabra] = "";

	while (fscanf(archivo, "%99s", palabraOriginal) == 1) {
		limpiarPalabra(palabraLimpia, palabraOriginal);
		if (esPalindromo(palabraLimpia)) {
			if (strlen(palabraLimpia) > strlen(palindromoMasLargo)) {
				strcpy(palindromoMasLargo, palabraLimpia);
			}
		}
	}

	fclose(archivo);

	if (strlen(palindromoMasLargo) > 0) {
		printf("El palindromo más largo es: %s\n", palindromoMasLargo);
	} else{
		printf("No se encontraron palindromos.\n");
	}

	return 0;
}
