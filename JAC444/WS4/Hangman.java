
/**********************************************
Workshop 4
Course: JAC444 - Semester
Last Name: MAI
First Name:HUU DUC 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: June 23, 2020
**********************************************/
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;
import java.util.NoSuchElementException;

public class Hangman {
    static Scanner input = new Scanner(System.in);

    public static void Initialize() throws FileNotFoundException {
        String[] library = null;

        File hangman = new File("hangman.txt");
        if (!hangman.exists()) {
            System.out.println("No file detected");
        }
        Scanner input2 = new Scanner(hangman);
        while (input2.hasNext()) {
            String str = input2.nextLine();
            library = str.split(" ");
        }
        input2.close();

        String word;
        Random rand = new Random();
        word = library[rand.nextInt(library.length)];

        String guess = "";
        for (int i = 1; i < (word.length() + 1); i++) {
            guess += "*";
        }

        try {
            Play(guess, word);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void Play(String guess, String word) throws Exception {

        char Answers[] = guess.toCharArray();
        char Question[] = word.toCharArray();
        System.out.print("(Guess) Enter a letter in word: ");
        for (int i = 0; i < Answers.length; i++) {
            System.out.print(Answers[i]);
        }
        System.out.print(">");
        String TriedLetters = "";
        int tryTime = 0;
        Guess(guess, word, Answers, Question, TriedLetters, tryTime);
    }

    public static void Guess(String guess, String word, char Answers[], char Question[], String TriedLetters,
            int tryTime) throws Exception {
        String ans = new String(Answers);
        String qes = new String(Question);
        boolean flag = false;
        if (ans.equals(qes)) {
            System.out.println("The word is " + word + ". " + "You missed " + tryTime + " time");
            Found();
        } else {
            String letter = input.next();
            if (word.contains(letter)) {
                if (TriedLetters.contains(letter)) {
                    tryTime += 1;
                    System.out.println("\t\t" + letter + " is already in the word");
                } else {
                    for (int i = 0; i < word.length(); i++) {
                        char usrinput = letter.charAt(0);
                        char ques = Question[i];
                        if (ques == usrinput) {
                            Answers[i] = usrinput;
                        }
                    }
                }
            } else {
                tryTime += 1;
                if (TriedLetters.contains(letter)) {
                    System.out.println("You already tried this letter, try another one");
                } else {
                    System.out.println("\t\t" + letter + " is not in the word");
                    TriedLetters += letter;
                }
            }
            for (int i = 0; i < Answers.length; i++) {
                if (Answers[i] == '*')
                    flag = true;
            }
            if (flag) {
                System.out.print("(Guess) Enter a letter in word: ");
                for (int i = 0; i < Answers.length; i++) {
                    System.out.print(Answers[i]);
                }
                System.out.print(" > ");
            }
            TriedLetters += letter;
            Guess(guess, word, Answers, Question, TriedLetters, tryTime);
        }
    }

    public static void Found() throws NoSuchElementException {

        AddWord();

        System.out.print("Do you want to play Hangman again? (Y for yes, others for back to menu) > ");
        String opt = input.next();
        if (opt.contains("y") || opt.contains("Y")) {
            try {
                Initialize();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public static void AddWord() {
        System.out.print("Do you want to add another word to library? (Y for yes, others for no) > ");
        String opt = input.next();
        if (opt.contains("y") || opt.contains("Y")) {
            System.out.print("Enter a new word to be added in the memory > ");
            String newWord = input.next();
            try {
                File hangman = new File("hangman.txt");
                FileWriter fr = new FileWriter(hangman, true);
                fr.write(" " + newWord);
                fr.close();
                System.out.println("The word: " + newWord + " is successfully added to library");
            } catch (IOException e) {
                System.out.println("An error occurred");
            }
        }
    }

}