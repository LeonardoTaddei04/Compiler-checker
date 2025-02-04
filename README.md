# Compiler-checker
Java Compilation Error Checker

Questo programma C consente di compilare un file Java specificato dall'utente e di scrivere eventuali errori di compilazione in un file .txt. L'utente può fornire il percorso completo del file .java da compilare e il nome del file di output dove verranno registrati gli errori.
Requisiti

    Un compilatore C (ad esempio, gcc).
    Java Development Kit (JDK) installato, con il comando javac disponibile nel tuo PATH.

Come compilare e eseguire il programma

    Compilare il programma C:

    Assicurati di avere un compilatore C installato. Per compilare il programma, esegui il comando seguente:

gcc -o java_compiler_error_checker program.c

Questo genererà un eseguibile chiamato java_compiler_error_checker.

Eseguire il programma:

Una volta compilato, puoi eseguire il programma con il comando:

    ./java_compiler_error_checker

    Il programma ti chiederà di fornire due input:
        Percorso del file .java da compilare.
        Nome del file .txt in cui salvare gli errori di compilazione.

    Fornire i parametri:

    Esempio di input richiesto dal programma:
        Per il percorso del file .java: /home/user/progetti/Main.java
        Per il nome del file di output .txt: errori.txt

    Il programma compila il file Java e scrive gli errori (se ci sono) nel file errori.txt.

Funzionalità

    Input:
        Un percorso completo o relativo di un file .java.
        Un nome per il file di output .txt dove verranno scritti gli errori di compilazione.
    Output:
        Se ci sono errori di compilazione, verranno scritti nel file .txt specificato.
        Se non ci sono errori, verrà scritto il messaggio "No compilation errors." nel file di output.

Esempio di utilizzo

    Quando esegui il programma, ti verrà chiesto:

Inserisci il percorso del file .java da compilare: /home/user/progetti/Main.java
Inserisci il nome del file .txt dove salvare gli errori: errori.txt

Se ci sono errori di compilazione, vedrai un file errori.txt contenente il testo degli errori, ad esempio:

Compilazione del file /home/user/progetti/Main.java:

/home/user/progetti/Main.java:3: error: class Main is public, should be declared in a file named Main.java
    public class Main {
           ^
1 error

Se il programma non trova errori di compilazione, il file errori.txt conterrà:

    No compilation errors.

