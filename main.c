#include <stdio.h>
#include <stdlib.h>

void compile_java_file(const char *filepath, const char *output_file) {
    char command[512];
    FILE *fp;
    char output[1024];

    // Creiamo il comando per compilare il file Java con il percorso completo
    snprintf(command, sizeof(command), "javac %s 2>&1", filepath); // Redirigiamo stderr a stdout

    // Eseguiamo il comando e catturiamo l'output (sia stdout che stderr)
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error running javac command");
        return;
    }

    // Apriamo il file di output per scrivere gli errori
    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        fclose(fp);
        return;
    }

    // Scriviamo gli errori nel file
    fprintf(output_fp, "Compilazione del file %s:\n\n", filepath);
    int has_errors = 0;
    while (fgets(output, sizeof(output), fp)) {
        fprintf(output_fp, "%s", output);
        has_errors = 1;
    }

    if (!has_errors) {
        fprintf(output_fp, "No compilation errors.\n");
    }

    printf("Gli errori di compilazione sono stati scritti in %s\n", output_file);

    fclose(fp);
    fclose(output_fp);
}

int main() {
    char filepath[512];
    char output_file[512];

    // Chiediamo all'utente di inserire il percorso completo del file .java
    printf("Inserisci il percorso del file .java da compilare: ");
    scanf("%511s", filepath);  // Limitiamo la lunghezza dell'input per evitare overflow

    // Chiediamo il nome del file di output per gli errori
    printf("Inserisci il nome del file .txt dove salvare gli errori: ");
    scanf("%511s", output_file);

    compile_java_file(filepath, output_file);

    return 0;
}
