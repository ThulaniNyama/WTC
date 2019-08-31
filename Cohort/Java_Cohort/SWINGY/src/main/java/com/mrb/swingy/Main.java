package com.mrb.swingy;

import com.mrb.swingy.util.DataBase;
import com.mrb.swingy.view.start.StartViewConsole;
import com.mrb.swingy.view.start.StartViewGUI;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Scanner;

public class Main {

    private static JFrame frame;
    private static Scanner scanner;

    public static void main(String[] args) {
        if (args.length != 1 || (!args[0].equals("console") && !args[0].equals("gui"))) {
            System.out.println("Usage: program console | gui");
            System.exit(1);
        }

        DataBase.connect();

        if (args[0].equals("console"))
            new StartViewConsole().start();
        else if (args[0].equals("gui"))
            new StartViewGUI().start();
    }

    public static JFrame getFrame() {
        if (frame == null) {
            frame = new JFrame();
            frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
            frame.setSize(500, 400);
            frameListener();
        }
        return frame;
    }

    public static void showFrame() {
        if (frame != null)
            frame.setVisible(true);
    }

    public static void hideFrame() {
        if (frame != null)
            frame.setVisible(false);
    }

    public static Scanner getScanner() {
        if (scanner == null)
            scanner = new Scanner(System.in);
        return scanner;
    }

    public static void closeConnections() {
        DataBase.close();
        if (scanner != null)
            scanner.close();
    }


    private static void frameListener() {
        getFrame().addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                closeConnections();
                super.windowClosing(e);
            }
        });
    }
}
