package simulator;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Logger {

    public static List<String> messages = new ArrayList<>();
    public static PrintWriter write;

    public static void logMessage() {

        try {
            File simulationFile = new File("simulation.txt");
            write = new PrintWriter(simulationFile);
            for (String msg : messages) {
                write.println(msg);
            }
            write.close();

        } catch (IOException e) {
            System.out.println("Something went wrong 'simulation.txt' ");
            System.exit(1);
        }
    }

    public static void addMessage(String message) {
        messages.add(message);
    }
}